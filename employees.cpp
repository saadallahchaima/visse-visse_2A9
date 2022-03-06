#include "employees.h"
#include "connection.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

Employees::Employees(int cin,QString nomprenom,QString naissance,QString nationnalite,QString adressee ,QString date_entree,QString email,QString assurance,QString situation_familiale,int nombre_enfants,int cnss,float salaire)
{
  this->cin=cin;
  this->nomprenom=nomprenom;
  this->naissance=naissance;
  this->nationnalite=nationnalite;
  this->adresse=adresse;
  this->date_entree=date_entree;
  this->email=email;
  this->cnss=cnss;
  this->assurance=assurance;
  this->nombre_enfants=nombre_enfants;
  this->salaire=salaire;
  this->situation_familiale=situation_familiale;


}
/*
bool Employees::ajouter_employe()
{
    QSqlQuery query;
    query.prepare("insert into Employees(cin,nomprenom,naissance,adresse,profession,situation_familiale,cnss,assurance,date_entree,nombre_enfants,salaire,nationnalite,email;)"
                  "values(:cin,:nomprenom,:naissance,:adresse,:profession,:situation_familiale,:cnss,:assurance,:date_entree,:nombre_enfants,:salaire,:nationnalite,:email;)");
    query.bindValue(":cin",cin);
    query.bindValue(":nomprenom",nomprenom);
    query.bindValue(":naissance",naissance);
    query.bindValue(":adresse",adresse);
    query.bindValue(":profession",profession);
    query.bindValue(":situation_familiale",profession);
    query.bindValue(":cnss",cnss);
    query.bindValue(":assurances",assurance);
    query.bindValue(":date_entree",date_entree);
    query.bindValue(":nombre_enfants",nombre_enfants);
    query.bindValue(":salaire",salaire);
    query.bindValue(":nationnalite",nationnalite);
    query.bindValue(":email",email);

    return query.exec();
}


QSqlQueryModel* Employees::afficher_employe()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Employees");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomprenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("naissance"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationnalite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationnalite"));
    return model;
}
*/


