#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_fournis->setModel(fo.afficher());
    ui->comboBox->setModel(fo.afficheroncombo());
    ui->tableView_facture->setModel(Fa.afficherFA());
    ui->comboBoxP_3->setModel(Pa.afficheroncomboP());
    ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());
    ui->tableView_Pai->setModel(Pa.afficherP());
    ui->comboBoxPrecherche->setModel(Pa.afficheroncomboPT());
    ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());
// Fournisseur
    ui->lineEdit_numF->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_nomF->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    ui->lineEdit_prenF->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    ui->lineEdit_telF->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_addF->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
    // Paiement
        ui->lineEditfa->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_PFA_2->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_numP_3->setValidator(new QIntValidator(0,99999999,this));
        // Facteur
            ui->lineEdit_numFA->setValidator(new QIntValidator(0,99999999,this));
            ui->lineEdit_Email->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));
            ui->lineEdit_Montant->setValidator(new QIntValidator(0,99999999,this));
            ui->lineEdit_telFone->setValidator(new QIntValidator(0,99999999,this));
            ui->textBrowserA->setValidator(new QRegExpValidator( QRegExp("[A-Z..a-z]*") ));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajF_clicked()
{

   int NumF=ui->lineEdit_numF->text().toInt();
QString nom=ui->lineEdit_nomF->text();
QString Prenf=ui->lineEdit_prenF->text();
QString Adress=ui->lineEdit_addF->text();
int Tel=ui->lineEdit_telF->text().toInt();
QString TYPE=ui->comboBox_typeF->currentText();


 if((NumF==0)||(nom=="")||(Prenf=="")||(Adress=="")||(Tel==0)||(TYPE==""))
 {
     QMessageBox::critical(nullptr,QObject::tr("Verifier Champs Vide !"),
                             QObject::tr("click cancel to exist"),
                             QMessageBox::Cancel);

 }



else
 {

Fournisseur f(NumF,nom,Prenf,Adress,Tel,TYPE);
bool test= f.ajouter();




       if (test)
       {ui->tableView_fournis->setModel(fo.afficher());//actualisation taa afficher
  ui->comboBox->setModel(fo.afficheroncombo());
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView_fournis->setModel(fo.afficher());
}
}


void MainWindow::on_pushButton_numF_clicked()
{
    bool test=fo.supprimer(ui->comboBox->currentText().toInt());
    if(test)
    {ui->tableView_fournis->setModel(fo.afficher());
         ui->comboBox->setModel(fo.afficheroncombo());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox->currentText();
}

void MainWindow::on_pushButton_mdF_clicked()
{

    int NumF=ui->lineEdit_numF->text().toInt();
 QString nom=ui->lineEdit_nomF->text();
 QString Prenf=ui->lineEdit_prenF->text();
 QString Adress=ui->lineEdit_addF->text();
 int Tel=ui->lineEdit_telF->text().toInt();
 QString TYPE=ui->comboBox_typeF->currentText();


  if((NumF==0)||(nom=="")||(Prenf=="")||(Adress=="")||(Tel==0)||(TYPE==""))
  {
      QMessageBox::critical(nullptr,QObject::tr("Verifier Champs Vide !"),
                              QObject::tr("click cancel to exist"),
                              QMessageBox::Cancel);

  }



 else
  {


 bool test= fo.modifier(NumF,nom,Prenf,Adress,Tel,TYPE);




        if (test)
        {ui->tableView_fournis->setModel(fo.afficher());//actualisation taa afficher
   ui->comboBox->setModel(fo.afficheroncombo());
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("modifie etablie .\n"),
                            QMessageBox::Cancel);
                }

                else
                    QMessageBox::critical(nullptr,QObject::tr("modifie not etablie !"),
                                            QObject::tr("click cancel to exist"),
                                            QMessageBox::Cancel);



         ui->tableView_fournis->setModel(fo.afficher());
 }
}

void MainWindow::on_pushButton_ajF_2_clicked()
{
    int NUMF=ui->comboBoxP_3->currentText().toInt();
    int NUMFA=ui->lineEditfa->text().toInt();
    float Total=ui->lineEdit_PFA_2->text().toInt();
    QString date=ui->dateEditP->text();
    int ID =ui->lineEdit_numP_3->text().toInt();

    if((NUMF==0)||(date=="")||(ID==0)||(Total==0)||(NUMFA==0))
    {
        QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                                QObject::tr("click cancel to exist"),
                                QMessageBox::Cancel);


    }
    else
    {

    Paiement  Pay(NUMF,NUMFA,Total,date,ID);
       bool test= Pay.ajouterP();

     if (test)
       {ui->tableView_Pai->setModel(Pa.afficherP());//actualisation  afficher
  ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());

                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView_Pai->setModel(Pa.afficherP());
}
}

void MainWindow::on_comboBoxP_3_currentIndexChanged(int index)
{

    int a;
        a=index;
    ui->comboBoxP_3->currentText();
}

void MainWindow::on_pushButton_mdF_2_clicked()
{

          int NUMF=ui->comboBoxP_3->currentText().toInt();
          int NUMFA=ui->lineEditfa->text().toInt();
          float Total=ui->lineEdit_PFA_2->text().toInt();
          QString date=ui->dateEditP->text();
          int ID =ui->lineEdit_numP_3->text().toInt();

          if((NUMF==0)||(date=="")||(ID==0)||(Total==0)||(NUMFA==0))
          {
              QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                                      QObject::tr("click cancel to exist"),
                                      QMessageBox::Cancel);


          }
          else
          {


             bool test= Pa.modifierP(NUMF,NUMFA,Total,date,ID);

           if (test)
             {ui->tableView_Pai->setModel(Pa.afficherP());//actualisation  afficher
        ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());

                         QMessageBox::information(nullptr,QObject::tr("ok"),
                                                  QObject::tr("Modifiy succful .\n"),
                                 QMessageBox::Cancel);
                     }

                     else
                         QMessageBox::critical(nullptr,QObject::tr("modification non établie"),
                                                 QObject::tr("click cancel to exist"),
                                                 QMessageBox::Cancel);



              ui->tableView_Pai->setModel(Pa.afficherP());
      }




}


void MainWindow::on_pushButton_numF_2_clicked()
{
    bool test=Pa.supprimerP(ui->comboBoxPP_2->currentText().toInt());
    if(test)
    {ui->tableView_Pai->setModel(Pa.afficherP());
         ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());//actualisation  affichage
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}









void MainWindow::on_comboBox_2_currentIndexChanged(int index2)
{
    int b;
        b=index2;
    ui->comboBoxPP_2->currentText();
}


void MainWindow::on_pushButton_ajFA_clicked()
{
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
Total=MONTANTT+T_Transport;
 FACTURE  Fa(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total);
 if((NUMFF==0)||(DATEE=="")||(typ=="")||(TEXTE=="")||(EMAILL=="")||(TRANSPORT=="")||(MONTANTT==0)||(Total==0)||(TVAA==""))
 {
     QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                             QObject::tr("click cancel to exist"),
                             QMessageBox::Cancel);


 }
 else
{



     bool test= Fa.ajouterFA();
     if (test)
            {ui->tableView_facture->setModel(Fa.afficherFA());//actualisation  afficher
                 ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());

                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("ajout succful .\n"),
                                QMessageBox::Cancel);
     }
                        else
     {
                            QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                                    QObject::tr("click cancel to exist"),
                                                    QMessageBox::Cancel);


                        }
                          ui->tableView_facture->setModel(Fa.afficherFA());


}












}




void MainWindow::on_pushButton_mdFA_clicked()
{
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
    Total=MONTANTT+T_Transport;
     FACTURE  Fa(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total);
     if((NUMFF==0)||(DATEE=="")||(typ=="")||(TEXTE=="")||(EMAILL=="")||(TRANSPORT=="")||(MONTANTT==0)||(Total==0)||(TVAA==""))
     {
         QMessageBox::critical(nullptr,QObject::tr("Verifier les champs"),
                                 QObject::tr("click cancel to exist"),
                                 QMessageBox::Cancel);


     }
    else
    {
    bool    test=Fa.modifierFA(NUMFF,DATEE,typ,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total) ;
          if (test)
          {
                ui->tableView_facture->setModel(Fa.afficherFA());
                ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}

}
}





void MainWindow::on_pushButton_recherche_clicked()
{

  QString Nom;
  Nom=ui->lineEdit_recherche->text();
 ui->tableView_fournis->setModel(fo.recherche(Nom));
}

void MainWindow::on_comboBoxPrecherche_currentIndexChanged(int index3)
{
    int b;
        b=index3;
    ui->comboBoxPrecherche->currentText();
}

void MainWindow::on_pushButton_recherche_ID_clicked()
{
    int ID;
    ID=ui->comboBoxPrecherche->currentText().toInt();
   ui->tableView_Pai->setModel(Pa.rechercherP(ID));
}






void MainWindow::on_comboBoxFa_supprimer_currentTextChanged(QString emaill)
{
    QString b;
        b=emaill;
    ui->comboBoxFa_supprimer->currentText();

    bool test=Fa.supprimerFA(ui->comboBoxFa_supprimer->currentText());
    if(test)
    {ui->tableView_facture->setModel(Fa.afficherFA());
         ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());//actualisation  affichage
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}



void MainWindow::on_comboBoxFa_supprimer_currentIndexChanged(int indexr)
{
    int  b;
        b=indexr;
    ui->comboBoxFa_supprimer->currentText();
}

void MainWindow::on_pushButton_Sup_clicked()
{
    bool test=Fa.supprimerFA(ui->comboBoxFa_supprimer->currentText());
    if(test)
    {ui->tableView_facture->setModel(Fa.afficherFA());
         ui->comboBoxFa_supprimer->setModel(Fa.afficheroncomboFA());//actualisation  affichage
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}
