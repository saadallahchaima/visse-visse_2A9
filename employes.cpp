#include "employes.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
#include "qpainter.h"
#include <QPrinter>
#include<QPrintDialog>
#include <QPdfWriter>
#include<QMessageBox>
#include<qfile.h>
using namespace std;
employes::employes()
{
        cin="";
        nomprenom="";
        email="";
        adresse="";
        profession="";
        assurance="";

        nombre_enfants=0;
        cnss=0;
        nationnalite="";
        salaire=0;
        num_tele="";
}
employes::employes(QString cin ,QString nomprenom,QString email,QString adresse,QString profession,QString assurance,QDate date_entree,QDate naissance,int nombre_enfants,int cnss,QString nationnalite,int salaire,QString num_tele)
{
    this->cin=cin;
    this->nomprenom=nomprenom;
    this->email=email;
    this->adresse=adresse;
    this->profession=profession;
    this->assurance=assurance;
    this->date_entree=date_entree;
    this->naissance=naissance;
    this->nombre_enfants=nombre_enfants;
    this->cnss=cnss;
    this->nationnalite=nationnalite;
    this->salaire=salaire;
    this->num_tele=num_tele;

}
bool employes::ajouter_employe()
{
 QSqlQuery query;
 QString cnss_string = QString::number(cnss);
 QString nombre_enfants_string = QString::number(nombre_enfants);
 QString salaire_string = QString::number(salaire);

 query.prepare("insert into employes(cin,nomprenom,email,adresse,profession,assurance,date_entree,naissance,nombre_enfants,cnss,nationnalite,salaire,num_tele)""values (:cin,:nomprenom,:email,:adresse,:profession,:assurance,:date_entree,:naissance,:nombre_enfants,:cnss,:nationnalite,:salaire,:num_tele)");

query.bindValue(":cin",cin);
query.bindValue(":nomprenom",nomprenom);
query.bindValue(":email",email);
query.bindValue(":adresse",adresse);
query.bindValue(":profession",profession);
query.bindValue(":assurance",assurance);
query.bindValue(":date_entree",date_entree);
query.bindValue(":naissance",naissance);
query.bindValue(":nombre_enfants",nombre_enfants_string);
query.bindValue(":cnss",cnss_string);
query.bindValue(":nationnalite",nationnalite);
query.bindValue(":salaire",salaire_string);
query.bindValue(":num_tele",num_tele);


   return  query.exec();}


QSqlQueryModel *  employes::afficher_Listeemploye()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomprenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("profession"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("assurance"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date_entree"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("naissance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("nombre_enfants"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cnss"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("nationnalite"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("num_tele"));


    return model;

}
bool employes::supprimer_employe(QString cin)
{
    QSqlQuery query;
    query.prepare("delete from employes where cin=:cin");
    query.bindValue(":cin",cin);
    return  query.exec();
}

bool employes::modifier_employe(QString cin ,QString nomprenom,QString email,QString adresse,QString profession,QString assurance,QDate date_entree,QDate naissance,int nombre_enfants,int cnss,QString nationnalite,int salaire,QString num_tele)
{
    QSqlQuery query;
    QString cnss_string = QString::number(cnss);
    QString nombre_enfants_string = QString::number(nombre_enfants);
    QString salaire_string= QString::number(salaire);
    query.prepare("update employes set cin= :cin,nomprenom= :nomprenom,email= :email,adresse= :adresse,profession= :profession,assurance= :assurance,date_entree= :date_entree,naissance= :naissance,nombre_enfants= :nombre_enfants,cnss= :cnss,nationnalite= :nationnalite ,salaire= :salaire,num_tele=:num_tele where cin = :cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nomprenom",nomprenom);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":profession",profession);
    query.bindValue(":assurance",assurance);
    query.bindValue(":date_entree",date_entree);
    query.bindValue(":naissance",naissance);
    query.bindValue(":nombre_enfants",nombre_enfants_string);
    query.bindValue(":cnss",cnss_string);
    query.bindValue(":nationnalite",nationnalite);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":num_tele",num_tele);

    return query.exec();
}
bool employes::controle_saisi_emp(employes E)
{
  if((E.getcin()==0)||(E.getnomprenom()=="")||(E.getadresse()=="")||(E.getemail()=="")||(E.getassurance()=="")||(E.getprofession()=="")||(E.getcnss()==0)||(E.getnationnlaite()=="")||(E.getsalaire()==0))
      return true;
  else
      return false;
}

QSqlQueryModel * employes::rechercher_employes(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from employes where ( nomprenom='"+nom+"'OR profession='"+nom+"'OR assurance='"+nom+"' OR nationnalite='"+nom+"');");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomprenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("profession"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("assurance"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("date_entree"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("naissance"));
            model->setHeaderData(8,Qt::Horizontal,QObject::tr("nombre_enfants"));
            model->setHeaderData(9,Qt::Horizontal,QObject::tr("cnss"));
            model->setHeaderData(10,Qt::Horizontal,QObject::tr("salaire"));
            model->setHeaderData(11,Qt::Horizontal,QObject::tr("nationnalite"));
             model->setHeaderData(12,Qt::Horizontal,QObject::tr("num_tele"));
        return model ;
}

QSqlQueryModel * employes::trier_employes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM employes ORDER BY salaire desc ;");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomprenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("profession"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("assurance"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date_entree"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("naissance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("nombre_enfants"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cnss"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("nationnalite"));
     model->setHeaderData(12,Qt::Horizontal,QObject::tr("num_tele"));
    return model;
}
void employes::printPDF_employe()
{QPdfWriter pdf("C:/Users/saada/OneDrive/Bureau/gestion_des_employes/print_employe.pdf");
    QPainter painter(&pdf);
    QFont font=painter.font();
    QMessageBox msgBox;
    QString res1=QString::number(nombre_enfants);
      QString res2=QString::number(cnss);
        QString res3=QString::number(salaire);

       font.setPointSize(font.pointSize() * 2);
              painter.setFont(font);
              painter.setPen(Qt::red);
              painter.drawText(3000,800 , "Fiche d'employe ");
              painter.drawImage(QRect(7000, 900, 1000,1000), QImage(":/img/employe.png"));
              painter.setPen(Qt::black);
              painter.drawText(300,1600,"Cin employe : ");
              painter.drawText(300,2200 , "Nom de l'employe : ");
              painter.drawText(300,2800,"Numero de Telephone : ");
              painter.drawText(300,3400, "Profession : ");
              painter.drawText(300, 4000, "Nombre d'enfants : ");
              painter.drawText(300, 4600, "Num cnss : ");
              painter.drawText(300,5200,"Assurance : ");
              painter.drawText(300,5800,"salaire : ");
              painter.drawText(300,6400,"Nationnalité : ");
              painter.drawText(300,7000,"Adresse : ");
              painter.drawText(300,7600,"Email : ");

              painter.setPen(Qt::gray);
              painter.drawText(2000, 1600, this->cin);
              painter.drawText(2600, 2200, this->nomprenom);
              painter.drawText(3200, 2800, this->num_tele);
              painter.drawText(1800, 3400, this->profession);
              painter.drawText(2800, 4000, res1);
               painter.drawText(1800, 4600, res2);
              painter.drawText(1800,5200,this->assurance);
               painter.drawText(2000,5800,res3);
                painter.drawText(2000,6400,this->nationnalite);
                 painter.drawText(1800,7000,this->adresse);
                  painter.drawText(1800,7600,this->email);

              painter.end();
              msgBox.setIcon(QMessageBox::Information);
              msgBox.setText("A pdf has been created.");
              msgBox.exec();


}
void employes::background()
{

}
