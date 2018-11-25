#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(const double dateTime,
         const QString &name = "", const QString &image = "",
         const QByteArray &imagesData = QByteArray());
    QString name() const { return mName; }
    QString image() const { return mImage; }
    QByteArray imagesData() const { return mImagesData; }
    double dateTime() const { return mDateTime; }
private:
    QString mName;
    QString mImage;
    QByteArray mImagesData;
    double mDateTime;
};

#endif // ITEM_H
