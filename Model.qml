import QtQuick 2.15

ListModel {
    id: taskModel

    ListElement {
        taskId: -1
        user_id: -1
        title: ""
        description: ""
        creation_time: new Date()
        due_date: new Date()
        priority: 0
    }

    function addTask(newTask) {
        var task = {
            id: generateUniqueId(),
            user_id: -1,
            title: newTask.title || "",
            description: newTask.description || "",
            creation_time: new Date(),
            due_date: newTask.due_date || new Date(),
            priority: newTask.priority || 0
        };

        taskModel.append(task);
    }

    function editTask(index, newTask) {
        var task = get(index);
        if (task) {
            task.title = newTask.title || task.title;
            task.description = newTask.description || task.description;
            task.due_date = newTask.due_date || task.due_date;
            task.priority = newTask.priority || task.priority;
        }
    }

    function removeTask(index) {

        taskModel.remove(index);
    }

    function generateUniqueId() {
    }
}
