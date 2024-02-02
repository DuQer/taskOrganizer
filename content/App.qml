// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import taskOrganizer

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
                    myModel.addBook("Author " + i, "Title " + i, "Publisher " + i, + (1900 + i), "ISBN " + i);
            }
        }

    ListView {
            width: parent.width
            height: parent.height

            model: ListModel {
                ListElement { name: "Obiekt 1"; description: "Opis obiektu 1" }
                ListElement { name: "Obiekt 2"; description: "Opis obiektu 2" }
            }

            delegate: Item {
                width: ListView.view.width

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "lightblue"

                    Text {
                        anchors.centerIn: parent
                        text: model.name
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("Kliknięto na: " + model.name);
                        }
                    }

                }
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
                    text: "Task Information:\nName: " + "\nDescription: "  + "\nCompleted: "
                }
            }
    }

}

