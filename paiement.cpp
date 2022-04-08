#include "paiement.h"
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QApplication>
#include <QMainWindow>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include"QSortFilterProxyModel"
#include <QTextBrowser>
#include<QMessageBox>
#include<QDate>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QSqlRecord>
#include<QMessageBox>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QTextStream>
#include<QFileInfo>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include<QTextCursor>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPieSlice>
#include <QPieSeries>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include"QSortFilterProxyModel"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


Paiement::Paiement()
{

}
Paiement::Paiement(int  numF,int  numFA,QString  Total,QString date_paiement,int idpaiement,QString PAYMENT_VALIDATION)
{
this->numF=numF;
    this->numFA=numFA;
    this->Total=Total;
    this->date_paiement=date_paiement;
    this->idpaiement=idpaiement;
    this->PAYMENT_VALIDATION=PAYMENT_VALIDATION;

}
QSqlQueryModel * Paiement ::afficheroncomboP()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMF"));

        return model;
}

bool Paiement::ajouterP()
{

    QSqlQuery query;
        query.prepare("INSERT INTO paiement (numF,numFA,Total,date_paiement,idpaiement,PAYMENT_VALIDATION) "
                            "VALUES (:NUMF, :NUMFA, :TOTAL,:date_paiement ,:idpaiement,:PAYMENT_VALIDATION)");
        query.bindValue(":NUMF",numF);
        query.bindValue(":NUMFA",numFA);
        query.bindValue(":TOTAL",Total);
        query.bindValue(":date_paiement",date_paiement);
        query.bindValue(":idpaiement",idpaiement);
        query.bindValue(":PAYMENT_VALIDATION",PAYMENT_VALIDATION);


        return    query.exec();
}
QSqlQueryModel * Paiement ::afficherP()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *FROM PAIEMENT INNER JOIN FOURNISSEUR ON paiement.numF = FOURNISSEUR.NUMF");

        return model;
}

bool Paiement ::supprimerP(int idd)
{
    QString ident2= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from PAIEMENT where idpaiement = :idpaiement");
    query.bindValue(":idpaiement",ident2);
    return    query.exec();

}


QSqlQueryModel * Paiement ::afficheroncomboPT() //combo ID
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idpaiement from PAIEMENT");
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("idpaiement"));

        return model;
}

bool Paiement::modifierP( QString date_paiement, int idpaiement)
{
    QString PAYMENT_VALIDATION ="Verified";
    QSqlQuery query;

    query.prepare("UPDATE PAIEMENT SET date_paiement= :date_paiement , PAYMENT_VALIDATION =:PAYMENT_VALIDATION   where idpaiement= :idpaiement ");

    query.bindValue(":date_paiement", date_paiement);
    query.bindValue(":idpaiement", idpaiement);
    query.bindValue(":PAYMENT_VALIDATION",PAYMENT_VALIDATION);
return    query.exec();

}

QSqlQueryModel * Paiement ::rechercherP(int ID)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM PAIEMENT WHERE idpaiement= :idpaiement");
    query.bindValue(":idpaiement",ID);
    query.exec();
    model->setQuery(query);

    return model;
}

QSqlQueryModel* Paiement ::tri_Pa()
{
    QSqlQueryModel* Tri_Pa_model=new QSqlQueryModel();

    Tri_Pa_model->setQuery("SELECT* FROM PAIEMENT ORDER BY idpaiement DESC ");
    Tri_Pa_model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMFA"));
    Tri_Pa_model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total"));
    Tri_Pa_model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_paiement"));
    Tri_Pa_model->setHeaderData(0, Qt::Horizontal, QObject::tr("idpaiement"));
    Tri_Pa_model->setHeaderData(1, Qt::Horizontal, QObject::tr("numF"));
    return Tri_Pa_model;


}
void Paiement :: Statistique_Pa()
{

int exp1=0 ;
    QPieSeries *series = new QPieSeries();
        QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from PAIEMENT where Total < 2000 ");
                 exp1=model->rowCount();
                 exp1=exp1;
                model->setQuery("select * from PAIEMENT where Total between 2000 and 10000 ");
                int exp2=model->rowCount();
                model->setQuery("select * from PAIEMENT where Total > 10000 ");
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
                chart->setTitle("Nombre des Paiements :  "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(2000,750);
                chartView->show();


}
