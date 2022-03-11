#ifndef DEMANDE_C_H
#define DEMANDE_C_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
#include"employes.h"
#include"conges.h"

class demande_C
{int id_employes,id_conge;
    QDate date_demande;
    QString cause;
public:
    demande_C();
    demande_C(int,int,QDate,QString);
    //Getters

int getid_employes(){return id_employes;}
QString getcause(){return  cause;}
QDate getdate_demande(){return date_demande;}
int getid_conge(){return  id_conge;}


//setters
void set_id_employe(int id_employes){this->id_employes=id_employes;}
void setcause(QString cause){this->cause=cause;}

void setdate_demande(QDate date_demande){this->date_demande=date_demande;}

void setsalaire(int id_conge){this->id_conge=id_conge;}

bool ajouter_demande();
bool supprimer_demande(int);
QSqlQueryModel * afficher_demande();
bool modifier_employe(int,int,QDate,QString);
bool controle_saisi_emp(demande_C);
};

#endif // DEMANDE_C_H
