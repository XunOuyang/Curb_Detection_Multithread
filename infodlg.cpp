//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include <stdio.h>
#include "simpleqt.h"
#include "infodlg.h"


InfoDlg::InfoDlg(SimpleQt *parent)
    : QDialog(parent),
    m_hApBase(NULL)
{
    ui.setupUi(this);
    m_pMainWnd = parent;

    connect(ui.pushButton_Get, SIGNAL(clicked()), this, SLOT(onGet()));
    connect(ui.pushButton_Set, SIGNAL(clicked()), this, SLOT(onSet()));
}

InfoDlg::~InfoDlg()
{

}

void InfoDlg::setCamera(AP_HANDLE hApBase)
{
    m_hApBase = hApBase;

    //  Fill in the combo-box with the register names
    ui.comboBox_Register->clear();
    int n = ap_NumRegisters(m_hApBase, NULL);
    for (int i = 0; i < n; ++i)
    {
        AP_HANDLE hReg = ap_Register(m_hApBase, NULL, i);
        ui.comboBox_Register->addItem(QString(ap_RegisterSymbol(hReg)));
        ap_DestroyRegister(hReg);
    }
    ui.comboBox_Register->setCurrentIndex(0);
    onGet();
}

void InfoDlg::onGet()
{
    ap_u32      nValue = 0;

    ap_GetSensorRegister(m_hApBase, ui.comboBox_Register->currentText().toLatin1(), NULL, &nValue, false);

    ui.lineEdit_Value->setText(QString("0x%1").arg(uint(nValue), 4, 16, QLatin1Char('0')));
}

void InfoDlg::onSet()
{
    ap_u32      nNewValue = 0;

    sscanf(ui.lineEdit_Value->text().toLatin1(), "%i", &nNewValue);

    ap_SetSensorRegister(m_hApBase, ui.comboBox_Register->currentText().toLatin1(),
                         NULL, nNewValue, NULL);
}
