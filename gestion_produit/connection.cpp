#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Nextech");
db.setUserName("Anis");//inserer nom de l'utilisateur
db.setPassword("tassoutassou53");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
