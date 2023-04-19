#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QJsonObject>

class Level
{
public:
    Level(const QString& fileName);
private:
    bool loaded;
    int width;
    int height;

    bool read(const QJsonObject& json);
};

#endif // LEVEL_H
