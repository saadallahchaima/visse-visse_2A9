#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
    int telF,numF;
    QString nomF,prenF,addF,typeF;

public:
    Fournisseur();
    Fournisseur(int,QString,QString,QString,int,QString);

     bool ajouter();
     QSqlQueryModel * afficher();
     bool modifier(int,QString,QString,QString,int,QString);
     QSqlQueryModel * afficheroncombo();
     bool  rechercher(int id  );
     bool supprimer(int);
     QSqlQueryModel* recherche(QString Nom);
};





#endif // FOURNISSEUR_H
