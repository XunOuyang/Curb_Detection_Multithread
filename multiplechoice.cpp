//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "multiplechoice.h"


MultipleChoice::MultipleChoice(QWidget *parent)
    : QDialog(parent),
    m_skip(false)
{
    ui.setupUi(this);

    connect(ui.pushButton_Ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui.pushButton_Cancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui.pushButton_Skip, SIGNAL(clicked()), this, SLOT(onSkip()));
}

MultipleChoice::~MultipleChoice()
{
    for (int i = 0; i < m_radioButtons.count(); ++i)
        delete m_radioButtons[i];
}

void MultipleChoice::SetPrompt(const char *szPrompt)
{
    ui.label_Prompt->setText(szPrompt);
}

void MultipleChoice::AddChoice(const char *szChoice)
{
    if (count() >= 15)
        return;
    QRadioButton *rb = new QRadioButton(szChoice, this);
    ui.verticalLayout_Choices->addWidget(rb);
    rb->show();
    if (m_radioButtons.count() == 0)
        rb->setChecked(true);
    m_radioButtons.append(rb);
}

void MultipleChoice::HideButtons()
{
    if (count() == 0)
    {
        ui.pushButton_Cancel->setVisible(false);
        ui.pushButton_Skip->setVisible(false);
    }
}

int MultipleChoice::count()
{
    return m_radioButtons.count();
}

void MultipleChoice::onSkip()
{
    m_skip = true;
    accept();
}

int MultipleChoice::choice()
{
    if (m_skip)
        return 0;
    for (int i = 0; i < m_radioButtons.count(); ++i)
    {
        if (m_radioButtons[i]->isChecked())
            return i + 1;
    }
    return 0;
}
