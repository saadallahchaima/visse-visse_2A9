#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
using namespace std;
class Employees
{
private:
    QString nomprenom,naissance,adresse,profession,situation_familiale,assurance,date_entree,nationnalite,email;
int cin,cnss,nombre_enfants;
float salaire;
public:

//constructeur
    Employees(){}
    Employees(int,QString,QString,QString,QString,QString,QString,QString,QString,QString,int,int,float);

//Getters

       int getcin(){return cin;}
        QString getnomprenom(){return nomprenom;}
        QString getnaissance(){return naissance;}
        QString getadresse(){return  adresse;}
        QString getprofession(){return  profession;}
        QString getsituation_familiale(){return  situation_familiale;}
        int getcnss(){return  cnss;}
        QString getassurance(){return  assurance;}
        QString getdate_entree(){return  date_entree;}
       int getnombreenfants(){return  nombre_enfants;}
       float getsalaire(){return  salaire;}
        QString getnationnlaite(){return  nationnalite;}

        //setters
                void setcin(int cin){this->cin=cin;}
                void setnomprenom(QString nv_nomprenom){nv_nomprenom=nomprenom;}
                void setnaissance(QString nv_naissance){nv_naissance=naissance;}
                void setadresse(QString nv_adresse){nv_adresse=adresse;}
                void setprofession(QString nv_profession){nv_profession=profession;}
                void setsituation_familiale(QString nv_situation_familiale){nv_situation_familiale=profession;}
                void setcnss(int cnss){this->cnss=cnss;}
                void setassurance(QString nv_assurance){nv_assurance=assurance;}
                void setdate_entree(QString nv_date_entree){nv_date_entree=date_entree;}
                void setnombre_enfants(int nombre_enfants){this->nombre_enfants=nombre_enfants;}
                void setsalaire(float salaire){this->salaire=salaire;}
                void setnationnalite(QString nv_nationnalite){nv_nationnalite=nationnalite;}
                void setemail(QString nv_email){nv_email=email;}
//fonctionnalités de bases relatives à l'entité Etudiant
        bool ajouter_employe();
        bool supprimer_employe(int);
        QSqlQueryModel * afficher_Listeemploye();





};





#endif // EMPLOYEES_H
