//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "simpleqt.h"
#include "multiplechoice.h"
#include <QMessageBox>


//
//  ApBase calls back to the application for some things, mainly user
//  interaction with ini scripts and Python scripts, and state changes.
//

//
//  This handles device register changes that may affect the application
//
ap_s32 APBASE_DECL BeforeSetSensorReg_Callback(void *pContext,
    const char *szRegisterName,
    ap_u32      nValue,
    ap_s32      nSideEffects)
{
    SimpleQt *pSimpleQt = (SimpleQt *)pContext;

    if (nSideEffects & AP_FLAG_REALLOC)
        pSimpleQt->onStop(); // stop streaming if register write will change the image format

    return 1; // OK to set register (return 0 to cancel setting the register)
}

void APBASE_DECL AfterSetSensorReg_Callback(void *pContext,
    const char *szRegisterName,
    ap_u32      nValue,
    ap_s32      nSideEffects)
{
    SimpleQt *pSimpleQt = (SimpleQt *)pContext;

    if (nSideEffects & AP_FLAG_REALLOC)
        pSimpleQt->onPlay(); // resume streaming
}


//
//   This handles the PROMPT= ini command, a multiple-choice question
//
ap_s32 APBASE_DECL MultipleChoice_Callback(void *pContext,
    const char *szMessage,
    const char *szChoices)
{
    SimpleQt *pSimpleQt = (SimpleQt *)pContext;

    MultipleChoice dlg(pSimpleQt);
    dlg.SetPrompt(szMessage);
    const char *p = szChoices;
    while (p[0])
    {
        dlg.AddChoice(p);
        p += strlen(p) + 1;
    }
    dlg.HideButtons();
    if (dlg.exec() == QDialog::Accepted)
        return dlg.choice();
    return -1;
}

//
//   This handles error messages
//
ap_s32 APBASE_DECL ErrorMessage_Callback(void *pContext,
    const char *szMessage,
    unsigned int mbType)
{
    SimpleQt *pSimpleQt = (SimpleQt *)pContext;

    //  Translate ApBase enum to Qt enums
    QMessageBox::StandardButtons qMbType = QMessageBox::Ok;
    QMessageBox::Icon            qMbIcon = QMessageBox::Information;
    switch (mbType & 0xF)
    {
    case AP_MSGTYPE_OK:
        qMbIcon = QMessageBox::Information;
        qMbType = QMessageBox::Ok;
        break;
    case AP_MSGTYPE_OKCANCEL:
        qMbIcon = QMessageBox::Warning;
        qMbType = QMessageBox::Ok | QMessageBox::Cancel;
        break;
    case AP_MSGTYPE_ABORTRETRYIGNORE:
        qMbIcon = QMessageBox::Warning;
        qMbType = QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore;
        break;
    case AP_MSGTYPE_YESNOCANCEL:
        qMbIcon = QMessageBox::Question;
        qMbType = QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel;
        break;
    case AP_MSGTYPE_YESNO:
        qMbIcon = QMessageBox::Question;
        qMbType = QMessageBox::Yes | QMessageBox::No;
        break;
    case AP_MSGTYPE_RETRYCANCEL:
        qMbIcon = QMessageBox::Warning;
        qMbType = QMessageBox::Retry | QMessageBox::Cancel;
        break;
    case AP_MSGTYPE_CANCELTRYCONTINUE:
        qMbIcon = QMessageBox::Warning;
        qMbType = QMessageBox::Cancel | QMessageBox::Retry | QMessageBox::Ignore;
        break;
    }

    //  Show message
    QMessageBox mb(qMbIcon, "SimpleQt", szMessage, qMbType, pSimpleQt);
    int retVal = mb.exec();

    //  Translate Qt enum to ApBase enum
    switch (retVal)
    {
    default:
    case     QMessageBox::Ok      : retVal = AP_MSG_OK       ; break;
    case     QMessageBox::Cancel  : retVal = AP_MSG_CANCEL   ; break;
    case     QMessageBox::Abort   : retVal = AP_MSG_ABORT    ; break;
    case     QMessageBox::Retry   : retVal = AP_MSG_RETRY    ; break;
    case     QMessageBox::Ignore  : retVal = AP_MSG_IGNORE   ; break;
    case     QMessageBox::Yes     : retVal = AP_MSG_YES      ; break;
    case     QMessageBox::No      : retVal = AP_MSG_NO       ; break;
    case     QMessageBox::Close   : retVal = AP_MSG_CLOSE    ; break;
    case     QMessageBox::Help    : retVal = AP_MSG_HELP     ; break;
    }

    return retVal;
}
