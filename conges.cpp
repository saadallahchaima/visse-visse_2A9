#include "conges.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
using namespace std;

conges::conges(int idC,QDate date_deb,QDate date_fin,int cin_emp,QString nom_emp,QString email_emp,QString type_c,QString cause)
{
this->idC=idC;
this->date_deb=date_deb;
this->date_fin=date_fin;
this->cin_emp=cin_emp;
this->nom_emp=nom_emp;
this->email_emp=email_emp;
this->type_c=type_c;
this->cause=cause;
}
bool conges::ajouter_conge()
{
 QSqlQuery query;
 QString res = QString::number(idC);
 QString cin_emp_string = QString::number(cin_emp);

 query.prepare("insert into conges(idC,date_deb,date_fin,cin_emp,nom_emp,email_emp,type_c,cause)""values (:idC,:date_deb,:date_fin,:cin_emp,:email_emp,:type_c,:cause)");

query.bindValue(":idC",res);
query.bindValue(":date_deb",date_deb);
query.bindValue(":date_fin",date_fin);
query.bindValue(":cin_emp",cin_emp_string);
query.bindValue(":nom_emp",nom_emp);
query.bindValue(":email_emp",email_emp);
query.bindValue(":type_c",type_c);
query.bindValue(":cause",cause);



   return  query.exec();}


QSqlQueryModel *  conges::afficher_ListeConge()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conges ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_deb"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_fin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("cin_emp"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom_emp"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email_emp"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("type_c"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("cause"));



    return model;

}
