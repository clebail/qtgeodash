#include <QFile>
#include <QJsonDocument>
#include <QtDebug>
#include "level.h"

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
        QJsonObject size = json["size"].toObject();

        if(size.contains("width") && size.contains("height"))
        {
            width = size["width"].toInt();
            height = size["height"].toInt();

            return true;
        }
    }

    return false;
}
