#ifndef DEMANDE_CONGE_H
#define DEMANDE_CONGE_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
#include "employes.h"

using namespace std;
class demande_congee
{
    QString nature_conges,nom_employes,fonction_employe,reponse,cause ,num_tele_employes,cin_employe;
    QDate date_depart_conge,date_retour_conge,date_demande;

public:
    demande_congee();
    demande_congee(QString ,QString ,QString,QDate ,QDate ,QString ,QString,QDate,QString,QString);

        QString getcin_employes(){return cin_employe;}
    QString getnature_conge(){return nature_conges;}
    QString getnom_employe(){return  nom_employes;}
    QString getfonction_employe(){return  fonction_employe;}
    QDate getdate_depart_conge(){return  date_depart_conge;}
    QDate getdate_retour_conge(){return date_retour_conge;}
   QString getnum_tele_employes(){return  num_tele_employes;}
    QDate getdate_demande(){return date_demande;}
     QString getreponse(){return  reponse;}
      QString getcause(){return  cause;}
    //setters

    void setcode_cin_employes(QString cin_employe){this->cin_employe=cin_employe;}
    void setnature_conge(QString nature_conges){this->nature_conges=nature_conges;}
    void setnom_employe(QString nom_employes){this->nom_employes=nom_employes;}
    void setfonction_employe(QString fonction_employe){this->fonction_employe=fonction_employe;}
    void setdate_depart_conge(QDate date_depart_conge){this->date_depart_conge=date_depart_conge;}
    void setdate_retour_conge(QDate date_retour_conge){this->date_retour_conge=date_retour_conge;}
    void setnum_tele_employes(QString num_tele_employes){this->num_tele_employes=num_tele_employes;}
     void setdate_demande(QDate date_demande){this->date_demande=date_demande;}
     void setreponse(QString reponse){this->reponse=reponse;}
     void setcause(QString cause){this->cause=cause;}
    //Methodes
    bool ajouter_demande();
    bool supprimer_demande(QString);
    QSqlQueryModel * afficher_Listedemandes();
    bool modifier_demande(QString ,QString ,QString,QDate ,QDate ,QString,QString ,QDate,QString,QString);
     bool modifier_autoriser(QString,QString);
       QSqlQueryModel * afficher_conge_refuses();
       QSqlQueryModel * afficher_conge_acceptes();
       QSqlQueryModel * trier_date_demande();
        QSqlQueryModel *trier_demande_acceptes_par_date();
       void printPDF_demande();

};

#endif // DEMANDE_CONGE_H
