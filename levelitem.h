#ifndef LEVELITEM_H
#define LEVELITEM_H

#include <QString>

class LevelItem
{
public:
    LevelItem();
    LevelItem(const int& x, const int &y, const QString& sprite, const int& rotate);

    const QString& getSprite() const;
private:
    int x;
    int y;
    QString sprite;
    int rotate;
};

#endif // LEVELITEM_H
