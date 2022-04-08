#include "fournisseur.h"
#include<QSqlRecord>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>


Fournisseur::Fournisseur(){}
 Fournisseur::Fournisseur(int  numF,QString nomF,QString prenF,QString addF,int telF,QString typeF)
{
this->numF=numF;
     this->nomF=nomF;
     this->prenF=prenF;
     this->addF=addF;
     this->telF=telF;
     this->typeF=typeF;
}

 bool Fournisseur::ajouter()
 {
 QSqlQuery query;
     query.prepare("INSERT INTO FOURNISSEUR (numF,nomF,prenF,addF,telF,typeF) "
                         "VALUES (:numF, :nomF, :prenF,:addF ,:telF,:typeF)");
     query.bindValue(":numF",numF);
     query.bindValue(":nomF",nomF);
     query.bindValue(":prenF",prenF);
     query.bindValue(":addF",addF);
     query.bindValue(":telF",telF);
     query.bindValue(":typeF",typeF);


     return    query.exec();

 }

 bool Fournisseur :: supprimer(int idd)
 {
     QString ident1= QString ::number(idd);
     QSqlQuery query;
     query.prepare("Delete from FOURNISSEUR where telF = :telF ");
     query.bindValue(":telF",ident1);
     return    query.exec();

 }


 QSqlQueryModel * Fournisseur ::afficher()
 {

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from FOURNISSEUR");

         return model;
 }
 bool Fournisseur::modifier(int  numF,QString nomF,QString prenF,QString addF,int telF,QString typeF)
 {

     QSqlQuery query;

     query.prepare("UPDATE FOURNISSEUR SET nomF= :nomF, prenF= :prenF , addF= :addF , telF= :telF , typeF= :typeF where numF= :numF ");
     query.bindValue(":numF", numF);
     query.bindValue(":nomF", nomF);
     query.bindValue(":prenF",prenF);
     query.bindValue(":addF", addF);
     query.bindValue(":telF", telF);
     query.bindValue(":typeF",typeF);

             return    query.exec();

 }

 QSqlQueryModel * Fournisseur ::afficheroncombo()
 {

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select telF  from fournisseur");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

         return model;
 }


 QSqlQueryModel * Fournisseur ::recherche(QString Nom)
 {
     int count;
     QSqlQueryModel* model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT * FROM fournisseur WHERE nomF=:nomF OR prenF= :prenF  ");
     query.bindValue(":nomF",Nom);
     query.bindValue(":prenF",Nom);
     query.exec();

     model->setQuery(query);

     return model;
 }

 QSqlQueryModel* Fournisseur ::tri_Fo()
 {
     QSqlQueryModel* Tri_Fo_model=new QSqlQueryModel();

     Tri_Fo_model->setQuery("SELECT* FROM fournisseur ORDER BY numF");
     Tri_Fo_model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomF"));
     Tri_Fo_model->setHeaderData(3, Qt::Horizontal, QObject::tr("addF"));
     Tri_Fo_model->setHeaderData(4, Qt::Horizontal, QObject::tr("telF"));
     Tri_Fo_model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenF"));
     Tri_Fo_model->setHeaderData(0, Qt::Horizontal, QObject::tr("numF"));
     Tri_Fo_model->setHeaderData(5, Qt::Horizontal, QObject::tr("typeF"));


     return Tri_Fo_model;
 }
 void Fournisseur ::  Generer_PDF()
 {
 QDate date ;
QDate datecreation = date.currentDate() ;
    QString Datee =  datecreation.toString() ;
           QPdfWriter Pdf_Fo("C:/Users/21627/Documents/ProjectFacture/PDF/Tables_Fournisseurs.pdf");
           QPainter painter(&Pdf_Fo);
          int i = 3100;


               painter.setPen(Qt::blue);
               painter.setFont(QFont("Baskerville Old Face", 40));
               painter.drawText(1100,1000,"    Liste Des Fournisseurs");
               painter.setPen(Qt::red);
               painter.setFont(QFont("Century Gothic (Body)", 20));
               painter.drawText(7000,100,Datee);
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial",15));
               painter.drawRect(100,100,8000,2600);
               painter.drawRect(0,3000,19300,500);
               painter.setPen("orange");
               painter.setFont(QFont("Arial Black", 16));
               painter.drawText(200,3300,"Numero ");
               painter.drawText(1700,3300,"Nom");
               painter.drawText(3200,3300,"Prenom");
               painter.drawText(4700,3300,"Adresse");
               painter.drawText(6500,3300,"Telephone");
               painter.drawText(8300,3300,"Type");
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial ", 12));
               QSqlQuery query;
               query.prepare("select * from FOURNISSEUR");
               query.exec();
               while (query.next())
               {
                   painter.drawText(400,i,query.value(0).toString());
                   painter.drawText(1700,i,query.value(1).toString());
                   painter.drawText(3200,i,query.value(2).toString());
                   painter.drawText(4900,i,query.value(3).toString());
                   painter.drawText(6600,i,query.value(4).toString());
                   painter.drawText(8400,i,query.value(5).toString());


                  i = i + 600;
               }





}
