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

    int numF,numFA,idpaiement;
    QString date_paiement,PAYMENT_VALIDATION,Total;

public:
    Paiement();
    Paiement(int,int,QString,QString,int,QString);

     bool ajouterP();
     QSqlQueryModel * afficherP();
     bool modifierP(QString,int);
     QSqlQueryModel * afficheroncomboP();
     QSqlQueryModel * afficheroncomboPT();
     QSqlQueryModel *  rechercherP(int);
     bool supprimerP(int);
     QSqlQueryModel* tri_Pa();
     void Statistique_Pa();


};

#endif // PAIEMENT_H
