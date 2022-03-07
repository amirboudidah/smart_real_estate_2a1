#include "connection.h"

connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test_bd");
db.setUserName("yessine");//inserer nom de l'utilisateur
db.setPassword("yessine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
