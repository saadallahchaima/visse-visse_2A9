#include "demande_congee.h"
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
#include "employes.h"
#include "congee.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
using namespace std;
demande_congee::demande_congee()
{
nature_conges="";
nom_employes="";
num_tele_employes="";
fonction_employe="";
cin_employe="";
reponse="en attente";
cause="";
}
demande_congee::demande_congee( QString nature_conges,QString nom_employes,QString num_tele_employes,QDate date_depart_conge,QDate date_retour_conge,QString cin_employe,QString fonction_employe,QDate date_demande,QString reponse,QString cause)
{

    this->nature_conges=nature_conges;
    this->nom_employes=nom_employes;
    this->num_tele_employes=num_tele_employes;
    this->date_depart_conge=date_depart_conge;
    this->date_retour_conge=date_retour_conge;
    this->cin_employe=cin_employe;
    this->fonction_employe=fonction_employe;
    this->date_demande=date_demande;
    this->reponse=reponse;
    this->cause=cause;

}
bool demande_congee::ajouter_demande()
{
QSqlQuery query;


query.prepare("insert into demande_congee (nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause)""values (:nature_conges,:nom_employes,:num_tele_employes,:date_depart_conge,:date_retour_conge,:cin_employe,:fonction_employe,:date_demande,'en attente',:cause)");

query.bindValue(":nature_conges",nature_conges);
query.bindValue(":nom_employes",nom_employes);
query.bindValue(":num_tele_employes",num_tele_employes);
query.bindValue(":date_depart_conge",date_depart_conge);
query.bindValue(":date_retour_conge",date_retour_conge);
query.bindValue(":cin_employe",cin_employe);
query.bindValue(":fonction_employe",fonction_employe);
query.bindValue(":date_demande",date_demande);
query.bindValue("en attente",reponse);
query.bindValue(":cause",cause);

  return  query.exec();}

QSqlQueryModel * demande_congee::afficher_Listedemandes()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery(" select nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause from demande_congee ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nature_conges"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_employes"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("num_tele_employes"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_depart_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_retour_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cin_employe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fonction_employe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_demande"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("reponse"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cause"));




    return model;

}
bool demande_congee::supprimer_demande(QString cin_employe)
{
    QSqlQuery query;

    query.prepare("delete from demande_congee where cin_employe=:cin_employe");
    query.bindValue(":cin_employe",cin_employe);
    return  query.exec();
}

bool demande_congee::modifier_demande(QString, QString, QString, QDate, QDate,QString, QString, QDate,QString,QString)
{
    QSqlQuery query;


    query.prepare("update demande_congee set nature_conges=:nature_conges,nom_employes=:nom_employes,num_tele_employes=:num_tele_employes,date_depart_conge=:date_depart_conge,date_retour_conge=:date_retour_conge,cin_employe=:cin_employe,fonction_employe=:fonction_employe,date_demande=:date_demande,reponse='en attente',cause=:cause where cin_employe = :cin_employe");

    query.bindValue(":nature_conges",nature_conges);
    query.bindValue(":nom_employes",nom_employes);
    query.bindValue(":num_tele_employes",num_tele_employes);
    query.bindValue(":date_depart_conge",date_depart_conge);
    query.bindValue(":date_retour_conge",date_retour_conge);
    query.bindValue(":cin_employe",cin_employe);
    query.bindValue(":fonction_employe",fonction_employe);
    query.bindValue(":date_demande",date_demande);
    query.bindValue("en attente",reponse);
    query.bindValue(":cause",cause);

      return  query.exec();
}
bool demande_congee::modifier_autoriser(QString cin_employe,QString reponse)
{
    QSqlQuery query;
    query.prepare("update demande_congee set cin_employe=:cin_employe,reponse=:reponse where cin_employe=:cin_employe");
query.bindValue(":cin_employe",cin_employe);
    query.bindValue(":reponse",reponse);
     return  query.exec();

}
QSqlQueryModel * demande_congee::afficher_conge_refuses()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery(" select nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause from demande_congee where reponse='refuser'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nature_conges"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_employes"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("num_tele_employes"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_depart_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_retour_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cin_employe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fonction_employe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_demande"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("reponse"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cause"));
       return model;

}
QSqlQueryModel * demande_congee::afficher_conge_acceptes()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery(" select nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause from demande_congee where reponse='accepter'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nature_conges"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_employes"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("num_tele_employes"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_depart_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_retour_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cin_employe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fonction_employe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_demande"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("reponse"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cause"));
       return model;

}
QSqlQueryModel * demande_congee::trier_demande_acceptes_par_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause from demande_congee where reponse='accepter' ORDER BY date_retour_conge desc ;");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nature_conges"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_employes"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("num_tele_employes"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_depart_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_retour_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cin_employe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fonction_employe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_demande"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("reponse"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cause"));

    return model;
}
QSqlQueryModel * demande_congee::trier_date_demande()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT nature_conges,nom_employes,num_tele_employes,date_depart_conge,date_retour_conge,cin_employe,fonction_employe,date_demande,reponse,cause from demande_congee ORDER BY date_demande desc ;");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nature_conges"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_employes"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("num_tele_employes"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_depart_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_retour_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cin_employe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fonction_employe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date_demande"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("reponse"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cause"));

    return model;
}
void demande_congee::printPDF_demande()
{
    QDate date_demande =date_demande.currentDate() ;
     QString Dateee = date_demande.toString() ;
     QDate date_depart_conge =date_depart_conge.currentDate() ;
      QString Datee = date_depart_conge.toString() ;
      QDate date_retour_conge =date_retour_conge.currentDate() ;
       QString Dateeee = date_retour_conge.toString() ;

    QPdfWriter pdf("C:/Users/saada/OneDrive/Bureau/integration/print_demande.pdf");
    QPainter painter(&pdf);//fournit des fonctions hautement optimisées pour faire dessiner
    QFont font=painter.font();//la police utilisée pour dessiner le texte
    QMessageBox msgBox;
       font.setPointSize(font.pointSize() * 2);//taille en point de police
              painter.setFont(font);
              painter.setPen(Qt::red);
              painter.drawText(3000,800 , "Demande Conge ");
              painter.setPen(Qt::black);
              painter.drawText(300,1600,"Cin employe : ");
              painter.drawText(300,2200 , "Nom de l'employe : ");
              painter.drawText(300,2800,"Numero de Telephone : ");
              painter.drawText(300,3400, "Profession : ");
              painter.drawText(300, 4000, "Nature du conge : ");
              painter.drawText(300, 4600, "Cause : ");
              painter.drawText(300,5200,"Reponse : ");
              painter.drawText(300,5800,"date demande : ");
              painter.drawText(300,6200,"date depart conge : ");
              painter.drawText(300,6800,"date retour : ");
              painter.setPen(Qt::gray);
              painter.drawText(2000, 1600, this->cin_employe);
              painter.drawText(2600, 2200, this->nom_employes);
              painter.drawText(3200, 2800, this->num_tele_employes);
              painter.drawText(1800, 3400, this->fonction_employe);
              painter.drawText(2500, 4000, this->nature_conges);
              painter.drawText(1800, 4600, this->cause);
              painter.drawText(1800,5200,this->reponse);
              painter.drawText(2700,5800,Datee);
              painter.drawText(2700,6200,Dateee);
              painter.drawText(2300,6800,Dateeee);
              painter.end();
              msgBox.setIcon(QMessageBox::Information);
              msgBox.setText("A pdf has been created.");
              msgBox.exec();

}

