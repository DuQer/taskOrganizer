#include "taskjsonmapper.h"
#include "src/task.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

TaskJSONMapper::TaskJSONMapper()
{

}

Task* TaskJSONMapper::InitializeTaskWithJsonData(QJsonObject jsonObject) {
    Task* task = new Task();

    task->setId(jsonObject["id"].toInt());
    task->setCompleted(jsonObject["completed"].toBool());
    task->setName(jsonObject["title"].toString());
    task->setDescription("some description"); // TODO: implement the description field in Task entity

    return task;
}

Task* TaskJSONMapper::FromJSON(QByteArray jsonData) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    qDebug() << "TEST";

    if (!jsonDoc.isNull()) {
        QJsonObject jsonObj = jsonDoc.object();
        return InitializeTaskWithJsonData(jsonObj);
    } else {
        qDebug() << "JSON data that is being processed is NULL";
    }

    return nullptr;
}
