#include "picture.h"


Picture::Picture(const QString &filePath) : Picture(QUrl::fromLocalFile(filePath))
{

}

Picture::Picture(const QUrl &fileUrl) :
    mId{-1},
    mAlbumId{-1},
    mFileUrl{fileUrl}
{

}

int Picture::id() const
{
    return mId;
}

int Picture::ambumId() const
{
    return mAlbumId;
}

QUrl Picture::fileUrl() const
{
    return mFileUrl;
}
