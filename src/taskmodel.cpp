#include "taskmodel.h"
#include "task.h"

TaskModel::TaskModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

int TaskModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_tasks.count();
}

int TaskModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3; //  == number of attributes in task
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(role);
    Q_UNUSED(orientation);

    switch (section) {
    case 0:
        return "Name";
    case 1:
        return "Description";
    case 2:
        return "Completed";
    default:
        return QVariant();
    }
}

QVariant TaskModel::data(const QModelIndex & index, int role) const
{
    Q_UNUSED(role);

    if (index.row() < 0 || index.row() >= m_tasks.count())
        return QVariant();

    qDebug() << index.row();

    const Task &task = m_tasks[index.row()];
    switch (index.column()) {
    case 0:
        return task.name();
    case 1:
        return task.description();
    case 2:
        return task.completed();
    default:
        return QVariant();
    }
}

bool TaskModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool ret = false;

    if (index.row() >= 0 && index.row() < m_tasks.count())
    {
        Task &task = m_tasks[index.row()];
        switch (index.column()) {
        case 0:
            task.setName(value.toString());
            ret = true;
            break;
        case 1:
            task.setDescription(value.toString());
            ret = true;
            break;
        case 2:
            task.setCompleted(value.toBool());
            ret = true;
            break;

            if (ret)
            {
                emit dataChanged(index, index);
            }
        }

    }
    return ret;
}

Qt::ItemFlags TaskModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void TaskModel::addTask(const QString &name, const QString &description,
                        const bool completed)
{
    Task task;
    task.setName(name);
    task.setDescription(description);
    task.setCompleted(completed);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_tasks.append(task);
    endInsertRows();
}

QHash<int, QByteArray> TaskModel::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[Qt::DisplayRole] = "taskData";
    roles[Qt::EditRole] = "newtaskData";
    return roles;
}

