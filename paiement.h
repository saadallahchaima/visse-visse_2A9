#ifndef PAIEMENT_H
#define PAIEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlRecord>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
class Paiement
{
public:

    int numF,numFA,Total,idpaiement;
    QString date_paiement;

public:
    Paiement();
    Paiement(int,int,int,QString,int);

     bool ajouterP();
     QSqlQueryModel * afficherP();
     bool modifierP(int,int,int,QString,int);
     QSqlQueryModel * afficheroncomboP();
     QSqlQueryModel * afficheroncomboPT();
     QSqlQueryModel *  rechercherP(int);
     bool supprimerP(int);
};

#endif // PAIEMENT_H
