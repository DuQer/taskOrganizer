#ifndef TASK_H
#define TASK_H

#include "qobject.h"

class Task : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool completed READ completed WRITE setCompleted NOTIFY completedChanged)

public:
    explicit Task(QObject *parent = nullptr);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    bool completed() const;
    void setCompleted(bool completed);

signals:
    void idChanged();
    void nameChanged();
    void descriptionChanged();
    void completedChanged();

private:
    int m_id;
    QString m_name;
    QString m_description;
    bool m_completed;
};

#endif // TASK_H
