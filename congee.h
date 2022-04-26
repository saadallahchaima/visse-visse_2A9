#ifndef CONGEE_H
#define CONGEE_H

#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
#include "demande_congee.h"
class congee
{ QString etat_congee;
    QDate duree;
public:
    congee();
    congee(QString,QDate);
    QString getetat_congee(){return etat_congee;}
    QDate getduree(){return  duree;}
    void setetat(QString etat_conge){this->etat_congee=etat_conge;}
    void setduree(QDate duree){this->duree=duree;}
    bool ajouter_congee();
    bool modifier_congee(QString,QDate);
    bool supprimer_conge(int);
    QSqlQueryModel * afficher_Listeconges();

};

#endif // CONGEE_H
