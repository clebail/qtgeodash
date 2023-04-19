#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <level.h>

class SceneWidget : public QWidget {
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);
    void setLevel(const Level& level);

protected:
    virtual void paintEvent(QPaintEvent *);

};

#endif // SCENEWIDGET_H
