#include <QPainter>
#include "scenewidget.h"

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent) {

}

void SceneWidget::setLevel(const Level& level) {
    this->level = level;
    this->x = level.getViewport().x();
    this->y = level.getViewport().y();

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
    int xLevel = x, yLevel = y;

    for(xScreen=0;xScreen<width();xScreen+=ITEM_WIDTH, xLevel++) {
        for(yScreen=height()-ITEM_HEIGHT;yScreen>=0;yScreen-=ITEM_HEIGHT, yLevel--) {
            if(xLevel < level.getSize().width() && yLevel >=0 && yLevel < level.getSize().height()) {
                QString key = QString("%1:%2").arg(xLevel).arg(yLevel);
                qDebug() << key;
                if(level.contains(key)) {
                    LevelItem li = level.item(key);

                    painter->drawImage(QPoint(xScreen, yScreen), QImage(QStringLiteral(":/images/") + li.getSprite()));
                }
            }
        }
    }
}
