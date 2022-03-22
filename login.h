#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
#include "employes.h"

using namespace std;

class login
{ QString login_p,nom_et_prenom,type_utilisateur;
public:

    login(QString,QString,QString);
      //getters
  QString get_login();
  QString getnom_et_prenom();
  QString gettype_utilisateur();

  //setters

  void setlogin(QString );
  void setnom_et_prenom(QString );
  void set_type_utilisateur(QString);

   //methodes
  bool ajouter_login();
  bool supprimer_Compte(QString);
  QSqlQueryModel * afficher_ListedesCompte();
  bool modifier_Compte(QString ,QString);

public:
    login();
};

#endif // LOGIN_H
