#include "connection.h"
#include "mainwindow.h"
#include <QSqlDatabase>
//test tutoriel Git

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("myBase");
db.setUserName("SYSTEM");//inserer nom de l'utilisateur
db.setPassword("chaima123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
