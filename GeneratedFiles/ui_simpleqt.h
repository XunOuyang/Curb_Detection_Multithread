/********************************************************************************
** Form generated from reading UI file 'simpleqt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEQT_H
#define UI_SIMPLEQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleQtClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView_left;
    QGraphicsView *graphicsView_right;
    QGraphicsView *graphicsView_center;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimpleQtClass)
    {
        if (SimpleQtClass->objectName().isEmpty())
            SimpleQtClass->setObjectName(QStringLiteral("SimpleQtClass"));
        SimpleQtClass->resize(1349, 914);
        centralWidget = new QWidget(SimpleQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView_left = new QGraphicsView(centralWidget);
        graphicsView_left->setObjectName(QStringLiteral("graphicsView_left"));
        graphicsView_left->setGeometry(QRect(10, 0, 661, 421));
        graphicsView_right = new QGraphicsView(centralWidget);
        graphicsView_right->setObjectName(QStringLiteral("graphicsView_right"));
        graphicsView_right->setGeometry(QRect(680, 0, 661, 421));
        graphicsView_center = new QGraphicsView(centralWidget);
        graphicsView_center->setObjectName(QStringLiteral("graphicsView_center"));
        graphicsView_center->setGeometry(QRect(360, 430, 661, 421));
        SimpleQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimpleQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1349, 21));
        SimpleQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimpleQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SimpleQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SimpleQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SimpleQtClass->setStatusBar(statusBar);

        retranslateUi(SimpleQtClass);

        QMetaObject::connectSlotsByName(SimpleQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleQtClass)
    {
        SimpleQtClass->setWindowTitle(QApplication::translate("SimpleQtClass", "SimpleQt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimpleQtClass: public Ui_SimpleQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEQT_H
