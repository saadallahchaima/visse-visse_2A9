#include "congee.h"

congee::congee()
{
etat_congee="en attente";

}
congee::congee(QString etat_congee,QDate duree)
{
    this->etat_congee=etat_congee;
    this->duree=duree;
}
bool congee::ajouter_congee()
{
    QSqlQuery query;


    query.prepare("insert into congee (etat_congee,duree)""values (:etat_congee,:duree)");

    query.bindValue(":etat_conge",etat_congee);
    query.bindValue(":duree",duree);


      return  query.exec();
}
bool modifier_congee(QString etat_congee,QDate duree)
{
    QSqlQuery query;


    query.prepare("update congee set etat_congee=:etat_congee,duree=:duree where id_congee = :id_congee");

    query.bindValue(":etat_congee",etat_congee);
    query.bindValue(":duree",duree);


      return  query.exec();
}
bool supprimer_conge(int id_congee)
{
    QSqlQuery query;
    QString res=QString::number(id_congee);
    query.prepare("delete from congee where id_congee=:id_congee");
    query.bindValue(":id_congee",res);
    return  query.exec();
}

//QSqlQueryModel * afficher_Listeconges()
