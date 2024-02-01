#ifndef TASKJSONMAPPER_H
#define TASKJSONMAPPER_H

#include <QByteArray>
#include "src/task.h"

class TaskJSONMapper
{
public:
    TaskJSONMapper();
    static Task* FromJSON(QByteArray jsonData);
    static QList<Task*> ListFromJSON(QByteArray jsonData);

private:
    static Task* InitializeTaskWithJsonData(QJsonObject jsonObject);
};

#endif // TASKJSONMAPPER_H
