#include <QPainter>
#include "scenewidget.h"

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent) {

}

void SceneWidget::setLevel(const Level& level) {
    this->level = level;
    reset();
}

void SceneWidget::incX() {
    x+=10;
    repaint();
}

void SceneWidget::reset() {
    this->x = level.getViewport().x() * ITEM_WIDTH;
    this->y = level.getViewport().y() * ITEM_HEIGHT;

    repaint();
}

void SceneWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setBrush(QBrush(QColor::fromRgb(224, 86, 253)));
    painter.drawRect(QRect(0, 0, size().width(), size().height()));

    paintLevel(&painter);
}

void SceneWidget::paintLevel(QPainter *painter) const {
    int xScreen, yScreen;
    int xLevel, yLevel;
    int xStart = x / ITEM_WIDTH;
    int yStart = y / ITEM_HEIGHT;
    int offsetX = x % ITEM_WIDTH;
    int offsetY = y % ITEM_HEIGHT;

    for(xScreen=0, xLevel = xStart;xScreen<width();xLevel++) {
        for(yScreen=height()-ITEM_HEIGHT, yLevel = yStart;yScreen>=0;yLevel--) {
            if(xLevel < level.getSize().width() && yLevel >=0 && yLevel < level.getSize().height()) {
                QString key = QString("%1:%2").arg(xLevel).arg(yLevel);

                if(level.contains(key)) {
                    LevelItem li = level.item(key);

                    painter->drawImage(xScreen, yScreen, QImage(QStringLiteral(":/images/") + li.getSprite()), offsetX, offsetY, 0, 0);
                }               
            }
            yScreen-=ITEM_HEIGHT-offsetY;
            offsetY=0;
        }
        xScreen+=ITEM_WIDTH-offsetX;
        offsetX=0;
    }
}
