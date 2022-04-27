#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class FACTURE
{
public:
    int NUMFA,TELEPHONE,MONTANT,TOTAL;

    QString DATE_FACTURE,TYPE_FACTURE,TVA,DESCREPTION,EMAIL,TRANSPORT;
public:
    FACTURE();
    FACTURE(int,QString,QString,QString,QString,QString,int,int,QString,int);
    bool ajouterFA();
    QSqlQueryModel * afficherFA();
    bool modifierFA(int,QString,QString,QString,QString,QString,int,int,QString,int);
    QSqlQueryModel * afficheroncomboFA();
    QSqlQueryModel * rechercher_FA(QString Email);
     bool supprimerFA(QString);
     QSqlQueryModel* tri_FA(QString Choice);
     QSqlQueryModel *afficheroncombo_Mail_FA();
     void Statistique_Fa();




};

#endif // FACTURE_H
