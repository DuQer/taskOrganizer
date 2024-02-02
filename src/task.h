#ifndef TASK_H
#define TASK_H

#include "qobject.h"

class Task
{

public:
    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    bool completed() const;
    void setCompleted(bool completed);

private:
    int m_id;
    QString m_name;
    QString m_description;
    bool m_completed;
};

#endif // TASK_H
