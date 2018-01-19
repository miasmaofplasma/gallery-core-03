#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "gallery-core_global.h"
#include "albumdao.h"
#include <QString>

class QSqlDatabase;
const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
     ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* mDatabase;

public:
    const AlbumDao albumDao;

};

#endif // DATABASEMANAGER_H
