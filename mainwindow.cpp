#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include "conges.h"
#include "connection.h"


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include<QDate>
#include <QPaintEvent>
#include <QPixmap>
#include<QComboBox>
#include<QFileDialog>
#include<QTextEdit>
#include <QSqlRecord>
#include<QSound>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Affichage_Emp->setModel(Etmp.afficher_Listeemploye());
    ui->tableView_2_C->setModel(temp.afficher_ListeConge());
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_supp->setValidator(new QIntValidator(0,99999999,this));
     setWindowTitle("Ma super app!");
     QPixmap Pix;

     son=new QSound(":/son/click.mp3");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_valider_clicked()
{
     QSound::play(":/son/click.mp3");
     QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl(":/son/click.mp3"));
        player->play();
//recuperation des informations saisies dans les champs

int cin=ui->lineEdit_cin->text().toInt();
QString nomprenom=ui->lineEdit_2_nom_et_prenom->text();
QString email=ui->lineEdit_email->text();
QString adresse=ui->lineEdit_3_adresse->text();
QString profession=ui->lineEdit_profession->text();
QString assurance=ui->lineEdit_assurance->text();
QDate date_entree=ui->dateEdit_entree->date();
QDate naissance=ui->dateEdit_naissance->date();
int nombre_enfants=ui->spinBox_enfants->text().toInt();
int cnss=ui->lineEdit_cnss->text().toInt();
QString nationnalite=ui->comboBox_2_nationnalite->currentText();
int salaire=ui->comboBox_salaire->currentText().toInt();


employes E(cin,nomprenom,email,adresse,profession,assurance,date_entree,naissance,nombre_enfants,cnss,nationnalite,salaire);
bool controle=E.controle_saisi_emp(E);

  if(controle)
  {
      QMessageBox::critical(nullptr,QObject::tr("attention"),
                                       QObject::tr("Champs non remplis.\n Taper CANCEL pour les remplir"),
                                       QMessageBox::Cancel);
  }
  if(E.getnomprenom()=="")
  {
      QMessageBox::critical(nullptr,QObject::tr("attention"),
                                       QObject::tr("le nom ne peut pas etre vide!\n Taper CANCEL pour changer "),
                                       QMessageBox::Cancel);
  }

  else
  {
bool test=E.ajouter_employe();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("Ajout effectué \n"
                                         "click cancel to exit."), QMessageBox::Cancel);
    ui->tableView_Affichage_Emp->setModel(Etmp.afficher_Listeemploye());

}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK" ),
                 QObject::tr("Ajout non effectué. \n"
                             "click cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pushButton_supp_emp_clicked()
{
    int cin =ui->lineEdit_supp->text().toInt();

  QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce employé?",
                                     QMessageBox::Yes|QMessageBox::No);
       if (reply == QMessageBox::Yes) {
           bool test=Etmp.supprimer_employe(cin);
           if(test)
           {

        ui->tableView_Affichage_Emp->setModel(Etmp.afficher_Listeemploye());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("suppressio effectuée \n"
                            "click cancel to exit."), QMessageBox::Cancel);
    }
       }

    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("suppression non effectuée.\n"
                                          "click cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_2_clicked()

{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click.mp3"));
    player->play();
    employes aux;
  aux.setcin(ui->lineEdit_cin->text().toInt());
      aux.setnomprenom(ui->lineEdit_2_nom_et_prenom->text());
   aux.setemail(ui->lineEdit_email->text());
  aux.setadresse(ui->lineEdit_3_adresse->text());
     aux.setprofession(ui->lineEdit_profession->text());
aux.setassurance(ui->lineEdit_assurance->text());
    aux.setdate_entree(ui->dateEdit_entree->date());
 aux.setnaissance(ui->dateEdit_naissance->date());
     aux.setnombre_enfants(ui->spinBox_enfants->text().toInt());
   aux.setcnss(ui->lineEdit_cnss->text().toInt());
 aux.setnationnalite( ui->comboBox_2_nationnalite->currentText());
aux.setsalaire(ui->comboBox_salaire->currentText().toInt());


           bool test=aux.modifier_employe(aux.getcin(),aux.getnomprenom(),aux.getemail(),aux.getadresse(),aux.getprofession(),aux.getassurance(),aux.getdate_entree(),aux.getnaissance(),aux.getnombreenfants(),aux.getcnss(),aux.getnationnlaite(),aux.getsalaire());
       if(test)
       {
           ui->tableView_Affichage_Emp->setModel(aux.afficher_Listeemploye());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("modification effectué \n"
                                                "click cancel to exit."), QMessageBox::Cancel);


       }

       else
       {
           QMessageBox::critical(nullptr,QObject::tr("Not OK" ),
                        QObject::tr("modification non effectué. \n"
                                    "click cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_pushButton_quitter_clicked()
{
   close();
   }






void MainWindow::on_pushButton_clicked()
{
    QString rech=ui->lineEdit_recherche->text();

        if(rech=="")
            ui->tableView->setModel(Etmp.afficher_Listeemploye());
        else
        ui->tableView->setModel(Etmp.rechercher_employes(rech));

}

void MainWindow::on_pushButton_sort_clicked()
{


        ui->tableView->setModel(aux.trier_employes());

}
