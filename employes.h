#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>

using namespace std;

class employes
{
   int nombre_enfants,cnss,salaire;
   QString nomprenom,email,adresse,profession,assurance,nationnalite,cin,num_tele;
   QDate date_entree,naissance;



public:

//constructeur
    employes();
employes(QString,QString,QString,QString,QString,QString,QDate,QDate,int,int,QString,int,QString);    //Getters

QString getcin(){return cin;}
QString getnomprenom(){return nomprenom;}
QString getemail(){return  email;}
QString getadresse(){return  adresse;}
QString getprofession(){return  profession;}
QString getassurance(){return  assurance;}
QDate getdate_entree(){return  date_entree;}
QDate getnaissance(){return naissance;}
int getnombreenfants(){return  nombre_enfants;}
int getcnss(){return  cnss;}
QString getnationnlaite(){return  nationnalite;}
int getsalaire(){return  salaire;}
QString getnum_tele(){return num_tele;}
//setters
void setcin(QString cin){this->cin=cin;}
void setnomprenom(QString nomprenom){this->nomprenom=nomprenom;}
void setemail(QString email){this->email=email;}
void setadresse(QString adresse){this->adresse=adresse;}
void setprofession(QString profession){this->profession=profession;}
void setassurance(QString assurance){this->assurance=assurance;}
void setdate_entree(QDate date_entree){this->date_entree=date_entree;}
void setnaissance(QDate naissance){this->naissance=naissance;}
void setnombre_enfants(int nombre_enfants){this->nombre_enfants=nombre_enfants;}
void setcnss(int cnss){this->cnss=cnss;}
void setnationnalite(QString nationnalite){this->nationnalite=nationnalite;}
void setsalaire(int salaire){this->salaire=salaire;}
void setnum_tele(QString num_tele){this->num_tele=num_tele;}
bool ajouter_employe();
bool supprimer_employe(QString);
QSqlQueryModel * afficher_Listeemploye();
bool modifier_employe(QString ,QString ,QString ,QString ,QString ,QString ,QDate,QDate ,int,int,QString,int,QString);
bool controle_saisi_emp(employes);
QSqlQueryModel * rechercher_employes(QString);
QSqlQueryModel * trier_employes();
bool controle_saisi_email(employes);
void printPDF_employe();

void background();
};

#endif // EMPLOYES_H
