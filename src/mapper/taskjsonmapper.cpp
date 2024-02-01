#include "taskjsonmapper.h"
#include "src/task.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

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

    if(jsonDoc.isNull()) {
        qDebug() << "JSON data that is being processed is NULL";
        return nullptr;
    }

    QJsonObject jsonObj = jsonDoc.object();
    return InitializeTaskWithJsonData(jsonObj);
}

QList<Task*> TaskJSONMapper::ListFromJSON(QByteArray jsonData) {
    QList<Task*> tasks;

    QJsonDocument jsonDocuments = QJsonDocument::fromJson(jsonData);

    if(jsonDocuments.isNull()) {
        qDebug() << "JSON data that is being processed is NULL";
        return tasks;
    }

    if(jsonDocuments.isArray()) {
        QJsonArray jsonArray = jsonDocuments.array();
        for(const QJsonValue &value : jsonArray) {
            QJsonObject jsonObj = value.toObject();
            Task* task = InitializeTaskWithJsonData(jsonObj);
            tasks.append(task);
        }
    }

    return tasks;
}
