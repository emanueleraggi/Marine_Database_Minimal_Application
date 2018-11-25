#include "item.h"

Item::Item(const double dateTime,
           const QString &name, const QString &image,
           const QByteArray &imagesData)
{
    mName = name;
    mImage = image;
    mImagesData = imagesData;
    mDateTime = dateTime;
}
