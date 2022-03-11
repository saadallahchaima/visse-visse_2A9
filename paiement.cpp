#include "paiement.h"

Paiement::Paiement()
{

}
Paiement::Paiement(int  numF,int  numFA,int  Total,QString date_paiement,int idpaiement)
{
this->numF=numF;
    this->numFA=numFA;
    this->Total=Total;
    this->date_paiement=date_paiement;
    this->idpaiement=idpaiement;

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
        //QString id= QString::number(ID);
        query.prepare("INSERT INTO paiement (numF,numFA,Total,date_paiement,idpaiement) "
                            "VALUES (:NUMF, :NUMFA, :TOTAL,:date_paiement ,:idpaiement)");
        query.bindValue(":NUMF",numF);
        query.bindValue(":NUMFA",numFA);
        query.bindValue(":TOTAL",Total);
        query.bindValue(":date_paiement",date_paiement);
        query.bindValue(":idpaiement",idpaiement);



        return    query.exec();
}
QSqlQueryModel * Paiement ::afficherP()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PAIEMENT INNER JOIN FOURNISSEUR ON paiement.NUMF = FOURNISSEUR.NUMF");

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

bool Paiement::modifierP(int numF, int numFA, int Total, QString date_paiement, int idpaiement)
{

    QSqlQuery query;

    query.prepare("UPDATE PAIEMENT SET numF= :NUMF, numFA= :NUMFA , Total= :TOTAL , date_paiement= :date_paiement   where idpaiement= :idpaiement ");
    query.bindValue(":NUMF", numF);
    query.bindValue(":NUMFA", numFA);
    query.bindValue(":TOTAL", Total);
    query.bindValue(":date_paiement", date_paiement);
    query.bindValue(":idpaiement", idpaiement);
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

