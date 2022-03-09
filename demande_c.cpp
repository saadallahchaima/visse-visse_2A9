#include "demande_c.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
using namespace std;
demande_C::demande_C()
{
id_employes=0;
id_conge=0;
cause="";

}
 demande_C::demande_C(int id_employes,int id_conge,QDate date_demande,QString cause)
 {
     this->id_employes=id_employes;
     this->id_conge=id_conge;
     this->date_demande=date_demande;
     this->cause=cause;

 }
 bool demande_C::ajouter_demande()
 {
  QSqlQuery query;
  QString res = QString::number(id_employes);
  QString res2 = QString::number(id_conge);


  query.prepare("insert into demande_C(id_employes,id_conge,date_demande,cause)""values (:id_employes,:id_conge,:date_demande,:cause)");

 query.bindValue(":id_employes",res);
 query.bindValue(":id_conge",res2);
 query.bindValue(":date_demande",date_demande);
 query.bindValue(":cause",cause);

    return  query.exec();
 }
