/********************************************************************************
** Form generated from reading UI file 'infodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODLG_H
#define UI_INFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InfoDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_Register;
    QPushButton *pushButton_Get;
    QLineEdit *lineEdit_Value;
    QPushButton *pushButton_Set;

    void setupUi(QDialog *InfoDlg)
    {
        if (InfoDlg->objectName().isEmpty())
            InfoDlg->setObjectName(QStringLiteral("InfoDlg"));
        InfoDlg->setEnabled(false);
        InfoDlg->resize(558, 29);
        horizontalLayout = new QHBoxLayout(InfoDlg);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        comboBox_Register = new QComboBox(InfoDlg);
        comboBox_Register->setObjectName(QStringLiteral("comboBox_Register"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Register->sizePolicy().hasHeightForWidth());
        comboBox_Register->setSizePolicy(sizePolicy);
        comboBox_Register->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(comboBox_Register);

        pushButton_Get = new QPushButton(InfoDlg);
        pushButton_Get->setObjectName(QStringLiteral("pushButton_Get"));

        horizontalLayout->addWidget(pushButton_Get);

        lineEdit_Value = new QLineEdit(InfoDlg);
        lineEdit_Value->setObjectName(QStringLiteral("lineEdit_Value"));
        lineEdit_Value->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(lineEdit_Value);

        pushButton_Set = new QPushButton(InfoDlg);
        pushButton_Set->setObjectName(QStringLiteral("pushButton_Set"));

        horizontalLayout->addWidget(pushButton_Set);


        retranslateUi(InfoDlg);

        QMetaObject::connectSlotsByName(InfoDlg);
    } // setupUi

    void retranslateUi(QDialog *InfoDlg)
    {
        InfoDlg->setWindowTitle(QApplication::translate("InfoDlg", "InfoDlg", Q_NULLPTR));
        pushButton_Get->setText(QApplication::translate("InfoDlg", "Get", Q_NULLPTR));
        pushButton_Set->setText(QApplication::translate("InfoDlg", "Set", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoDlg: public Ui_InfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODLG_H
