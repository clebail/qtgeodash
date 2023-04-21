#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QtDebug>
#include "level.h"

Level::Level() {
    loaded = false;
}

Level::Level(const QString &fileName)
{
    QFile loadFile(fileName);

    loaded = false;

    if (loadFile.open(QIODevice::ReadOnly)) {
        QByteArray saveData = loadFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        loaded = read(loadDoc.object());

        loadFile.close();
        return;
    }

    qWarning("Couldn't open file.");
}

bool Level::read(const QJsonObject& json) {
    if (json.contains("size") && json["size"].isObject()) {
        QJsonObject jSize = json["size"].toObject();

        if(jSize.contains("width") && jSize.contains("height"))
        {
            size.setWidth(jSize["width"].toInt());
            size.setHeight(jSize["height"].toInt());

            if (json.contains("viewport") && json["viewport"].isObject()) {
                QJsonObject jViewport = json["viewport"].toObject();

                if(jViewport.contains("x") && jViewport.contains("y"))
                {
                    viewport.setX(jViewport["x"].toInt());
                    viewport.setY(jViewport["y"].toInt());

                    if (json.contains("start")) {
                        start = json["start"].toInt();

                        if (json.contains("scene") && json["scene"].isArray()) {
                            QJsonArray jScene = json["scene"].toArray();

                            for(auto i : jScene) {
                                if (i.isObject()) {
                                    QJsonObject item = i.toObject();
                                    QString key = QString("%1:%2").arg(item["x"].toInt()).arg(item["y"].toInt());

                                    items.insert(key, LevelItem(item["x"].toInt(), item["y"].toInt(), item["sprite"].toString(), item["rotate"].toInt()));
                                }
                            }

                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

const QSize& Level::getSize() const {
    return size;
}

const QPoint& Level::getViewport() const {
    return viewport;
}

const int& Level::getStart() const {
    return start;
}

bool Level::contains(const QString& key) const {
    return items.contains(key);
}

LevelItem Level::item(const QString& key) const {
    return items.value(key);
}
