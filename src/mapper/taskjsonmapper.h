#ifndef TASKJSONMAPPER_H
#define TASKJSONMAPPER_H

#include <QByteArray>
#include "src/task.h"

class TaskJSONMapper
{
public:
    TaskJSONMapper();
    Task* FromJSON(QByteArray jsonData);
    Task* InitializeTaskWithJsonData(QJsonObject jsonObject);
};

#endif // TASKJSONMAPPER_H
