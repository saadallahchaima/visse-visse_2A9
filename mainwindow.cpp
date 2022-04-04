#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include "demande_congee.h"
#include "congee.h"
#include"login.h"
#include "connection.h"
#include <QDebug>
#include <QSqlRecord>
#include<QTabWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QFile>   
#include <QMessageBox>
#include<QDate>
#include <QPaintEvent>
#include <QPixmap>
#include<QComboBox>
#include<QFileDialog>
#include<QTextEdit>
#include <QSqlRecord>
#include<QSound>
#include <QDebug>
#include<QModelIndex>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QSound>
#include<QSoundEffect>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(100,100,500,600);// place la fenêtre aux coordonnés : 100px,100px
                 // largeur fixée à 500px et hauteur à 600px
    ui->tableView_Affichage_Emp->setModel(Etmp.afficher_Listeemploye());
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_supp->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_cnss->setValidator(new QIntValidator(0,9999,this));
    ui->lineEdit_2_nom_et_prenom->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    son=new QSound(":/img/click2.wav");
    setWindowTitle("Ma super app!");
     QPixmap Pix;
     QPixmap pic_employe(":/img/téléchargement (2).png");

         QPropertyAnimation *animation2;
         int w2=ui->animation->width();
         int h2=ui->animation->height();

         ui->animation->setPixmap(pic_employe.scaled(h2,w2,Qt::KeepAspectRatio));
         animation2 = new QPropertyAnimation(ui->animation, "geometry");
                     animation2->setDuration(3000);
                     animation2->setStartValue(ui->animation->geometry());
                     animation2->setEndValue(QRect(1,197,579,13 ));
                     animation2->start();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_valider_clicked()
{

 son->play();
//recuperation des informations saisies dans les champs

QString cin=ui->lineEdit_cin->text();
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
QString num_tele=ui->lineEdit_num_tele->text();


employes E(cin,nomprenom,email,adresse,profession,assurance,date_entree,naissance,nombre_enfants,cnss,nationnalite,salaire,num_tele);
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
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/img/click.mp3"));
    player->play();
    QString cin=ui->lineEdit_supp->text();
    QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce employé ?",
                                       QMessageBox::Yes|QMessageBox::No);
         if (reply == QMessageBox::Yes) {

               bool test=Etmp.supprimer_employe(cin);
               if(test)
               {

            ui->tableView_Affichage_Emp->setModel(Etmp.afficher_Listeemploye());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("suppression effectuée \n"
                                "click cancel to exit."), QMessageBox::Cancel);
        }

}
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("suppression non effectuée.\n"
                                              "click cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_2_clicked()

{   QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/img/click.mp3"));
    player->play();
    employes aux;
  aux.setcin(ui->lineEdit_cin->text());
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
aux.setnum_tele(ui->lineEdit_num_tele->text());

           bool test=aux.modifier_employe(aux.getcin(),aux.getnomprenom(),aux.getemail(),aux.getadresse(),aux.getprofession(),aux.getassurance(),aux.getdate_entree(),aux.getnaissance(),aux.getnombreenfants(),aux.getcnss(),aux.getnationnlaite(),aux.getsalaire(),aux.getnum_tele());
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
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
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

void MainWindow::on_pushButton_valider_Demande_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
    //recuperation des informations saisies dans les champs
 QString nature_conges=ui->comboBox_type_c->currentText();

   aux.setnomprenom(ui->Le_nom_emp->text());

    QString num_tele_employes=ui->Le_tele->text();

    QDate date_depart_conge=ui->dateTimeEdit_C->date();
    QDate date_retour_conge=ui->dateTimeEdit_D_C->date();
    aux.setcin(ui->le_cin_emp->text());

    QString fonction_employe=ui->le_fonction->text();
QDate date_demande=ui->dateTimeEdit_date_demande->date();
QString reponse=ui->le_reponse->text();
QString cause=ui->lineEdit_cause->text();

    demande_congee D(nature_conges, aux.getnomprenom(), num_tele_employes,date_depart_conge,date_retour_conge, aux.getcin(),fonction_employe,date_demande,reponse,cause);

    bool test=D.ajouter_demande();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Ajout effectué \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
        ui->tableView_2_C_2->setModel(tamp.afficher_Listedemandes());

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK" ),
                     QObject::tr("Ajout non effectué. \n"
                                 "click cancel to exit."), QMessageBox::Cancel);
    }

void MainWindow::on_pushButton_supp_emp_supp_demande_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
    QString cin_employe =ui->lineEdit_supp_demande->text();

      QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette demande?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
               bool test=tamp.supprimer_demande(cin_employe);
               if(test)
               {

            ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
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

void MainWindow::on_pushButton_update_demande_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qqrc:/son/click.mp3"));
    player->play();
    tamp.setnature_conge(ui->comboBox_type_c->currentText());
    tamp.setnom_employe(ui->Le_nom_emp->text());
    tamp.setdate_demande(ui->dateTimeEdit_C->date());
    tamp.setfonction_employe(ui->le_fonction->text());
    tamp.setcode_cin_employes(ui->le_cin_emp->text());
    tamp.setnum_tele_employes(ui->Le_tele->text());
    tamp.setdate_depart_conge(ui->dateTimeEdit_C->date());
    tamp.setdate_retour_conge(ui->dateTimeEdit_D_C->date());
    tamp.setreponse(ui->le_reponse->text());
    tamp.setcause(ui->lineEdit_cause->text());
  bool test=tamp.modifier_demande(tamp.getnature_conge(), tamp.getnom_employe(), tamp.getnum_tele_employes(),tamp.getdate_depart_conge(),tamp.getdate_retour_conge(), tamp.getcin_employes(),tamp.getfonction_employe(),tamp.getdate_demande(),tamp.getreponse(),tamp.getcause());
          if(test)
          {

              QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("modification effectué \n"
                                                   "click cancel to exit."), QMessageBox::Cancel);
          ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
          ui->tableView_2_C_2->setModel(tamp.afficher_Listedemandes());


          }

          else
          {
              QMessageBox::critical(nullptr,QObject::tr("Not OK" ),
                           QObject::tr("modification non effectué. \n"
                                       "click cancel to exit."), QMessageBox::Cancel);
          }
}





void MainWindow::on_pushButton_valider_demande_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
    tamp.setreponse(ui->comboBox_D->currentText());
  tamp.setcode_cin_employes(ui->lineEdit_autoriser->text());
   bool test=tamp.modifier_autoriser(tamp.getcin_employes(),tamp.getreponse());
 if(tamp.getreponse()=="accepter")
 { QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("demande acceptée \n"
                                         "click cancel to exit."), QMessageBox::Cancel);

 }
 else

 {if(tamp.getreponse()=="refuser")
   {  QMessageBox::critical(nullptr,QObject::tr("ok"),
                                QObject::tr("demande refusée \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
     }
 }


           if(test)
           {

               QMessageBox::information(nullptr,QObject::tr("ok"),
                                       QObject::tr("demande réglée \n"
                                                    "click cancel to exit."), QMessageBox::Cancel);


               ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
               ui->tableView_2_C_2->setModel(tamp.afficher_Listedemandes());
               ui->tableView_2_C_4->setModel(tamp.afficher_conge_refuses());
               ui->tableView_2_C_3->setModel(tamp.afficher_conge_acceptes());
           }

           else
           {
               QMessageBox::critical(nullptr,QObject::tr("Not OK" ),
                            QObject::tr("demande non réglée. \n"
                                        "click cancel to exit."), QMessageBox::Cancel);
           }


}

void MainWindow::on_tableView_Affichage_Emp_activated(const QModelIndex &index)
{

QString val=ui->tableView_Affichage_Emp->model()->data(index).toString();
QSqlQuery query;
query.prepare("select * from employes where cin='"+val+"' or nomprenom='"+val+"' or email='"+val+"'  or profession='"+val+"' or assurance='"+val+"' or num_tele='"+val+"' ");
if(query.exec())
{
    while(query.next())
   {
        ui->lineEdit_cin->setText(query.value(0).toString());
        ui->lineEdit_2_nom_et_prenom->setText(query.value(1).toString());
        ui->lineEdit_email->setText(query.value(2).toString());
        ui->lineEdit_3_adresse->setText(query.value(3).toString());
        ui->lineEdit_profession->setText(query.value(4).toString());
        ui->lineEdit_assurance->setText(query.value(5).toString());
        ui->dateEdit_entree->setDate(query.value(6).toDate());
        ui->dateEdit_naissance->setDate(query.value(7).toDate());
        ui->spinBox_enfants->setValue(query.value(8).toInt());
        ui->lineEdit_cnss->setText(query.value(9).toString());
        ui->comboBox_2_nationnalite->setCurrentText(query.value(10).toString());
        ui->comboBox_salaire->setCurrentText(query.value(11).toString());
        ui->lineEdit_num_tele->setText(query.value(12).toString());
        ui->lineEdit_supp->setText(query.value(0).toString());
        ui->Le_nom_emp->setText(query.value(1).toString());
        ui->Le_tele->setText(query.value(12).toString());
        ui->le_cin_emp->setText(query.value(0).toString());
        ui->le_fonction->setText(query.value(4).toString());

    }
}

}

void MainWindow::on_tableView_2_C_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2_C->model()->data(index).toString();
    QSqlQuery query;
    ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
    query.prepare("select * from demande_congee where cin_employe='"+val+"' or nature_conges='"+val+"' or nom_employes='"+val+"' or num_tele_employes='"+val+"' or fonction_employe='"+val+"' or reponse='"+val+"' or cause='"+val+"' ");
    if(query.exec())
    {
        while(query.next())
       {    ui->comboBox_type_c->setCurrentText(query.value(0).toString());
            ui->Le_nom_emp->setText(query.value(1).toString());
            ui->Le_tele->setText(query.value(2).toString());
            ui->dateTimeEdit_C->setDate(query.value(3).toDate());
            ui->dateTimeEdit_D_C->setDate(query.value(4).toDate());
            ui->le_cin_emp->setText(query.value(5).toString());
            ui->le_fonction->setText(query.value(6).toString());
            ui->dateTimeEdit_date_demande->setDate(query.value(7).toDate());
            ui->le_reponse->setText(query.value(9).toString());
            ui->lineEdit_cause->setText(query.value(10).toString());
            ui->lineEdit_supp_demande->setText(query.value(5).toString());
        }

}
}

void MainWindow::on_tableView_2_C_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2_C->model()->data(index).toString();
    QSqlQuery query;
    ui->tableView_2_C->setModel(tamp.afficher_Listedemandes());
    query.prepare("select * from demande_congee where cin_employe='"+val+"' or nature_conges='"+val+"' or nom_employes='"+val+"' or num_tele_employes='"+val+"' or fonction_employe='"+val+"' or reponse='"+val+"' or cause='"+val+"'");
    if(query.exec())
    {
        while(query.next())
       {    ui->comboBox_type_c->setCurrentText(query.value(0).toString());
            ui->Le_nom_emp->setText(query.value(1).toString());
            ui->Le_tele->setText(query.value(2).toString());
            ui->dateTimeEdit_C->setDate(query.value(3).toDate());
            ui->dateTimeEdit_D_C->setDate(query.value(4).toDate());
            ui->le_cin_emp->setText(query.value(5).toString());
            ui->le_fonction->setText(query.value(6).toString());
            ui->dateTimeEdit_date_demande->setDate(query.value(7).toDate());
            ui->le_reponse->setText(query.value(9).toString());
            ui->lineEdit_cause->setText(query.value(10).toString());
            ui->lineEdit_autoriser->setText(query.value(5).toString());
        }

}
}




void MainWindow::on_pushButton_print_3_clicked()
{
    QString cin=ui->lineEdit_cin->text();
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
        QString num_tele=ui->lineEdit_num_tele->text();


        employes E(cin,nomprenom,email,adresse,profession,assurance,date_entree,naissance,nombre_enfants,cnss,nationnalite,salaire,num_tele);
      E.printPDF_employe();
}

void MainWindow::on_pushButton_printPDF_demande_clicked()
{

    //recuperation des informations saisies dans les champs
 QString nature_conges=ui->comboBox_type_c->currentText();

   aux.setnomprenom(ui->Le_nom_emp->text());

   QString num_tele_employes=ui->Le_tele->text();

    QDate date_depart_conge=ui->dateTimeEdit_C->date();
    QDate date_retour_conge=ui->dateTimeEdit_D_C->date();
    aux.setcin(ui->le_cin_emp->text());

    QString fonction_employe=ui->le_fonction->text();
QDate date_demande=ui->dateTimeEdit_date_demande->date();
QString reponse=ui->le_reponse->text();
QString cause=ui->lineEdit_cause->text();

    demande_congee D(nature_conges, aux.getnomprenom(), num_tele_employes,date_depart_conge,date_retour_conge, aux.getcin(),fonction_employe,date_demande,reponse,cause);
    D.printPDF_demande();
}

void MainWindow::on_pushButton_sort_demande_acceptes_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
      ui->tableView_2_C_3->setModel(tamp.trier_demande_acceptes_par_date());
}

void MainWindow::on_pushButton_sort_demande_refusees_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/son/click.mp3"));
    player->play();
      ui->tableView_2_C_2->setModel(tamp.trier_date_demande());
}
void MainWindow::statistiques()
{
    QPieSeries *series = new QPieSeries();
       QSqlQuery qry("SELECT * FROM employes where profession=:profession");
           QMap<QString,int >qq;
           QVector <QString> names;
           while(qry.next())

               {
                   if(qq[qry.value(0).toString()]==0)
                       names.push_back(qry.value(0).toString());
                   qq[qry.value(0).toString()]+=qry.value(3).toInt();

               }
               for(int i=0;i< names.size();i++)
                   series->append(names[i],qq[names[i]]);

           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("statistiques des professions dans l'entreprise");
series->append("ingenieurs", 80);
series->append("Ouvriers", 70);
series->append("Personnels", 50);
QPieSlice *slice = series->slices().at(1);
slice->setExploded(true);
slice->setLabelVisible(true);
slice->setPen(QPen(Qt::darkGreen, 2));
slice->setBrush(Qt::green);
 QChartView *chartview = new QChartView(chart);
  chartview->setParent(ui->horizontalFrame);


}
void MainWindow::on_pushButton_stat_clicked()
{
   son->play();
     statistiques();
     ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{

     son->play();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{

    son->play();
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
   son->play();
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_preced_D_clicked()
{

     son->play();
    ui->tabWidget->setCurrentIndex(5);

}

void MainWindow::on_pushButton_apres_D_clicked()
{
   son->play();
    ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->tabWidget->setCurrentIndex(4);
      son->play();
}

void MainWindow::on_pushButton_8_clicked()
{

     ui->tabWidget->setCurrentIndex(1);
      son->play();
}

void MainWindow::on_pushButton_10_clicked()
{

     ui->tabWidget->setCurrentIndex(2);
      son->play();
}


void MainWindow::on_pushButton_3_clicked()
{
    employes E;
    login l ;
    QString cin;
QString nom_et_prenom=ui->le_nom_log->text();
QString login_p=ui->le_cin_log->text();

 if((nom_et_prenom==("Admin")||("Employes"))&&(login_p==("Admin")||("Employes")))
        {if(((nom_et_prenom=="Admin")&&(login_p=="Admin"))||((nom_et_prenom=="Employe")&&(login_p=="Employe")))
     {
     QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("vous etes trouvé \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
     if(login_p=="Admin")
            ui->tabWidget->setCurrentIndex(1);
    if(login_p=="Employe")
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("BienVenue! \n"
                                             "click cancel to exit."), QMessageBox::Cancel);ui->tabWidget->setCurrentIndex(3);
ui->tabWidget->removeTab(4);
          ui->tabWidget->setCurrentIndex(3);
    }
         }else
 {
     QMessageBox::critical(nullptr,QObject::tr("not"),
                                  QObject::tr("vous netes trouvé \n"
                                               "click cancel to exit."), QMessageBox::Cancel);
                 ui->tabWidget->setCurrentIndex(0);
 }
 }
 son->play();
}

void MainWindow::on_pushButton_7_clicked()
{
    close();
     son->play();
}

void MainWindow::on_pushButton_11_clicked()
{     //set the app style sheet
        QFile styleSheetFile(":/img/Adaptic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        MainWindow::setStyleSheet(styleSheet);
         son->play();
}
void MainWindow::on_pushButton_12_clicked()
{
    //set the app style sheet
           QFile styleSheetFile(":/img/normal.qss");
           styleSheetFile.open(QFile::ReadOnly);
           QString styleSheet = QLatin1String(styleSheetFile.readAll());
           MainWindow::setStyleSheet(styleSheet);
            son->play();
}



void MainWindow::on_pushButton_13_clicked()
{

        //set the app style sheet
               QFile styleSheetFile(":/img/Obit.qss");
               styleSheetFile.open(QFile::ReadOnly);
               QString styleSheet = QLatin1String(styleSheetFile.readAll());
               MainWindow::setStyleSheet(styleSheet);
 son->play();


}

void MainWindow::on_pushButton_14_clicked()
{
                   QFile styleSheetFile(":/img/Diplaytap.qss");
                   styleSheetFile.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(styleSheetFile.readAll());
                   MainWindow::setStyleSheet(styleSheet);
                   son->play();
}

void MainWindow::on_pushButton_15_clicked()
{
     ui->tabWidget->setCurrentIndex(4);
      son->play();
}

void MainWindow::on_commandLinkButton_clicked()
{
    QFile styleSheetFile(":/img/Diplaytap.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    MainWindow::setStyleSheet(styleSheet);
    son->play();

}
