#include "databasemanager.h"
#include <QSqlDatabase>

DatabaseManager &DatabaseManager::instance()
{
   static DatabaseManager singleton;
   return singleton;
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete mDatabase;
}

DatabaseManager::DatabaseManager(const QString &path):
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
}

DatabaseManager &DatabaseManager::operator=(const DatabaseManager &rhs)
{

}
