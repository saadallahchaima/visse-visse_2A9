#include "employes.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
using namespace std;
employes::employes()
{
        cin=0;
        nomprenom="";
        email="";
        adresse="";
        profession="";
        assurance="";

        nombre_enfants=0;
        cnss=0;
        nationnalite="";
        salaire=0;
}
employes::employes(int cin ,QString nomprenom,QString email,QString adresse,QString profession,QString assurance,QDate date_entree,QDate naissance,int nombre_enfants,int cnss,QString nationnalite,int salaire)
{
    this->cin=cin;
    this->nomprenom=nomprenom;
    this->email=email;
    this->adresse=adresse;
    this->profession=profession;
    this->assurance=assurance;
    this->date_entree=date_entree;
    this->naissance=naissance;
    this->nombre_enfants=nombre_enfants;
    this->cnss=cnss;
    this->nationnalite=nationnalite;
    this->salaire=salaire;

}
bool employes::ajouter_employe()
{
 QSqlQuery query;
 QString res = QString::number(cin);
 QString cnss_string = QString::number(cnss);
 QString nombre_enfants_string = QString::number(nombre_enfants);
 QString salaire_string = QString::number(salaire);

 query.prepare("insert into employes(cin,nomprenom,email,adresse,profession,assurance,date_entree,naissance,nombre_enfants,cnss,nationnalite,salaire)""values (:cin,:nomprenom,:email,:adresse,:profession,:assurance,:date_entree,:naissance,:nombre_enfants,:cnss,:nationnalite,:salaire)");

query.bindValue(":cin",res);
query.bindValue(":nomprenom",nomprenom);
query.bindValue(":email",email);
query.bindValue(":adresse",adresse);
query.bindValue(":profession",profession);
query.bindValue(":assurance",assurance);
query.bindValue(":date_entree",date_entree);
query.bindValue(":naissance",naissance);
query.bindValue(":nombre_enfants",nombre_enfants_string);
query.bindValue(":cnss",cnss_string);
query.bindValue(":nationnalite",nationnalite);
query.bindValue(":salaire",salaire_string);


   return  query.exec();}


QSqlQueryModel *  employes::afficher_Listeemploye()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomprenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("profession"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("assurance"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date_entree"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("naissance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("nombre_enfants"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cnss"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("nationnalite"));


    return model;

}
bool employes::supprimer_employe(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("delete from employes where Cin=:cin");
    query.bindValue(":cin",res);
    return  query.exec();
}

bool employes::modifier_employe(int cin ,QString nomprenom,QString email,QString adresse,QString profession,QString assurance,QDate date_entree,QDate naissance,int nombre_enfants,int cnss,QString nationnalite,int salaire)
{
    QSqlQuery query;
    QString res = QString::number(cin);
    QString cnss_string = QString::number(cnss);
    QString nombre_enfants_string = QString::number(nombre_enfants);
    QString salaire_string= QString::number(salaire);
    query.prepare("update employes set cin= :cin,nomprenom= :nomprenom,email= :email,adresse= :adresse,profession= :profession,assurance= :assurance,date_entree= :date_entree,naissance= :naissance,nombre_enfants= :nombre_enfants,cnss= :cnss,nationnalite= :nationnalite ,salaire= :salaire where cin = :cin");
    query.bindValue(":cin",res);
    query.bindValue(":nomprenom",nomprenom);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":profession",profession);
    query.bindValue(":assurance",assurance);
    query.bindValue(":date_entree",date_entree);
    query.bindValue(":naissance",naissance);
    query.bindValue(":nombre_enfants",nombre_enfants_string);
    query.bindValue(":cnss",cnss_string);
    query.bindValue(":nationnalite",nationnalite);
    query.bindValue(":salaire",salaire_string);

    return query.exec();
}
bool employes::controle_saisi_emp(employes E)
{
  if((E.getcin()==0)||(E.getnomprenom()=="")||(E.getadresse()=="")||(E.getemail()=="")||(E.getassurance()=="")||(E.getprofession()=="")||(E.getcnss()==0)||(E.getnationnlaite()=="")||(E.getsalaire()==0))
      return true;
  else
      return false;
}
QSqlQueryModel * employes::rechercher_employes(QString nomprenom )
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("SELECT * FROM employes WHERE( cin =  cin OR nomprenom='"+nomprenom+"'OR profession='"+profession+"'OR assurance='"+assurance+"' OR nationnalite='"+nationnalite+"')");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomprenom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("profession"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("assurance"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationnalite"));

        return model ;
}
QSqlQueryModel * employes::trier_employes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM employes ORDER BY salaire desc ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomprenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("profession"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationnalite"));
    return model;
}
