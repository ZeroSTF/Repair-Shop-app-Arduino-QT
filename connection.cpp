#include "connection.h"

Connection::Connection()
{
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("ZeroS");
db.setPassword("ZeroS");

if (db.open())
test=true;
    return  test;
}

void Connection::closeConnection()
{
    db.close();
}
