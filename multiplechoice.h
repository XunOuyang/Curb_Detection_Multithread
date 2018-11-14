//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#ifndef MULTIPLECHOICE_H
#define MULTIPLECHOICE_H

#include <QDialog>
#include <QRadioButton>
#include "ui_multiplechoice.h"

class MultipleChoice : public QDialog
{
    Q_OBJECT

public:
    MultipleChoice(QWidget *parent = 0);
    ~MultipleChoice();

    void        SetPrompt(const char *szPrompt);
    void        AddChoice(const char *szChoice);
    void        HideButtons();
    int         count();
    int         choice();

private slots:
    void        onSkip();
private:
    Ui::MultipleChoice ui;
    QList<QRadioButton *>   m_radioButtons;
    bool                    m_skip;
};

#endif // MULTIPLECHOICE_H
