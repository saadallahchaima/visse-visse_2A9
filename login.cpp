#include "login.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
#include "employes.h"
#include"vector"
login::login()
{
login_p="";
nom_et_prenom="";
type_utilisateur="";
}
login::login(QString login_p,QString nom_et_prenom,QString type_utilisateur)
{
    this->login_p=login_p;
    this->nom_et_prenom=nom_et_prenom;
    this->type_utilisateur=type_utilisateur;
}
  //getters
QString login::get_login(){return login_p;}
QString login::getnom_et_prenom(){return  nom_et_prenom;}
QString login::gettype_utilisateur(){return type_utilisateur;}

//setters

void login::setlogin(QString login_p){this->login_p=login_p;}
void login::setnom_et_prenom(QString nom_et_prenom){this->nom_et_prenom=nom_et_prenom;}
void login::set_type_utilisateur(QString type_utilisateur){this->type_utilisateur=type_utilisateur;}




