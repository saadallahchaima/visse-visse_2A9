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
     //QString id= QString::number(ID);
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
     QSqlQueryModel* model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT * FROM fournisseur WHERE nomF=:nomF OR prenF= :prenF  ");
     query.bindValue(":nomF",Nom);
     query.bindValue(":prenF",Nom);
     query.exec();
     model->setQuery(query);

     return model;
 }


