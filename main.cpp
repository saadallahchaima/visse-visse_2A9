#include "mainwindow.h"
#include "connection.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include<QDate>
#include<QFile>
#include<QTranslator>
#include<QInputDialog>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
 a.setStyle("fusion");
    bool test=c.createconnect();
    //*****************


    QTranslator t;
         QTranslator guiTranslator;
        QStringList languages;
        languages <<"Frensh"<<"English";
        QString lang = QInputDialog::getItem(NULL,"select Language",
                                             "Language",languages);
        if(lang=="English")
        {
            t.load(":/english.qm");
            a.installTranslator(&t);
        }

    //*************

 MainWindow w;

//d.show();
    if(test)
    {//d.show();
        w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
