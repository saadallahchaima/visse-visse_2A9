#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include "facture.h"
#include<QSqlRecord>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QTextStream>
#include<QFileInfo>
#include<QPrinter>
#include<QFileDialog>
#include<QDate>
#include<QTextDocument>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

FACTURE::FACTURE(){}
FACTURE::FACTURE(int NUMFA,QString DATE_FACTURE ,QString TYPE_FACTURE,QString TVA ,QString DESCREPTION ,QString EMAIL ,int MONTANT ,int TELEPHONE,QString TRANSPORT ,int TOTAL)
{
    this->NUMFA=NUMFA;
    this->DATE_FACTURE=DATE_FACTURE;
    this->TYPE_FACTURE=TYPE_FACTURE;
    this->TVA=TVA;
    this->DESCREPTION=DESCREPTION;
    this->EMAIL=EMAIL;
    this->MONTANT=MONTANT;
    this->TELEPHONE=TELEPHONE;
    this->TRANSPORT=TRANSPORT;
    this->TOTAL=TOTAL;
}
bool FACTURE::ajouterFA()
{
QSqlQuery query;


    query.prepare("INSERT INTO FACTURE (NUMFA,DATE_FACTURE,TYPE_FACTURE,TVA,DESCREPTION,EMAIL,MONTANT,TELEPHONE,TRANSPORT ,TOTAL) "
                        "VALUES (:NUMFA, :DATE_FACTURE, :TYPE_FACTURE, :TVA, :DESCREPTION, :EMAIL, :MONTANT, :TELEPHONE, :TRANSPORT, :TOTAL)");
    query.bindValue(":NUMFA",NUMFA);
    query.bindValue(":DATE_FACTURE",DATE_FACTURE);
    query.bindValue(":TYPE_FACTURE",TYPE_FACTURE);
    query.bindValue(":TVA",TVA);
    query.bindValue(":DESCREPTION",DESCREPTION);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":MONTANT",MONTANT);
    query.bindValue(":TELEPHONE",TELEPHONE);
    query.bindValue(":TRANSPORT",TRANSPORT);
    query.bindValue(":TOTAL",TOTAL);
return    query.exec();
}
QSqlQueryModel * FACTURE ::afficherFA()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURE ");

        return model;
}


bool FACTURE::modifierFA(int NUMFA, QString DATE_FACTURE , QString TYPE_FACTURE , QString TVA ,QString DESCREPTION ,QString EMAIL ,int  MONTANT, int TELEPHONE , QString TRANSPORT , int TOTAL )

{
     QSqlQuery query;

    query.prepare("UPDATE FACTURE SET  DATE_FACTURE= :DATE_FACTURE, TYPE_FACTURE = :TYPE_FACTURE  , TVA = :TVA  , DESCREPTION= :DESCREPTION,EMAIL= :EMAIL,MONTANT= :MONTANT, TELEPHONE= :TELEPHONE,TRANSPORT= :TRANSPORT,TOTAL= :TOTAL where NUMFA= :NUMFA ");
    query.bindValue(":NUMFA", NUMFA);
    query.bindValue(":DATE_FACTURE", DATE_FACTURE);
    query.bindValue(":TYPE_FACTURE",TYPE_FACTURE);
    query.bindValue(":TVA", TVA);
    query.bindValue(":DESCREPTION", DESCREPTION);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":MONTANT", MONTANT);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":TRANSPORT",TRANSPORT);
    query.bindValue(":TOTAL",TOTAL);
            return    query.exec();

}

bool FACTURE::supprimerFA(QString IDD)
{

    QSqlQuery query;
    query.prepare("Delete from FACTURE where NUMFA = :NUMFA ");
    query.bindValue(":NUMFA",IDD);
    return    query.exec();

}

QSqlQueryModel * FACTURE ::rechercher_FA(QString Email)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM FACTURE WHERE EMAIL=:EMAIL   ");
    query.bindValue(":EMAIL",Email);
    query.exec();

    model->setQuery(query);

    return model;
}

QSqlQueryModel * FACTURE::afficheroncomboFA() //combo supprimer
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select NUMFA  from FACTURE");
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMFA"));

        return model;
}

QSqlQueryModel* FACTURE ::tri_FA(QString Choice)
{
    QSqlQueryModel* model=new QSqlQueryModel();
if (Choice =="A-Z")
{
    model->setQuery("SELECT* FROM FACTURE ORDER BY EMAIL ASC");
}
else if (Choice =="Z-A")
{
    model->setQuery("SELECT* FROM FACTURE ORDER BY EMAIL DESC");
}
else if (Choice =="Montant ^")
{
    model->setQuery("SELECT* FROM FACTURE ORDER BY MONTANT ASC");
}
else
{
    model->setQuery("SELECT* FROM FACTURE ORDER BY MONTANT DESC");
}

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMFA"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FACTURE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FACTURE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TVA"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCREPTION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TRANSPORT"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("TOTAL"));
    return model;
}

QSqlQueryModel * FACTURE::afficheroncombo_Mail_FA() //combo generer
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT EMAIL FROM FACTURE  ");
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));

        return model;
}



void FACTURE::Statistique_Fa()
{

    int exp1=0 ;
        QPieSeries *series = new QPieSeries();
            QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from FACTURE where Total < 2000 ");
                     exp1=model->rowCount();
                     exp1=exp1;
                    model->setQuery("select * from FACTURE where Total between 2000 and 10000 ");
                    int exp2=model->rowCount();
                    model->setQuery("select * from FACTURE where Total > 10000 ");
                    int exp3=model->rowCount();
                    float total=exp1+exp2+exp3;
                    QString a=QString("  moins de 2000   " + QString::number((exp1*100)/total,'f',2)+"%" );
                    QString b=QString("entre 2000 et 10000    " + QString::number((exp2*100)/total,'f',2)+"%" );
                    QString c=QString("plus de 10000    " + QString::number((exp3*100)/total,'f',2)+"%" );

                    series->append(a,exp1);
                    series->append(b,exp2);
                     series->append(c,exp3);
            if (exp1!=0)
            {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
            if ( exp2!=0)
            {
                     // Add label, explode and define brush for 2nd slice
                     QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded(); Explode the Slice
                     slice1->setLabelVisible();
            }
            if(exp3!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice2 = series->slices().at(2);
                     slice2->setLabelVisible();
            }
                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Nombre des Factures :  "+ QString::number(total));
                    chart->legend()->hide();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(2000,750);
                    chartView->show();
}
