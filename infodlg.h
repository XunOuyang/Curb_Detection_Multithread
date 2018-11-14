//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#ifndef INFODLG_H
#define INFODLG_H

#include <QDialog>
#include "ui_infodlg.h"
#include "apbase.h"

class SimpleQt;

class InfoDlg : public QDialog
{
    Q_OBJECT

public:
    InfoDlg(SimpleQt* parent = 0);
    ~InfoDlg();

    void    setCamera(AP_HANDLE hApBase);

private slots:
    void    onGet();
    void    onSet();

private:
    Ui::InfoDlg ui;
    AP_HANDLE       m_hApBase;
    SimpleQt *      m_pMainWnd;
};

#endif // INFODLG_H
