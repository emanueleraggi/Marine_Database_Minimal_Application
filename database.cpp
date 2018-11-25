#include "database.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#define CREATE_TABLE \
     " CREATE TABLE IF NOT EXISTS Fish_Table" \
     " (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
     ", name TEXT NOT NULL" \
     ", image TEXT NOT NULL" \
     ", dataDataBase BLOB NOT NULL" \
     ", dateTime DOUBLE NOT NULL)"

dataBase::dataBase(QObject *parent)
    : QObject(parent)
{
}

bool dataBase::inizializationDataBase(const QString &nameDataBase) {
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName(nameDataBase);
    bool ok = mDatabase.open();
    if (!ok) {
        mError = mDatabase.lastError().text();
    }
    return ok;
}

bool dataBase::configureDataBase() {
    QSqlQuery q;
    bool ok = q.exec(CREATE_TABLE);
    if (!ok) {
        mError = q.lastError().text();
    }
    return ok;
}

bool dataBase::addItem(const Item &item) {
    QSqlQuery q;
    q.prepare("INSERT INTO Fish_Table (name, image, dataDatabase, dateTime) VALUES (?,?,?,?)");
    q.addBindValue(item.name());
    q.addBindValue(item.image());
    q.addBindValue(item.imagesData());
    q.addBindValue(item.dateTime());
    bool ok = q.exec();
    if (!ok) {
        mError = q.lastError().text();
    }
    return ok;
}

















