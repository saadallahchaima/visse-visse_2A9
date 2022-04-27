#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include <QPainter>
#include <QPdfWriter>
#include <QPrinter>
#include <QDesktopServices>
#include <QLabel>
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
     QSqlQueryModel* tri_Fo();
     void Generer_PDF();
};





#endif // FOURNISSEUR_H
