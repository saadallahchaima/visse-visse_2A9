#ifndef CONGES_H
#define CONGES_H
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>


class conges
{ int idC,cin_emp;
    QString nom_emp,email_emp,type_c,cause;
    QDate date_deb,date_fin;
public:
    conges(){}
    conges(int,QDate,QDate,int,QString,QString,QString,QString);
//getters
    int getidC(){return idC;}
    QString getnom_emp(){return nom_emp;}
    QString getemail_emp(){return  email_emp;}
    QString gettype_c(){return  type_c;}
    QString getCause(){return  cause;}

    QDate getdate_deb(){return  date_deb;}
    QDate getdate_fin(){return date_fin;}
    int getcin_emp(){return  cin_emp;}
    //setters
    void setidC(int idC){this->idC=idC;}
    void setnom_emp(QString nv_nom_emp){nv_nom_emp=nom_emp;}
    void setemail_emp(QString nv_email_emp){nv_email_emp=email_emp;}
    void settype_C(QString nv_type_c){nv_type_c=type_c;}
    void setcause(QString nv_cause){nv_cause=cause;}
    void setdate_deb( QDate nv_date_deb){nv_date_deb=date_deb;}
    void setdate_fin(QDate nv_date_fin){nv_date_fin=date_fin;}
    void setcin_emp(int cin_emp){this->cin_emp=cin_emp;}

    bool ajouter_conge();
    bool supprimer_conge(int);
    QSqlQueryModel * afficher_ListeConge();
    bool modifier_Conge(int,QDate,QDate,int,QString,QString,QString,QString);
    bool controle_saisi_emp(conges);

};

#endif // CONGES_H
