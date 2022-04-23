#include "dialog.h"
#include "ui_dialog.h"
#include"login.h"
#include"employes.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QTabWidget>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_valide_login_clicked()
{

    employes E;
    login l ;
    QString cin;
    MainWindow w;
    Dialog d;
QString nom_et_prenom=ui->line_nom_emp_login->text();
QString login_p=ui->line_edit_mdp_emp->text();
w.setVisible(false);
w.hide();
 if((nom_et_prenom==("Admin")||("Employes"))&&(login_p==("Admin")||("Employes")))
        {if(((nom_et_prenom=="Admin")&&(login_p=="Admin"))||((nom_et_prenom=="Employe")&&(login_p=="Employe")))
     {

     QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("vous etes trouvé \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
     if(login_p=="Admin")

            d.hide();

    if(login_p=="Employe")
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("BienVenue! \n"
                                         "click cancel to exit."), QMessageBox::Cancel);

d.hide();
       w.setVisible(true);

    }
         }else
 {
     QMessageBox::critical(nullptr,QObject::tr("not"),
                                  QObject::tr("vous netes trouvé \n"
                                               "click cancel to exit."), QMessageBox::Cancel);
w.setVisible(false);
w.hide();

 }
 }
}
