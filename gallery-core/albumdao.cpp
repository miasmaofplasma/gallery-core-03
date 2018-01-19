#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

#include "databasemanager.h"
#include "album.h"


AlbumDao::AlbumDao(QSqlDatabase &database):
    mDatabase(database)
{

}

void AlbumDao::init() const
{
   if(!mDatabase.tables().contains("albums"))
   {
       QSqlQuery query(mDatabase);
       query.exec("CREATE TABLE albums (id INTEGER PRIMERY KEY AUTOINCREMENT, name TEXT)");
   }
}

void AlbumDao::addAlbum(Album &album) const
{
   QSqlQuery query(mDatabase);
   query.prepare("INSERT INTO albums (name) VALUES (:name)");
   query.bindValue(":name", album.name());
   query.exec();
   album.setId(query.lastInsertId().toInt());

}
