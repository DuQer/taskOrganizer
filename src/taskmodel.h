#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QQmlEngine>
#include "task.h"

class TaskModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    int columnCount(const QModelIndex & parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void addTask(const QString &name, const int id, const bool completed);
    Q_INVOKABLE void fetchData();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Task> m_tasks;
};

#endif // TASKMODEL_H
