/********************************************************************************
** Form generated from reading UI file 'multiplechoice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLECHOICE_H
#define UI_MULTIPLECHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MultipleChoice
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_Prompt;
    QVBoxLayout *verticalLayout_Choices;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Ok;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Cancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Skip;

    void setupUi(QDialog *MultipleChoice)
    {
        if (MultipleChoice->objectName().isEmpty())
            MultipleChoice->setObjectName(QStringLiteral("MultipleChoice"));
        MultipleChoice->resize(400, 150);
        verticalLayout = new QVBoxLayout(MultipleChoice);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Prompt = new QLabel(MultipleChoice);
        label_Prompt->setObjectName(QStringLiteral("label_Prompt"));

        verticalLayout->addWidget(label_Prompt);

        verticalLayout_Choices = new QVBoxLayout();
        verticalLayout_Choices->setSpacing(6);
        verticalLayout_Choices->setObjectName(QStringLiteral("verticalLayout_Choices"));

        verticalLayout->addLayout(verticalLayout_Choices);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Ok = new QPushButton(MultipleChoice);
        pushButton_Ok->setObjectName(QStringLiteral("pushButton_Ok"));

        horizontalLayout->addWidget(pushButton_Ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Cancel = new QPushButton(MultipleChoice);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Skip = new QPushButton(MultipleChoice);
        pushButton_Skip->setObjectName(QStringLiteral("pushButton_Skip"));

        horizontalLayout->addWidget(pushButton_Skip);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 90);
        verticalLayout->setStretch(3, 10);

        retranslateUi(MultipleChoice);

        pushButton_Skip->setDefault(true);


        QMetaObject::connectSlotsByName(MultipleChoice);
    } // setupUi

    void retranslateUi(QDialog *MultipleChoice)
    {
        MultipleChoice->setWindowTitle(QApplication::translate("MultipleChoice", "Configuration Selection", Q_NULLPTR));
        label_Prompt->setText(QApplication::translate("MultipleChoice", "Prompt", Q_NULLPTR));
        pushButton_Ok->setText(QApplication::translate("MultipleChoice", "OK", Q_NULLPTR));
        pushButton_Cancel->setText(QApplication::translate("MultipleChoice", "Cancel", Q_NULLPTR));
        pushButton_Skip->setText(QApplication::translate("MultipleChoice", "Skip This", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MultipleChoice: public Ui_MultipleChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICE_H
