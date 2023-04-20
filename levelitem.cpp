#include "levelitem.h"

LevelItem::LevelItem() {

}

LevelItem::LevelItem(const int &x, const int &y, const QString &sprite, const int &rotate)
{
    this->x = x;
    this->y = y;
    this->sprite = sprite;
    this->rotate = rotate;
}

const QString& LevelItem::getSprite() const {
    return sprite;
}
