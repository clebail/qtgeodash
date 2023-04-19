#include <QPainter>
#include "scenewidget.h"

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent) {

}

void SceneWidget::setLevel(const Level& level) {

}

void SceneWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setBrush(QBrush(QColor::fromRgb(224, 86, 253)));
    painter.drawRect(QRect(0, 0, size().width(), size().height()));
}
