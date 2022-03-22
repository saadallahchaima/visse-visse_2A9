/********************************************************************************
** Form generated from reading UI file 'mainwindow_stat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_STAT_H
#define UI_MAINWINDOW_STAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_stat
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_stat)
    {
        if (MainWindow_stat->objectName().isEmpty())
            MainWindow_stat->setObjectName(QStringLiteral("MainWindow_stat"));
        MainWindow_stat->resize(800, 600);
        menubar = new QMenuBar(MainWindow_stat);
        menubar->setObjectName(QStringLiteral("menubar"));
        MainWindow_stat->setMenuBar(menubar);
        centralwidget = new QWidget(MainWindow_stat);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow_stat->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow_stat);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_stat->setStatusBar(statusbar);

        retranslateUi(MainWindow_stat);

        QMetaObject::connectSlotsByName(MainWindow_stat);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_stat)
    {
        MainWindow_stat->setWindowTitle(QApplication::translate("MainWindow_stat", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_stat: public Ui_MainWindow_stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_STAT_H
