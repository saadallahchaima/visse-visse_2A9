#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include<QMessageBox>
#include<QDate>
#include<QSound>
// Lucky Number 7//
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QSqlRecord>
#include<QMessageBox>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QTextStream>
#include<QFileInfo>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include<QTextCursor>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrintDialog>
#include <QtGui>
#include"QSortFilterProxyModel"
#include <QTextStream>
#include <QtMultimedia/QMediaPlayer>
#include <QAxWidget>
#include <QAxObject>
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



 // Fournisseur

    ui->tableView_fournis->setModel(fo.afficher());
    ui->comboBox->setModel(fo.afficheroncombo());
    ui->tableView_facture->setModel(Fa.afficherFA());
    ui->comboBoxP_3->setModel(Pa.afficheroncomboP());
    ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());
    ui->comboBoxPP_Verif->setModel(Pa.afficheroncomboPT());
    ui->tableView_Pai->setModel(Pa.afficherP());
    ui->comboBoxPrecherche->setModel(Pa.afficheroncomboPT());
    ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());
    ui->comboBox_Generer->setModel(Fa.afficheroncombo_Mail_FA());

    ui->lineEdit_numF->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_nomF->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    ui->lineEdit_prenF->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    ui->lineEdit_telF->setValidator(new QIntValidator(0,99999999,this));

//Timer
    timer = new QTimer(this) ;
       connect(timer,SIGNAL(timeout()), this ,SLOT(myfunction())) ;
       timer->start(1000) ;


    // Paiement



    ui->tabWidget->setTabText(0,"Fournisseur");
    ui->tabWidget->setTabText(1,"Paiement");
    ui->tabWidget->setTabText(2,"Facture");
    ui->tabWidget_3->setTabText(0,"Acces Denied !");
    ui->tabWidget->setTabText(3,"Bloc notes");
    ui->label_10->setText("Identifiant Paiement");
    ui->label_12->setText("Identifiant Paiement");
    ui->label_7->setText("Identifiant Fournisseur");
    ui->label_8->setText("Numero Facture");
    ui->label_9->setText("Total");
    ui->pushButton_ajF_2->setText("Ajouter");
    ui->pushButton_Verif->setText("Verifier");
    ui->pushButton_numF_2->setText("Supprimer");
    ui->pushButton_recherche_ID->setText("rechercher");
    ui->commandLinkButtonClear_Pa->setText("Effacer Tout");
    ui->Traduction_Fo->setText("ENG");
    ui->Historique->setText("Historique");
    ui->Calculator_PA->setText("Calculatrice");


        ui->lineEditfa->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_PFA_2->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_numP_3->setValidator(new QIntValidator(0,99999999,this));


        ui->label_Num->setText("Identifiant");
        ui->label_FirstName->setText("Nom");
        ui->label_LasName->setText("Prenom");
        ui->label_Adresse->setText("Adresse");
        ui->label_Tel->setText("Telephone");
        ui->label_Type->setText("Type");
        ui->label_Tel_rech->setText("Telephone");
        ui->pushButton_ajF->setText("Ajouter");
        ui->pushButton_mdF->setText("Modifier");
        ui->pushButton_numF->setText("Supprimer");
        ui->pushButton_recherche->setText("rechercher");
        ui->commandLinkButton_Clear->setText("Effacer Tout");
         ui->Traduction_Fo->setText("ENG");



        // Facteur

            ui->lineEdit_numFA->setValidator(new QIntValidator(0,99999999,this));
            ui->lineEdit_Montant->setValidator(new QIntValidator(0,99999999,this));
            ui->lineEdit_telFone->setValidator(new QIntValidator(0,99999999,this));
            ui->textBrowserA->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));




            ui->label_20->setText("Numero Facture");
            ui->label_21->setText("Date");
            ui->label_23->setText("TVA");
            ui->label_28->setText("Transport");
            ui->label_25->setText("Montant");
            ui->label_29->setText("Description");
            ui->label_30->setText("Email");
            ui->label_27->setText("Telephone");
            ui->label_22->setText("Type");
            ui->commandLinkButton_Ge->setText("Generer");
            ui->pushButton_ajFA->setText("Ajouter");
            ui->pushButton_mdFA->setText("Modifier");
            ui->pushButton_Supp->setText("Supprimer");
            ui->pushButton_rech_FA->setText("Rechercher");
            ui->commandLinkButtonClear_Fa->setText("Effacer Tout");
            ui->lineEdit_Generer_Fa->setVisible(false);
            ui->Traduction_FA->setText("ENG");
            on_label_pic_linkActivated(-1);
            on_label_Animation(-1);
            on_label_Animation(-2);
            on_label_Animation(-4);
            on_label_Animation(-3);



//Favourite Theme
            QFile styleSheetFile(":/Pictures/MacOS.qss");
             styleSheetFile.open(QFile::ReadOnly);
             QString styleSheet = QLatin1String(styleSheetFile.readAll());
             MainWindow::setStyleSheet(styleSheet);
             ui->commandLinkButton_T1->setText("Theme 1");




}











MainWindow::~MainWindow()
{
    delete ui;
}

// FOURNISSEUR


// Clear Button Fo

void MainWindow::on_commandLinkButton_Clear_clicked()
{Click();


    ui->lineEdit_numF->clear();
    ui->lineEdit_nomF->clear();
    ui->lineEdit_prenF->clear();
    ui->lineEdit_telF->clear();
on_label_pic_linkActivated(12);



}





//Notification Fo

void MainWindow::on_label_pic_linkActivated(int choice)
{
if (choice == 0)
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Payments.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 1 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Tri.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}

else if (choice == 2 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Remove.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 3 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Search.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 4 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Addition.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 5 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Stat.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 6 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Error.jpg"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 7 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Update.jpg"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 8 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/PDF.jpg"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}

else if (choice == 9 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Fr.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 10 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/english.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 11 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Russe.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);

}
else if (choice == 12 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Clear.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}
else if (choice == 13 )
{
    QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/not.png"); // <- path to image file
                   ui->label_pic_2->setPixmap(pm);
                   ui->label_pic_2->setScaledContents(true);
                   on_label_Animation(7);
}

}





void MainWindow::myfunction()
{


   QTime time = QTime::currentTime();
   QString time_text = time.toString("hh : mm : ss");
   if ((time.second() % 2)==  0)
   {
       time_text[3] = ' ';
       time_text[8] = ' ' ;
   }
   ui->Time->setText(time_text);
// go to line 65
}


void MainWindow::Click()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Documents/ProjectFacture/Pictures/Click.wav"));
    player->setVolume(20);
    player->play();

}
//Stop_Time
void MainWindow::Shattered_Time(int T)
{


   while (T!=0)
   {
       QTime dieTime= QTime::currentTime().addSecs(1);
           while (QTime::currentTime() < dieTime)
               QCoreApplication::processEvents(QEventLoop::AllEvents,100);
   T=T-1;
   }

}

//Animation
void MainWindow::on_label_Animation(int choice)
{

 if (choice == 7 )
 {
     Shattered_Time(3.5);
ui->label_pic_2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Gif.gif");
ui->label_pic_2->setMovie (movie);
movie->start ();

 }

 else if (choice == -1 )
 {

ui->label_pic_2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Gif.gif");
ui->label_pic_2->setMovie (movie);
movie->start ();

 }

 else if (choice == -2 )
 {

ui->label_pic_PA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Connor.gif");
ui->label_pic_PA->setMovie (movie);
movie->start ();

 }
 else if (choice == 2 )
 {
Shattered_Time(3.5);
ui->label_pic_PA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Connor.gif");
ui->label_pic_PA->setMovie (movie);
movie->start ();

 }
 else if (choice == -3 )
 {

ui->label_pic_File->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Note.gif");
ui->label_pic_File->setMovie (movie);
movie->start ();

 }
 else if (choice == 3 )
 {
Shattered_Time(3.5);
ui->label_pic_File->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Note.gif");
ui->label_pic_File->setMovie (movie);
movie->start ();

 }
 else if (choice == -4 )
 {

ui->label_pic_FA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Facture.gif");
ui->label_pic_FA->setMovie (movie);
movie->start ();

 }
 else if (choice == 4 )
 {
Shattered_Time(3.5);
ui->label_pic_FA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Facture.gif");
ui->label_pic_FA->setMovie (movie);
movie->start ();

 }
 else if (choice == 77 )
 {

ui->label_pic_FA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Error.gif");
ui->label_pic_FA->setMovie (movie);
movie->start ();
Shattered_Time(2);
 }
 else if (choice == 777 )
 {

ui->label_pic_FA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Welcome to the Game - Hacking Alert.gif");
ui->label_pic_Hack->setMovie (movie);
movie->start ();

 }
 else if (choice == 775 )
 {
Shattered_Time(6);
ui->label_pic_FA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Error.gif");
ui->label_pic_Hack_9->setMovie (movie);
ui->label_pic_Hack_10->setMovie (movie);
ui->label_pic_Hack_11->setMovie (movie);
ui->label_pic_Hack_8->setMovie (movie);
movie->start ();
Shattered_Time(8);
 }
 else if (choice == 7777 )
 {

ui->label_pic_PA->setFrameStyle(QFrame::Panel | QFrame::Sunken);
QMovie *movie = new QMovie("C:/Users/21627/Documents/ProjectFacture/Pictures/Verif.gif");
ui->label_pic_PA->setMovie (movie);
movie->start ();
Shattered_Time(5);

 }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    index=3;

}

// Fournisseur AFF


void MainWindow::on_tableView_fournis_clicked(const QModelIndex &index)
{Click();
    QString val=ui->tableView_fournis->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from FOURNISSEUR  where  numF= '"+val+"'");
    if(query.exec())
    {
        while(query.next())
       {
            ui->lineEdit_numF->setText(query.value(0).toString());
            ui->lineEdit_nomF->setText(query.value(1).toString());
            ui->lineEdit_prenF->setText(query.value(2).toString());
            ui->lineEdit_telF->setText(query.value(3).toString());
            ui->lineEdit_addF->setText(query.value(4).toString());
            ui->comboBox_typeF->setCurrentText(query.value(5).toString());

        }
    }
}
//Facture AFF


void MainWindow::on_tableView_facture_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_facture->model()->data(index).toString();
   QSqlQuery query;
   query.prepare("select * from FACTURE  where  NUMFA= '"+val+"'");
   if(query.exec())
   {
       while(query.next())
      {

           ui->lineEdit_Email->setText(query.value(5).toString());
           ui->lineEdit_numFA->setText(query.value(0).toString());
           ui->lineEdit_Montant->setText(query.value(6).toString());
           ui->lineEdit_telFone->setText(query.value(7).toString());
           ui->textBrowserA->setText(query.value(4).toString());
           ui->comboBox_TVA->setEditText(query.value(3).toString());
            QString b=query.value(2).toString();
if (b=="Pasif")
{
ui->radioButton_pasif->setChecked(1);
}
else
{
ui->radioButton_actif->setChecked(1);
}
QString c=query.value(9).toString();
if(c=="TRUCK")
{
ui->radioButtonTruck->setChecked(1);
}
else if (c=="VAN")
{
ui->radioButton_Van->setChecked(1);
}
else
{
    ui->radioButtonPlane->setChecked(1);
}

                    QString a=query.value(8).toString();
                    qDebug() << a ;



       }
   }
}


void MainWindow::on_pushButton_ajF_clicked()
{Click();

   int NumF=ui->lineEdit_numF->text().toInt();
QString nom=ui->lineEdit_nomF->text();
QString Prenf=ui->lineEdit_prenF->text();
QString Adress=ui->lineEdit_addF->text();
int Tel=ui->lineEdit_telF->text().toInt();
QString TYPE=ui->comboBox_typeF->currentText();

QString NUMFT=QString ::number(NumF);
QString TelFT=QString ::number(Tel);
nom[0]=nom[0].toUpper();
Prenf[0]=Prenf[0].toUpper();



 if((NumF==0)||(nom=="")||(Prenf=="")||(Adress=="")||(Tel==0)||(TYPE==""))
 {
     QMessageBox::critical(nullptr,QObject::tr("Verifier Champs Vide !"),
                             QObject::tr("click cancel to exist"),
                             QMessageBox::Cancel);
 }


  else if((NUMFT.length()) != 4 )
 {
      QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                              QObject::tr("Le numero de fournisseur est compose de 4 characteres"),
                              QMessageBox::Cancel);
  }
 else if((TelFT.length()) < 8 )
{
     QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                             QObject::tr("Le numero de telephone est invalid "),
                             QMessageBox::Cancel);
 }


else
 {

Fournisseur f(NumF,nom,Prenf,Adress,Tel,TYPE);
bool test= f.ajouter();




       if (test)
       {
           ui->tableView_fournis->setModel(fo.afficher());//actualisation taa afficher
  ui->comboBox->setModel(fo.afficheroncombo());
  ui->comboBoxP_3->setModel(Pa.afficheroncomboP());

  on_label_pic_linkActivated(4);
  QString His = "Ajout fournisseur de Numero : ";
                  on_Historique_Pa__clicked(His,NumF);


                        }

                        else
                    on_label_pic_linkActivated(6);




                 ui->tableView_fournis->setModel(fo.afficher());
         }
         }


         void MainWindow::on_pushButton_numF_clicked()
         {Click();
             bool test=fo.supprimer(ui->comboBox->currentText().toInt());
             if(test)
             {ui->tableView_fournis->setModel(fo.afficher());
                  ui->comboBox->setModel(fo.afficheroncombo());//actualisation taa afficher
                  on_label_pic_linkActivated(2);
                  QString His = "Suprresion du  fournisseur de Numero : ";
                                  on_Historique_Pa__clicked(His,ui->comboBox->currentText().toInt());

                 }

                 else
                 on_label_pic_linkActivated(6);

         }

         void MainWindow::on_comboBox_currentIndexChanged(int index)
         {
             int a;
                 a=index;
             ui->comboBox->currentText();
         }

         void MainWindow::on_pushButton_mdF_clicked()
         {Click();

             int NumF=ui->lineEdit_numF->text().toInt();
          QString nom=ui->lineEdit_nomF->text();
          QString Prenf=ui->lineEdit_prenF->text();
          QString Adress=ui->lineEdit_addF->text();
          int Tel=ui->lineEdit_telF->text().toInt();
          QString TYPE=ui->comboBox_typeF->currentText();

          QString NUMFT=QString ::number(NumF);
          QString TelFT=QString ::number(Tel);
          nom[0]=nom[0].toUpper();
          Prenf[0]=Prenf[0].toUpper();



           if((NumF==0)||(nom=="")||(Prenf=="")||(Adress=="")||(Tel==0)||(TYPE==""))
           {
               QMessageBox::critical(nullptr,QObject::tr("Verifier Champs Vide !"),
                                       QObject::tr("click cancel to exist"),
                                       QMessageBox::Cancel);
           }


            else if((NUMFT.length()) < 4 )
           {
                QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                                        QObject::tr("Le numero de fournisseur est compose de 4 characteres"),
                                        QMessageBox::Cancel);
            }
           else if((TelFT.length()) < 8 )
          {
               QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                                       QObject::tr("Le numero de telephone est invalid "),
                                       QMessageBox::Cancel);
           }


          else
           {

          bool test= fo.modifier(NumF,nom,Prenf,Adress,Tel,TYPE);




                 if (test)
                 {ui->tableView_fournis->setModel(fo.afficher()); //actualisation taa afficher
            ui->comboBox->setModel(fo.afficheroncombo());
            on_label_pic_linkActivated(7);
            QString His = "Modification  du  fournisseur de Numero : ";
                            on_Historique_Pa__clicked(His,NumF);

                         }

                         else
                     on_label_pic_linkActivated(6);



                  ui->tableView_fournis->setModel(fo.afficher());
          }
         }

         void MainWindow::on_pushButton_recherche_clicked()
         {Click();
          int i=13;
           QString Nom;
           Nom=ui->lineEdit_recherche->text();
          ui->tableView_fournis->setModel(fo.recherche(Nom));
          int row =ui->tableView_fournis->model()->rowCount();

         if (row !=0)
         {
            i=3;
            QString His = "Recherche  du  fournisseur par Nom  ";
                            on_Historique_Pa__clicked(His,0);
         }
          on_label_pic_linkActivated(i);

         }



         void MainWindow::on_commandLinkButton_TRI_F_clicked()
         {Click();
             ui->tableView_fournis->setModel(fo.tri_Fo());
             on_label_pic_linkActivated(1);
             QString His = "Tri   fournisseur   ";
                             on_Historique_Pa__clicked(His,0);


         }



//PDF Fo
         void MainWindow::on_commandLinkButton_PDF_clicked()
         {Click();
         fo.Generer_PDF();
         QPainter painter ;
         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
             if (reponse == QMessageBox::Yes)
             {
                 QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21627/Documents/ProjectFacture/PDF/Tables_Fournisseurs.pdf"));
                 painter.end();
                 on_label_pic_linkActivated(8);
                 QString His = "PDF   Fournisseur   ";
                                 on_Historique_Pa__clicked(His,0);

             }
             if (reponse == QMessageBox::No)
             {
                  painter.end();
                  on_label_pic_linkActivated(6);

             }
         }



         // Traduction Fo
         void MainWindow::on_Traduction_Fo_clicked()
         {Click();

            QString Lang=ui->Traduction_Fo->text() ;



            if (Lang == "ENG")
            {
                ui->tabWidget->setTabText(0,"Provider");
                ui->tabWidget->setTabText(1,"Payments");
                ui->tabWidget->setTabText(2,"bills");
                ui->tabWidget->setTabText(3,"NotePad");
                ui->label_Num->setText("ID");
                ui->label_FirstName->setText("First Name");
                ui->label_LasName->setText("Last Name");
                ui->label_Adresse->setText("Adress");
                ui->label_Tel->setText("Phone Number");
                ui->label_Type->setText("Type");
                ui->label_Tel_rech->setText("Phone Number");
                ui->pushButton_ajF->setText("ADD");
                ui->pushButton_mdF->setText("Update");
                ui->pushButton_numF->setText("Delete");
                ui->pushButton_recherche->setText("Search");
                ui->commandLinkButton_Clear->setText("Clear");
                ui->Traduction_Fo->setText("RUS");
                on_label_pic_linkActivated(10);
                QString His = "Modification de la langue vers l' Anglais";
                                        on_Historique_Pa__clicked(His,0);






            }

            if (Lang == "FR")
            {
                ui->tabWidget->setTabText(0,"Fournisseur");
                ui->tabWidget->setTabText(1,"Paiement");
                ui->tabWidget->setTabText(2,"Facture");
                ui->tabWidget->setTabText(3,"Bloc notes");
                ui->label_Num->setText("Identifiant");
                ui->label_FirstName->setText("Nom");
                ui->label_LasName->setText("Prenom");
                ui->label_Adresse->setText("Adresse");
                ui->label_Tel->setText("Telephone");
                ui->label_Type->setText("Type");
                ui->label_Tel_rech->setText("Telephone");
                ui->pushButton_ajF->setText("Ajouter");
                ui->pushButton_mdF->setText("Modifier");
                ui->pushButton_numF->setText("Supprimer");
                ui->pushButton_recherche->setText("rechercher");
                ui->commandLinkButton_Clear->setText("Effacer Tout");
                ui->Traduction_Fo->setText("ENG");
                on_label_pic_linkActivated(9);
                QString His = "Modification de la langue vers le Francais";
                                        on_Historique_Pa__clicked(His,0);

            }
            if (Lang == "RUS")
            {
                ui->tabWidget->setTabText(0,"Провайдер");
                ui->tabWidget->setTabText(1,"Платежи");
                ui->tabWidget->setTabText(2,"Выставленный счет");
                ui->tabWidget->setTabText(3,"Блокнот");
                ui->label_Num->setText("я бы");
                ui->label_FirstName->setText("имя");
                ui->label_LasName->setText("имя");
                ui->label_Adresse->setText("Адрес");
                ui->label_Tel->setText("Телефонный номер");
                ui->label_Type->setText("Тип");
                ui->label_Tel_rech->setText("Телефонный номер");
                ui->pushButton_ajF->setText("Добавлять");
                ui->pushButton_mdF->setText("Обновить");
                ui->pushButton_numF->setText("Удалять");
                ui->pushButton_recherche->setText("исследовать");
                ui->commandLinkButton_Clear->setText("Сбросить все");
                ui->Traduction_Fo->setText("FR");
                on_label_pic_linkActivated(11);
                QString His = "Modification de la langue vers le Russee";
                                        on_Historique_Pa__clicked(His,0);
            }

         }


         void MainWindow::on_pushButton_Exit_3_clicked()
         {Click();
             int reponse = QMessageBox::question(this, "Quitter", "Vous Voulez Vraiment Quitter ?", QMessageBox::Yes |  QMessageBox::No);
                 if (reponse == QMessageBox::Yes)
                 {
                     QString His = "Exit";
                                             on_Historique_Pa__clicked(His,0);
                 }
                 if (reponse == QMessageBox::No)
                 {

                 }
         }



         // PAIEMENT


         // Clear Button Pa

         void MainWindow::on_commandLinkButtonClear_Pa_clicked()
         {Click();
             ui->lineEditfa->clear();
             ui->lineEdit_PFA_2->clear();
             ui->lineEdit_numP_3->clear();
             on_label_pic_PA_linkActivated(12);

         }




         //Notification Pa



         void MainWindow::on_label_pic_PA_linkActivated(int choice)
         {
         if (choice == 0)
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Payments.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 1 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Tri.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }

         else if (choice == 2 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Remove.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 3 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Search.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 4 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Addition.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 5 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Stat.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 6 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Error.jpg"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 7 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Update.jpg"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 8 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/PDF.jpg"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 9 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Fr.png"); // <- path to image file
                           ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 10 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/english.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 11 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Russe.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }

         else if (choice == 12 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Clear.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 13 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/not.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }

         else if (choice == 15 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/GF.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(4);
         }
         else if (choice == 155 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/27324.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         else if (choice == 16 )
         {
             QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Bt.png"); // <- path to image file
                            ui->label_pic_PA->setPixmap(pm);
                            ui->label_pic_PA->setScaledContents(true);
                            on_label_Animation(2);
         }
         }


         int MainWindow::Remise_PA(int numF)
         {
             qDebug() << numF ;
             int row=0,i;

         int Remise=0,Somme=0;


     QString sql=QString("select * from PAIEMENT where  NUMF=numF AND  PAYMENT_VALIDATION='Verified'");
QSqlQuery query(sql);
query.bindValue(":numF",numF);


     while(query.next())
     {
     row++;
     }
     for(i=0 ;i<row;i++)
     {
     query.seek(i);
     Somme+=query.value("TOTAL").toInt();

     }


         on_label_Animation(7777);


         if (Somme >15000 && Somme < 30000)
         {

Remise= row*5 ;


         }
         else if (Somme > 30000)
         {
Remise= row*7 ;


         }





         if (Remise > 50 )
         {
             on_label_pic_PA_linkActivated(155);
             return 50 ;
         }
         else if (Remise == 0 )
         {
         on_label_pic_PA_linkActivated(16);
         return 0 ;
         }
         else

         {
             on_label_pic_PA_linkActivated(155);
             return Remise ;
         }

             QString His = "Remise Pour  Le Paiement :  " ;
                           on_Historique_Pa__clicked(His,numF);



         }

         void MainWindow::on_pushButton_ajF_2_clicked()
         {Click();
             int NUMF=ui->comboBoxP_3->currentText().toInt();
             int NUMFA=ui->lineEditfa->text().toInt();
             QString Total=ui->lineEdit_PFA_2->text();
             int ID =ui->lineEdit_numP_3->text().toInt();
             QString PAYMENT_VALIDATION ="Not Yet";



             QDate date = QDate ::currentDate();
             QString  Datee= date.toString();

             if((NUMF==0)||(ID==0)||(Total==0)||(NUMFA==0))
             {
               on_label_pic_PA_linkActivated(6);


             }



             else
             {


                 int Remise =Remise_PA(NUMF);
                 int TT= Total.toDouble();
                 TT=((TT*(100-Remise))/100);
QString Tot=QString::number(TT);

             Paiement  Pay(NUMF,NUMFA,Tot,Datee,ID,PAYMENT_VALIDATION);
                bool test= Pay.ajouterP();

              if (test)
                {ui->tableView_Pai->setModel(Pa.afficherP());//actualisation  afficher
           ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());
           ui->comboBoxPP_Verif->setModel(Pa.afficheroncomboPT());
           QString His = "Ajout du paiement Numero : ";
           on_Historique_Pa__clicked(His,ID);



                            on_label_pic_PA_linkActivated(4);
                        }

                        else
                            on_label_pic_PA_linkActivated(6);



                 ui->tableView_Pai->setModel(Pa.afficherP());

         }
         }

         void MainWindow::on_comboBoxP_3_currentIndexChanged(int index)
         {

             int a;
                 a=index;
             ui->comboBoxP_3->currentText();
         }
 void MainWindow::on_Historique_Pa__clicked(QString His , int ID)
         {
             QString time_format = "yyyy-MM-dd  HH:mm:ss";
             QDateTime a = QDateTime::currentDateTime();
             QString Date = a.toString(time_format);

             QFile file("C:/Users/21627/Documents/ProjectFacture/PDF/History.txt");
                   if(file.open(QIODevice::WriteOnly | QIODevice::Text| QIODevice::Append))
                   {
                       // We're going to streaming text to the file
                       QTextStream stream(&file);
                       if (ID!=0)
                       {

                       stream << Date << "   -" << His << ID<< '\n';
                       }
                       else
                       {
                          stream << Date << "   -" << His << '\n';
                       }

                       }

                       file.close();

                   }





 void MainWindow::on_Historique_clicked()
 {Click();
   int y=1;

     Shattered_Time(3);
ui->tabWidget->setVisible(false);
ui->tabWidget_3->setVisible(false);

QString fileName = "C:/Users/21627/Documents/ProjectFacture/PDF/History.txt";
QFile file(fileName);
currentFile = fileName;
if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Probléme", "fichier non ouvrir " + file.errorString());
    return;
}

setWindowTitle(fileName);
QTextStream in(&file);
QString text = in.readAll();
ui->textEdit_Historique->setText(text);
file.close();

while (y!=0)
{
    Shattered_Time(3777);
on_Historique_clicked();


}
 }

 void MainWindow::on_Return_clicked()
 {Click();
ui->tabWidget->setVisible(true);
ui->tabWidget_3->setVisible(true);
 }

         void MainWindow::on_pushButton_Verif_clicked()
         {Click();
             int  ID_pay_validation;
             ID_pay_validation = ui->comboBoxPP_Verif->currentText().toInt();
             QSqlQueryModel * model =  Pa.rechercherP(ID_pay_validation) ;
             ui->tableView_Pai->setModel(model);

             QDate date = QDate ::currentDate();
             QString  Datee= date.toString();

             int reponse = QMessageBox::question(this, "Verifier", "Voulez payer?", QMessageBox::Yes |  QMessageBox::No);
                 if (reponse == QMessageBox::Yes)
                 {

                     bool test= Pa.modifierP(Datee,ID_pay_validation);


                        if (test)

                        {
                            ui->comboBoxPP_Verif->setModel(Pa.afficheroncomboPT());

                                 on_label_pic_PA_linkActivated(0);
                                     //actualisation  afficher

                                  ui->tableView_Pai->setModel(Pa.afficherP());
                                  QString His = " Valider Paiement de   Numero : ";
                                  on_Historique_Pa__clicked(His,ID_pay_validation);

                                }



                 }

                 if (reponse == QMessageBox::No)
                 {

                 }
                 ui->tableView_Pai->setModel(Pa.afficherP());

             }



         void MainWindow::on_pushButton_numF_2_clicked()
         {Click();
             bool test=Pa.supprimerP(ui->comboBoxPP_2->currentText().toInt());
             if(test)
             {ui->tableView_Pai->setModel(Pa.afficherP());
                  ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());//actualisation  affichage
                  ui->comboBoxPP_Verif->setModel(Pa.afficheroncomboPT());
                    on_label_pic_PA_linkActivated(2);
                    QString His = "Suppresion Du paiement : ";
                    int k =ui->comboBoxPP_2->currentText().toInt();
                    on_Historique_Pa__clicked(His,k);
                 }

                 else
                    on_label_pic_PA_linkActivated(6);
         }

         // Lucky Number 7 //

         void MainWindow::on_comboBox_2_currentIndexChanged(int index2)
         {
             int b;
                 b=index2;
             ui->comboBoxPP_2->currentText();
         }


         void MainWindow::on_commandLinkButton_TRI_Pa_clicked()
         {Click();
             ui->tableView_Pai->setModel(Pa.tri_Pa());
             on_label_pic_PA_linkActivated(1);
             QString His = "Tri  Paiement   ";
             on_Historique_Pa__clicked(His,0);

         }

         void MainWindow::on_pushButton_recherche_ID_clicked()
         {Click();
             int i=0;
             int ID=ui->comboBoxPrecherche->currentText().toInt();
             ui->tableView_Pai->setModel(Pa.rechercherP(ID));
               int row = ui->tableView_Pai->model()->rowCount();

             if (row !=0)
             {
                 i=3;
                 QString His = "Recherche du  Paiement Numero :";
                 on_Historique_Pa__clicked(His,ID);
             }


             on_label_pic_PA_linkActivated(i);

         }


         void MainWindow::on_commandLinkButton_Statt_clicked()
         {Click();
         Pa.Statistique_Pa();
         on_label_pic_PA_linkActivated(5);
         QString His = "Affichage de statistique ";
         on_Historique_Pa__clicked(His,0);
         }



         void MainWindow::on_Traduction_Pa_clicked()
         {Click();
             // Traduction Pa


                QString Lang=ui->Traduction_Pa->text() ;



                if (Lang == "ENG")
                {
                    ui->tabWidget->setTabText(0,"Provider");
                    ui->tabWidget->setTabText(1,"Payments");
                    ui->tabWidget->setTabText(2,"bills");
                     ui->tabWidget->setTabText(3,"NotePad");
                    ui->label_10->setText(" Payment ID");
                    ui->label_12->setText("Payment ID");
                    ui->label_7->setText("Provider ID");
                    ui->label_8->setText("Bill ID");
                    ui->label_9->setText("Total");
                    ui->pushButton_ajF_2->setText("ADD");
                    ui->pushButton_Verif->setText("Verify");
                    ui->pushButton_numF_2->setText("Delete");
                    ui->pushButton_recherche_ID->setText("Search");
                    ui->commandLinkButtonClear_Pa->setText("Clear");
                    ui->Traduction_Pa->setText("RUS");
                    ui->Historique->setText("History");
                    ui->Calculator_PA->setText("Calculator");
                    on_label_pic_PA_linkActivated(10);
                    QString His = "Modification de la langue vers l'Anglais";
                                            on_Historique_Pa__clicked(His,0);



                                        }

                                        if (Lang == "FR")
                                        {

                                            ui->tabWidget->setTabText(0,"Provider");
                                            ui->tabWidget->setTabText(1,"Payments");
                                            ui->tabWidget->setTabText(2,"bills");
                                             ui->tabWidget->setTabText(3,"Bloc notes");
                                            ui->label_10->setText("Identifiant Paiement");
                                            ui->label_12->setText("Identifiant Paiement");
                                            ui->label_7->setText("Identifiant Fournisseur");
                                            ui->label_8->setText("Numero Facture");
                                            ui->label_9->setText("Total");
                                            ui->pushButton_ajF_2->setText("Ajouter");
                                            ui->pushButton_Verif->setText("Verifier");
                                            ui->pushButton_numF_2->setText("Supprimer");
                                            ui->pushButton_recherche_ID->setText("rechercher");
                                            ui->commandLinkButtonClear_Pa->setText("Effacer Tout");
                                            ui->Traduction_Pa->setText("ENG");
                                            ui->Historique->setText("Historique");
                                            ui->Calculator_PA->setText("Calculatrice");

                                            on_label_pic_PA_linkActivated(9);
                                            QString His = "Modification de la langue vers le Francais";
                                                                    on_Historique_Pa__clicked(His,0);

                                        }
                                        if (Lang == "RUS")
                                        {
                                            ui->tabWidget->setTabText(0,"Провайдер");
                                            ui->tabWidget->setTabText(1,"Платежи");
                                            ui->tabWidget->setTabText(2,"Выставленный счет");
                                            ui->tabWidget->setTabText(3,"Блокнот");
                                            ui->label_10->setText("Идентификатор платежа");
                                            ui->label_12->setText("Идентификатор платежа");
                                            ui->label_7->setText("Идентификатор поставщика");
                                            ui->label_8->setText("Номер счета");
                                            ui->label_9->setText("Всего");
                                            ui->pushButton_ajF_2->setText("Добавлять");
                                            ui->pushButton_Verif->setText("Проверять");
                                            ui->pushButton_numF_2->setText("Удалять");
                                            ui->pushButton_recherche_ID->setText("исследовать");
                                            ui->commandLinkButtonClear_Pa->setText("Сбросить все");
                                            ui->Historique->setText("исторический");
                                            ui->Calculator_PA->setText("калькулятор");
                                            ui->Traduction_Pa->setText("FR");
                                            on_label_pic_PA_linkActivated(11);
                                            QString His = "Modification de la langue vers le Russe";
                                                   on_Historique_Pa__clicked(His,0);
                                        }

                                    }
         //Calculator

         void MainWindow::on_Calculator_PA_clicked()
         {Click();
             Shattered_Time(1);
             QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21627/Documents/ProjectFacture/Calculator/Calculator.py"));
             QString His = "Ouverture Du Calculatrice";
             on_Historique_Pa__clicked(His,0);

         }

                                 void MainWindow::on_pushButton_Exit_2_clicked()
                                 {Click();
                                     int reponse = QMessageBox::question(this, "Quitter", "Vous Voulez Vraiment Quitter ?", QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {
                                 close();
                                 QString His = "Exit";
                                        on_Historique_Pa__clicked(His,0);
                                         }
                                         if (reponse == QMessageBox::No)
                                         {

                                         }
                                 }


                                 //---FACTURE---//

                                 //Notification FA

                                 void MainWindow::on_label_pic_FA_linkActivated(int choice)
                                 {


                                     if (choice == 1 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Tri.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }

                                     else if (choice == 2 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Remove.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }
                                     else if (choice == 3 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Search.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }
                                     else if (choice == 4 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Addition.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }

                                     else if (choice == 6 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Error.jpg"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }
                                     else if (choice == 7 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Update.jpg"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }
                                     else if (choice == 8 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/PDF.jpg"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }

                                     else if (choice == 9 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Fr.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }
                                     else if (choice == 10 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/english.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                     }
                                     else if (choice == 11 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Russe.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }

                                     else if (choice == 12 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Clear.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);

                                     }
                                     else if (choice == 13 )
                                     {
                                         QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/not.png"); // <- path to image file
                                                        ui->label_pic_FA->setPixmap(pm);
                                                        ui->label_pic_FA->setScaledContents(true);
                                                        on_label_Animation(4);
                                     }


                                 }


                                 // Clear Button Fa



                                 void MainWindow::on_commandLinkButtonClear_Fa_clicked()

                                 {Click();


                                     ui->lineEdit_numFA->clear();
                                     ui->lineEdit_Montant->clear();
                                     ui->lineEdit_telFone->clear();
                                     ui->textBrowserA->clear();
                                     ui->lineEdit_Email->clear();
                                     ui->dateFAEdit->clear();
                                 on_label_pic_FA_linkActivated(12);



                                 }

                                 int  MainWindow::Blockage(int NUMFA)
                                 {
                                     int i,row=0,Somme=0;


                                     QString  PAYMENT_VALIDATION="Not Yet";
                                 QString sql=QString("select * from PAIEMENT where PAYMENT_VALIDATION ='Not Yet'");
                                 QSqlQuery query(sql);
                                 if(query.isActive())
                                 {
                                 while(query.next())
                                 {
                                 row++;
                                 }
                                 for(i=0 ;i<row;i++)
                                 {
                                 query.seek(i);
                                 Somme+=query.value("TOTAL").toInt();

                                 }


                                 }


                                 return Somme ;
                                 }






//Ajout Fa
                                 int w =0;
                                 void MainWindow::on_pushButton_ajFA_clicked()
                                 {Click();

                                 float Total;
                                 int T_Transport=0;
                                 QString TYPE;
                                 QString TRANSPORT;

                                 if(ui->radioButton_Van->isChecked())
                                 {
                                     TRANSPORT="VAN";
                                     T_Transport=40;
                                 }
                                 if(ui->radioButtonPlane->isChecked())
                                 {
                                     TRANSPORT="PLANE";
                                     T_Transport=500;

                                 }
                                 if(ui->radioButtonTruck->isChecked())
                                 {
                                     TRANSPORT="TRUCK";
                                      T_Transport=100;
                                 }

                                 if(ui->radioButton_actif->isChecked())
                                 {
                                     Fa.TYPE_FACTURE="Actif";
                                 }
                                 else  if(ui->radioButton_pasif->isChecked())
                                 {
                                     Fa.TYPE_FACTURE="Pasif";
                                 }
                                 else
                                 {
                                     QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                                                             QObject::tr("click cancel to exist"),
                                                             QMessageBox::Cancel);

                                 }


                                 int NUMFF=ui->lineEdit_numFA->text().toInt();
                                 QString DATEE=ui->dateFAEdit->text();
                                 QString TVAA=ui->comboBox_TVA->currentText();
                                 QString TEXTE=ui->textBrowserA->text();
                                 QString EMAILL=ui->lineEdit_Email->text();
                                 float MONTANTT=ui->lineEdit_Montant->text().toFloat();
                                 int TELL=ui->lineEdit_telFone->text().toInt();
                                 QString typ;
                                 typ=Fa.TYPE_FACTURE;
                                 EMAILL[0]=EMAILL[0].toUpper();
                                 Total=MONTANTT+T_Transport;
                                 QString TelFA=QString ::number(TELL);
                                  int Somme=Blockage(NUMFF);



            {

            }

                                 //test mail
                                     int test=0,k=0;

                                     for(int i = 0; i < EMAILL.size(); i++) {

                                 if(EMAILL[i]=="@")

                                 {test=test +1 ;



                                 }}

                                     for(int i = 0; i < EMAILL.size(); i++) {

                                 if((test==1)&&(EMAILL[i]=="."))

                                 {if(EMAILL.size()>i+1)

                                     k=1;

                                 }}



                                  FACTURE  Fa(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total);
                                  if((NUMFF==0)||(DATEE=="")||(typ=="")||(TEXTE=="")||(EMAILL=="")||(TRANSPORT=="")||(MONTANTT==0)||(Total==0)||(TVAA==""))
                                  {
                                      QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                                                              QObject::tr("click cancel to exist"),
                                                              QMessageBox::Cancel);


                                  }



                                        else if((TelFA.length()) < 8 )
                                 {
                                      QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                                                              QObject::tr("Le numero de telephone est invalid "),
                                                              QMessageBox::Cancel);
                                  }
                                  else if(k == 0 )
                                 {
                                      QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                                                              QObject::tr("Email Invalid  "),
                                                              QMessageBox::Cancel);
                                  }
                                  else if(Somme > 10000 && w==0)
                                 {
                                      QMessageBox::critical(nullptr,QObject::tr("Erreur 777"),
                                                              QObject::tr("The total invalid payout is above 10000 you have reached the maximum "),
                                                     QMessageBox::Cancel);
                                      on_label_Animation(77);
                                      on_label_Animation(-4);
                                      w=1;
                                      QString His = "User Blocked : " ;
                                                    on_Historique_Pa__clicked(His,NUMFF);
                                  }

                                  else if(Somme > 10000 && w==1)
                                 {
                                      QMessageBox::critical(nullptr,QObject::tr("Erreur 777"),
                                                              QObject::tr("The system will shut down in the next Warning !!! "),
                                                              QMessageBox::Cancel);
                                      on_label_Animation(77);
                                      on_label_Animation(-4);
                                      w=2;
                                  }
                                  else if(Somme > 10000 && w==2)
                                 {
                                      Shattered_Time(1) ;
                                         ui->tabWidget->setVisible(false);
                                         ui->tabWidget_Historique->setVisible(false);

                                      on_label_Animation(777);
                                      on_label_Animation(-4);

                                      QMediaPlayer *player = new QMediaPlayer;
                                      player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Documents/ProjectFacture/Pictures/Welcome to the Game - Hacking Alert.mp3"));
                                      player->setVolume(60);
                                      player->play();
                                      on_label_Animation(775);
                                      QString His = "Vioalation system leading to an emergency Shut Down  !!! ";
                                             on_Historique_Pa__clicked(His,0);
                                      close();

                                  }




                                  else
                                 {



                                      bool test= Fa.ajouterFA();
                                      if (test)
                                             {ui->tableView_facture->setModel(Fa.afficherFA());//actualisation  afficher
                                                  ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());
                                                  ui->comboBox_Generer->setModel(Fa.afficheroncombo_Mail_FA());
                                                         on_label_pic_FA_linkActivated(4);
                                                         QString His = "Ajout De La Facture Numero : ";
                                                                on_Historique_Pa__clicked(His,NUMFF);
                                      }
                                                         else
                                      {
                                                             on_label_pic_FA_linkActivated(6);


                                                         }
                                                           ui->tableView_facture->setModel(Fa.afficherFA());


                                 }



                                 }




                                 void MainWindow::on_pushButton_mdFA_clicked()
                                 {Click();
                                     float Total;
                                     int T_Transport=0;
                                     QString TYPE;
                                     QString TRANSPORT;

                                     if(ui->radioButton_Van->isChecked())
                                     {
                                         TRANSPORT="VAN";
                                         T_Transport=40;
                                     }
                                     if(ui->radioButtonPlane->isChecked())
                                     {
                                         TRANSPORT="PLANE";
                                         T_Transport=500;

                                     }
                                     if(ui->radioButtonTruck->isChecked())
                                     {
                                         TRANSPORT="TRUCK";
                                          T_Transport=100;
                                     }

                                     if(ui->radioButton_actif->isChecked())
                                     {
                                         Fa.TYPE_FACTURE="Actif";
                                     }
                                     else  if(ui->radioButton_pasif->isChecked())
                                     {
                                         Fa.TYPE_FACTURE="Pasif";
                                     }
                                     else
                                     {
                                         QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                                                                 QObject::tr("click cancel to exist"),
                                                                 QMessageBox::Cancel);

                                     }

                                     int NUMFF=ui->lineEdit_numFA->text().toInt();
                                     QString DATEE=ui->dateFAEdit->text();
                                     QString TVAA=ui->comboBox_TVA->currentText();
                                     QString TEXTE=ui->textBrowserA->text();
                                     QString EMAILL=ui->lineEdit_Email->text();
                                     float MONTANTT=ui->lineEdit_Montant->text().toFloat();
                                     int TELL=ui->lineEdit_telFone->text().toInt();
                                     QString typ;
                                     typ=Fa.TYPE_FACTURE;
                                     EMAILL[0]=EMAILL[0].toUpper();
                                     Total=MONTANTT+T_Transport;
                                     QString TelFA=QString ::number(TELL);

                                      FACTURE  Fa(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total);
                                      if((NUMFF==0)||(DATEE=="")||(typ=="")||(TEXTE=="")||(EMAILL=="")||(TRANSPORT=="")||(MONTANTT==0)||(Total==0)||(TVAA==""))
                                      {
                                          QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                                                                  QObject::tr("click cancel to exist"),
                                                                  QMessageBox::Cancel);


                                      }
                                      else if((TelFA.length()) < 8 )
                                     {
                                          QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                                                                  QObject::tr("Le numero de telephone est invalid "),
                                                                  QMessageBox::Cancel);
                                      }

                                     else
                                     {
                                     bool    test=Fa.modifierFA(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total) ;
                                           if (test)
                                           {
                                                 ui->tableView_facture->setModel(Fa.afficherFA());
                                                 ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());
                                                 ui->comboBox_Generer->setModel(Fa.afficheroncombo_Mail_FA());
                                               on_label_pic_FA_linkActivated(7);
                                               QString His = "Modification De La Facture Numero : ";
                                                      on_Historique_Pa__clicked(His,NUMFF);
                                           }
                                           else{

                                                   on_label_pic_FA_linkActivated(6);

                                                       }
                                 }


                                 }



                                 void MainWindow::on_comboBoxPrecherche_currentIndexChanged(int index3)
                                 {
                                     int b;
                                         b=index3;
                                     ui->comboBoxPrecherche->currentText();
                                 }



                                 void MainWindow::on_pushButton_Supp_clicked()
                                 {Click();
                                     bool test=Fa.supprimerFA(ui->comboBoxFa_supprimer->currentText());
                                     if(test)
                                     {ui->tableView_facture->setModel(Fa.afficherFA());
                                          ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());//actualisation  affichage
                                             on_label_pic_FA_linkActivated(2);
                                             QString His = "Suppresion De La Facture de Numero :  ";
                                                    on_Historique_Pa__clicked(His,ui->comboBoxFa_supprimer->currentText().toInt());
                                         }

                                         else
                                             on_label_pic_FA_linkActivated(6);
                                 }




                                 void MainWindow::on_commandLinkButton_TRI_FA_clicked()
                                 {Click();
                                     QString Choice = ui->comboBoxFa_TRI->currentText();
                                     ui->tableView_facture->setModel(Fa.tri_FA(Choice));
                                     on_label_pic_FA_linkActivated(1);
                                     QString His = "Tri  Facture  ";
                                            on_Historique_Pa__clicked(His,0);

                                 }






                                 void MainWindow::on_pushButton_rech_FA_clicked()
                                 {Click();
                                     int i = 13;
                                     QString Email=ui->lineEdit_Recherche_FA->text();
                                     ui->tableView_facture->setModel(Fa.rechercher_FA(Email));
                                     int row = ui->tableView_facture->model()->rowCount();

                                     if (row !=0)
                                     {
                                         i=3;
                                         QString His = "Recherche de facture par email ";
                                                on_Historique_Pa__clicked(His,0);
                                     }
                                     on_label_pic_FA_linkActivated(i);

                                 }







                                 // Traduction FA

                                 void MainWindow::on_Traduction_FA_clicked()
                                 {Click();



                                    QString Lang=ui->Traduction_FA->text() ;



                                    if (Lang == "ENG")
                                    {
                                        ui->tabWidget->setTabText(0,"Provider");
                                        ui->tabWidget->setTabText(1,"Payments");
                                        ui->tabWidget->setTabText(2,"Bills");
                                        ui->tabWidget->setTabText(3,"NotePad");
                                        ui->label_20->setText("ID Bill");
                                        ui->label_21->setText("Date");
                                        ui->label_23->setText("TVA");
                                        ui->label_28->setText("Means Of Transport");
                                        ui->label_25->setText("Total amount");
                                        ui->label_29->setText("Description");
                                        ui->label_30->setText("Mail");
                                        ui->label_27->setText("Phone Number");
                                        ui->label_22->setText("Type");
                                        ui->commandLinkButton_Ge->setText("Generate");
                                        ui->pushButton_ajFA->setText("ADD");
                                        ui->pushButton_mdFA->setText("Update");
                                        ui->pushButton_Supp->setText("Delete");
                                        ui->pushButton_rech_FA->setText("Search");
                                        ui->commandLinkButtonClear_Fa->setText("Clear");
                                        ui->Traduction_FA->setText("RUS");
                                        on_label_pic_FA_linkActivated(10);
                                        QString His = "Modification De la Langue vers l'Anglais ";
                                               on_Historique_Pa__clicked(His,0);




                                    }

                                    if (Lang == "FR")
                                    {
                                        ui->tabWidget->setTabText(0,"Fournisseur");
                                        ui->tabWidget->setTabText(1,"Paiement");
                                        ui->tabWidget->setTabText(2,"Facture");
                                        ui->tabWidget->setTabText(3,"Bloc notes");
                                        ui->label_20->setText("Numero Facture");
                                        ui->label_21->setText("Date");
                                        ui->label_23->setText("TVA");
                                        ui->label_28->setText("Transport");
                                        ui->label_25->setText("Montant");
                                        ui->label_29->setText("Description");
                                        ui->label_30->setText("Email");
                                        ui->label_27->setText("Telephone");
                                        ui->label_22->setText("Type");

                                        ui->pushButton_ajFA->setText("Ajouter");
                                        ui->pushButton_mdFA->setText("Modifier");
                                        ui->pushButton_Supp->setText("Supprimer");
                                        ui->pushButton_rech_FA->setText("Rechercher");
                                        ui->commandLinkButtonClear_Fa->setText("Effacer Tout");
                                        ui->commandLinkButton_Ge->setText("Generer");

                                        ui->Traduction_FA->setText("ENG");
                                        on_label_pic_FA_linkActivated(9);
                                        QString His = "Modification De la Langue vers le Francais ";
                                               on_Historique_Pa__clicked(His,0);

                                    }
                                    if (Lang == "RUS")
                                    {
                                        ui->tabWidget->setTabText(0,"Провайдер");
                                        ui->tabWidget->setTabText(1,"Платежи");
                                        ui->tabWidget->setTabText(2,"Выставленный счет");
                                        ui->tabWidget->setTabText(3,"Блокнот");
                                        ui->label_20->setText("я бы");
                                        ui->label_21->setText("Дата");
                                        ui->label_23->setText("TVA");
                                        ui->label_28->setText("Транспортные средства");
                                        ui->label_25->setText("Общая сумма");
                                        ui->label_29->setText("Описание");
                                        ui->label_30->setText("Почта");
                                        ui->label_27->setText("Телефонный номер");
                                        ui->label_22->setText("Тип");
                                        ui->pushButton_ajFA->setText("Добавлять");
                                        ui->pushButton_mdFA->setText("Обновить");
                                        ui->pushButton_Supp->setText("Удалять");
                                        ui->commandLinkButton_Ge->setText("Создать");

                                        ui->pushButton_rech_FA->setText("исследовать");
                                        ui->commandLinkButtonClear_Fa->setText("Сбросить все");
                                        ui->Traduction_FA->setText("FR");
                                        on_label_pic_FA_linkActivated(11);
                                        QString His = "Modification De la Langue vers le Russe ";
                                               on_Historique_Pa__clicked(His,0);









                                    }

                                 }


                                 void MainWindow::on_pushButton_Exit_clicked()
                                 {Click();
                                     int reponse = QMessageBox::question(this, "Quitter", "Vous Voulez Vraiment Quitter ?", QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {
                                             QString His = "Exit";
                                                    on_Historique_Pa__clicked(His,0);
                                         }
                                         if (reponse == QMessageBox::No)
                                         {

                                         }
                                 }





                                 //FILE

                                 //Notification File
                                 void MainWindow::on_label_pic_File_linkActivated(int choice)
                                 {


                                  if (choice == 9 )
                                 {
                                     QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Fr.png"); // <- path to image file
                                                    ui->label_pic_File->setPixmap(pm);
                                                    ui->label_pic_File->setScaledContents(true);
                                                    on_label_Animation(3);
                                 }
                                 else if (choice == 10 )
                                 {
                                     QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/english.png"); // <- path to image file
                                                    ui->label_pic_File->setPixmap(pm);
                                                    ui->label_pic_File->setScaledContents(true);
                                                    on_label_Animation(3);
                                 }
                                 else if (choice == 11 )
                                 {
                                     QPixmap pm("C:/Users/21627/Documents/ProjectFacture/Pictures/Russe.png"); // <- path to image file
                                                    ui->label_pic_File->setPixmap(pm);
                                                    ui->label_pic_File->setScaledContents(true);
                                                    on_label_Animation(3);
                                 }

                                 }

                                 void MainWindow::on_pushButton_New_clicked()
                                 {Click();
                                     currentFile.clear();
                                     ui->textEdit_->setText(QString());
                                     QString His = "nouveau fichier ";
                                            on_Historique_Pa__clicked(His,0);
                                 }


                                 void MainWindow::on_pushButton_clicked()
                                 {Click();
                                     QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer sous..");
                                     QFile file(fileName);
                                     if (!file.open(QFile::WriteOnly | QFile::Text)) {
                                         QMessageBox::warning(this, "Error 777", "Pas d'enregistrement de fichier" + file.errorString());
                                         return;
                                 }
                                     currentFile = fileName;
                                     setWindowTitle(fileName);
                                     QTextStream out(&file);
                                     QString text = ui->textEdit_->toPlainText();
                                     out << text;
                                     file.close();
                                     QString His = "Enregistrement Fichier ";
                                            on_Historique_Pa__clicked(His,0);
                                 }

                                 void MainWindow::on_pushButton_Copy_clicked()
                                 {Click();
                                     ui->textEdit_->copy();
                                     QString His = "Copier ";
                                            on_Historique_Pa__clicked(His,0);
                                 }

                                 void MainWindow::on_pushButton_Coupper_clicked()
                                 {Click();
                                     ui->textEdit_->paste();
                                     QString His = "Coller ";
                                            on_Historique_Pa__clicked(His,0);

                                 }

                                 void MainWindow::on_pushButton_Cut_clicked()
                                 {Click();
                                     ui->textEdit_->cut();
                                     QString His = "Couper ";
                                            on_Historique_Pa__clicked(His,0);

                                 }


                                 void MainWindow::on_pushButton_Open_clicked()
                                 {Click();
                                     QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir le fichier");
                                     QFile file(fileName);
                                     currentFile = fileName;
                                     if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
                                         QMessageBox::warning(this, "Probléme", "fichier non ouvrir " + file.errorString());
                                         return;
                                     }

                                     setWindowTitle(fileName);
                                     QTextStream in(&file);
                                     QString text = in.readAll();
                                     ui->textEdit_->setText(text);
                                     file.close();
                                     QString His = "Ouverture du Fichier ";
                                            on_Historique_Pa__clicked(His,0);
                                 }

                                 void MainWindow::on_pushButton_Imprimer_clicked()
                                 {Click();
                                     QPrinter printer;

                                     printer.setPrinterName("Nom de l'imprimente");
                                     QPrintDialog pDialog(&printer, this);
                                     if(pDialog.exec() == QDialog::Rejected){
                                         QMessageBox::warning(this, "Probleme", "Pas de connexion avec l'imprimente");
                                         return;
                                     }
                                     ui->textEdit_->print(&printer);
                                     QString His = "Impression du  Fichier ";
                                            on_Historique_Pa__clicked(His,0);

                                 }

                                 void MainWindow::on_pushButton_Exit_4_clicked()
                                 {Click();
                                     int reponse = QMessageBox::question(this, "Quitter", "Vous Voulez Vraiment Quitter ?", QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {
                                             QString His = "Exit";
                                                    on_Historique_Pa__clicked(His,0);
                                         }
                                         if (reponse == QMessageBox::No)
                                         {

                                         }

                                 }

                                 //Traduction File
                                 void MainWindow::on_Traduction_File_clicked()
                                 {
Click();


                                     QString Lang=ui->Traduction_File->text() ;



                                     if (Lang == "ENG")
                                     {
                                         ui->tabWidget->setTabText(0,"Provider");
                                         ui->tabWidget->setTabText(1,"Payments");
                                         ui->tabWidget->setTabText(2,"Bills");
                                         ui->tabWidget->setTabText(3,"NotePad");
                                         ui->pushButton_Cut->setText("Cut");
                                         ui->pushButton_New->setText("New");
                                         ui->pushButton_Copy->setText("Copy");
                                         ui->pushButton_Open->setText("Open");
                                         ui->pushButton_Exit_4->setText("Exit");
                                         ui->pushButton_Coupper->setText("Paste");
                                         ui->pushButton->setText("Save");
                                         ui->pushButton_Imprimer->setText("Print");
                                         ui->Traduction_File->setText("RUS");
                                          on_label_pic_File_linkActivated(10);
                                          QString His = "Notepad en Anglais";
                                                 on_Historique_Pa__clicked(His,0);




                                     }

                                     if (Lang == "FR")
                                     {
                                         ui->tabWidget->setTabText(0,"Fournisseur");
                                         ui->tabWidget->setTabText(1,"Paiement");
                                         ui->tabWidget->setTabText(2,"Facture");
                                         ui->tabWidget->setTabText(3,"Bloc notes");
                                         ui->pushButton_Cut->setText("Couper");
                                         ui->pushButton_New->setText("Nouveau");
                                         ui->pushButton_Copy->setText("Copier");
                                         ui->pushButton_Open->setText("Ouvrir");
                                         ui->pushButton_Exit_4->setText("Sortir");
                                         ui->pushButton_Coupper->setText("Coller");
                                         ui->pushButton->setText("Enregistrer");
                                         ui->pushButton_Imprimer->setText("Imprimer");

                                         ui->Traduction_File->setText("ENG");
                                          on_label_pic_File_linkActivated(9);
                                          QString His = "Notepad en Francais";
                                                 on_Historique_Pa__clicked(His,0);

                                     }
                                     if (Lang == "RUS")
                                     {
                                         ui->tabWidget->setTabText(0,"Провайдер");
                                         ui->tabWidget->setTabText(1,"Платежи");
                                         ui->tabWidget->setTabText(2,"Выставленный счет");
                                         ui->tabWidget->setTabText(3,"Блокнот");
                                         ui->pushButton_Cut->setText("резать");
                                         ui->pushButton_New->setText("новый");
                                         ui->pushButton_Copy->setText("копировать");
                                         ui->pushButton_Open->setText("Открыть");
                                         ui->pushButton_Exit_4->setText("выход");
                                         ui->pushButton_Coupper->setText("придерживаться");
                                         ui->pushButton->setText("спасти");
                                         ui->pushButton_Imprimer->setText("Распечатать");


                                         ui->Traduction_File->setText("FR");
                                         on_label_pic_File_linkActivated(11);
                                         QString His = "Notepad en Russe";
                                                on_Historique_Pa__clicked(His,0);









                                     }
                                 }



                                 void MainWindow::on_commandLinkButton_Ge_clicked()
                                 {Click();
                                 int NUMFA;
                                      int Row ;
                                              QSqlQueryModel* model=new QSqlQueryModel();
                                              QSqlQuery query;
                                         QString Email = ui->comboBox_Generer->currentText();
                                     ui->tableView_facture->setModel(Fa.rechercher_FA(Email));
                                     int reponse = QMessageBox::question(this, "Génerer Facture", " Saisir le numero de facture  ?", QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {      Shattered_Time(2); //attendre 2 seconde
                                            ui->lineEdit_Generer_Fa->setVisible(true);
                                                 Shattered_Time(7);
                                  NUMFA =ui->lineEdit_Generer_Fa->text().toInt();
                                                 query.prepare("SELECT * FROM FACTURE WHERE EMAIL=:EMAIL AND :NUMFA = NUMFA");
                                                 query.bindValue(":EMAIL",Email);
                                                 query.bindValue(":NUMFA",NUMFA);
                                                 query.exec();

                                                 model->setQuery(query);
                                                 ui->tableView_facture->setModel(model);
                                                 Row = ui->tableView_facture->model()->rowCount();
                                                 if (Row  !=0)

                                                 {   ui->lineEdit_Generer_Fa->clear();
                                                     ui->lineEdit_Generer_Fa->setVisible(false);
                                                     on_label_pic_FA_linkActivated(15);
                                                     Shattered_Time(5);
                                                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21627/Documents/ProjectFacture/PDF/Facture.docx"));
                                                QString His = "Generation de la Facture : ";
                                                       on_Historique_Pa__clicked(His,NUMFA);

                                                 }
                                                 else
                                                 {
                                                   ui->lineEdit_Generer_Fa->setVisible(false);
                                                  on_label_pic_FA_linkActivated(6);

                                                 on_commandLinkButton_Ge_clicked();

                                                 }
                                         }




                                 }


void MainWindow::on_Excel_clicked()
{


                const QString fileName = "C:/Users/21627/Documents/ProjectFacture/Excel";



                ExcelExportHelper helper;

    int l=2;

                QSqlQuery q;

                if(q.exec("SELECT * FROM FACTURE"))

                {

    helper.SetCellValue(1,1,"Numero Facture");

    helper.SetCellValue(1,2,"Date Facture");

    helper.SetCellValue(1,3,"Type ");

    helper.SetCellValue(1,4,"USERNAME");

    helper.SetCellValue(1,5,"EMAIL");

    helper.SetCellValue(1,6,"MDP");

    helper.SetCellValue(1,7,"NBPOINTS");

    helper.SetCellValue(1,8,"BRANCHE");

                    while (q.next())

                    {



                helper.SetCellValue(l,1,q.value(0).toString());

                helper.SetCellValue(l,2,q.value(1).toString());

                helper.SetCellValue(l,3,q.value(2).toString());

                helper.SetCellValue(l,4,q.value(3).toString());

                helper.SetCellValue(l,5,q.value(4).toString());

                helper.SetCellValue(l,6,q.value(5).toString());

                helper.SetCellValue(l,7,q.value(6).toString());

                helper.SetCellValue(l,8,q.value(7).toString());

    l++;



                    }

                helper.SaveAs(fileName);

            }



}



void MainWindow::on_Stat_FA_clicked()
{

    Click();
            Fa.Statistique_Fa();
             on_label_pic_PA_linkActivated(5);
             QString His = "Affichage de statistique ";
             on_Historique_Pa__clicked(His,0);
}





void MainWindow::on_commandLinkButton_T1_clicked()
{Click();
    QString T=ui->commandLinkButton_T1->text();

    if (T=="Theme 1")
{
    QFile styleSheetFile(":/Pictures/Diffnes.qss");
     styleSheetFile.open(QFile::ReadOnly);
     QString styleSheet = QLatin1String(styleSheetFile.readAll());
     MainWindow::setStyleSheet(styleSheet);
ui->commandLinkButton_T1->setText("Theme 2");
int i=1;
QString His = "Set Theme";
on_Historique_Pa__clicked(His,i);
    }
    else if (T=="Theme 2")
    {
        QFile styleSheetFile(":/Pictures/Dtor.qss");
         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 3");
    int i=2;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);
    }
    else if (T=="Theme 3")
    {
         QFile styleSheetFile(":/Pictures/Scalcula.qss");

         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 4");
    int i=3;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);
    }
    else if (T=="Theme 4")
    {
        QFile styleSheetFile(":/Pictures/Filmovio.qss");
         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 5");
    int i=4 ;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);
    }
    else if (T=="Theme 5")
    {
        QFile styleSheetFile(":/Pictures/SyNet.qss");
         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 6");
    int i=5 ;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);
    }

    else if (T=="Theme 6")
    {
         QFile styleSheetFile(":/Pictures/Perstfic.qss");
         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 7");
    int i=6 ;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);

    }
    else if (T=="Theme 7")
    {

        QFile styleSheetFile(":/Pictures/MacOS.qss");
         styleSheetFile.open(QFile::ReadOnly);
         QString styleSheet = QLatin1String(styleSheetFile.readAll());
         MainWindow::setStyleSheet(styleSheet);
    ui->commandLinkButton_T1->setText("Theme 1");
    int i=7 ;
    QString His = "Set Theme";
    on_Historique_Pa__clicked(His,i);
    }
}




