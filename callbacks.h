//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "apbase.h"

//  This handles register change notifications
ap_s32 APBASE_DECL BeforeSetSensorReg_Callback(void *pContext,
    const char *szRegisterName,
    ap_u32      nValue,
    ap_s32      nSideEffects);

//  This handles register change notifications
void APBASE_DECL AfterSetSensorReg_Callback(void *pContext,
    const char *szRegisterName,
    ap_u32      nValue,
    ap_s32      nSideEffects);

//   This handles the PROMPT= ini command, a multiple-choice question
ap_s32 APBASE_DECL MultipleChoice_Callback(void *pContext,
    const char *szMessage,
    const char *szChoices);

//   This handles error messages
ap_s32 APBASE_DECL ErrorMessage_Callback(void *pContext,
    const char *szMessage,
    unsigned int mbType);
