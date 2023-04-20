#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <level.h>

#define ITEM_WIDTH 32
#define ITEM_HEIGHT 32

class SceneWidget : public QWidget {
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);
    void setLevel(const Level& level);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Level level;
    int x;
    int y;

    void paintLevel(QPainter *painter) const;
};

#endif // SCENEWIDGET_H
