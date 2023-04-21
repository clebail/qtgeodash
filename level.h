#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QJsonObject>
#include <QSize>
#include <QPoint>
#include "levelitem.h"

class Level
{
public:
    Level();
    Level(const QString& fileName);

    const QSize& getSize() const;
    const QPoint& getViewport() const;
    const int& getStart() const;
    bool contains(const QString& key) const;
    LevelItem item(const QString& key) const;
private:
    bool loaded;
    QSize size;
    QPoint viewport;
    int start;
    QMap<QString, LevelItem> items;

    bool read(const QJsonObject& json);
};

#endif // LEVEL_H
