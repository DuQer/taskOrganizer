#include "task.h"


int Task::id() const
{
    return m_id;
}

void Task::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
}

QString Task::name() const
{
    return m_name;
}

void Task::setName(const QString &name)
{
    if (m_name == name)
        return;

    m_name = name;
}

QString Task::description() const
{
    return m_description;
}

void Task::setDescription(const QString &description)
{
    if (m_description == description)
        return;

    m_description = description;
}

bool Task::completed() const
{
    return m_completed;
}

void Task::setCompleted(bool completed)
{
    if (m_completed == completed)
        return;

    m_completed = completed;
}
