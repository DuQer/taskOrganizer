// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick
import QtQuick.Controls.Basic
import QtQml.Models
import taskOrganizer
import TaskModel 1.0

Window {
    visible: true
    width: 400
    height: 300
    title: qsTr("Task manager")
    color: "#26648E"

    TaskModel {
        id: myModel

        Component.onCompleted: {
            for (var i = 1; i <= 100; i++)
                myModel.addTask("name", "desc", false);
        }
    }

    TableView {
        id: table

        // qmlsc, if enabled, will output warnings on width/height provider
        rowHeightProvider:  function() {
            return 20;
        }
        columnWidthProvider: function(column) {
            switch(column) {
            case 3:
                return 80;
            case 4:
                return 180;
            default:
                return 280;
            }
        }

        anchors.fill: parent
        anchors.topMargin: header.height
        model: myModel
        columnSpacing: 5
        rowSpacing: 5
        boundsBehavior: Flickable.StopAtBounds

        //  To experiment with pooling, set reuseitems to true
        reuseItems: false

        delegate: Rectangle {
            id: dlg

            required property bool selected
            required property int row
            required property int column
            required property string taskData
            required property string newTaskData
            property bool pooled: false

            implicitWidth: 100
            implicitHeight: 20

            color: selected ? "blue" : "lightsteelblue"

            Text {
                font.pixelSize: 22
                text: dlg.taskData
                anchors.verticalCenter: dlg.verticalCenter
            }

            TableView.editDelegate: TextField {
                anchors.left: parent.left
                anchors.right: parent.right
                text: dlg.taskData
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                Component.onCompleted: selectAll()
                font.pixelSize: 8

                TableView.onCommit: {
                    newTaskData = text
                }
            }
        }

        selectionModel: ItemSelectionModel {
            model: table.model
        }
    }

    // prawy panel wyświetlający listę obiektów typu Task
    RightPanel {

        Rectangle {
            width: 200
            height: 100
            color: "lightblue"

            Text {
                            anchors.centerIn: parent
                            text: "Task Information:\nName: " + myModel.get(table.currentIndex.row, "name") +
                                  "\nDescription: " + myModel.get(table.currentIndex.row, "description") +
                                  "\nCompleted: " + myModel.get(table.currentIndex.row, "completed")
                        }
        }
    }

}

