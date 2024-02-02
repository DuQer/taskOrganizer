import QtQuick
import QtQuick.Controls.Basic
import QtQml.Models
import taskOrganizer
import TaskModel 1.0

Item {
    id: taskTableView
    anchors.fill: parent
    height: parent.height
    width: parent.width

    TaskModel {
        id: myModel

        // zbieranie danych na załadowanie komponentu
        Component.onCompleted: {
            myModel.fetchData();
        }
    }

    TableView {
        id: table

        height: parent.height
        width: parent.width

        anchors.fill: parent
        anchors.topMargin: header.height
        model: myModel
        columnSpacing: 10
        rowSpacing: 10
        boundsBehavior: Flickable.StopAtBounds

        rowHeightProvider:  function() {
            return 20;
        }

        columnWidthProvider: function(column) {
            return parent.width * 0.33
        }

        delegate: Rectangle {
            id: delegat

            required property bool selected
            required property int row
            required property int column
            required property string taskData
            property bool pooled: false

            color: selected ? "#c9bda7" : "#d1b37b"

            Text {
                font.pixelSize: 14
                text: delegat.taskData
                anchors.verticalCenter: delegat.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onEntered: {
                    delegat.color = "#aabbcc"; // Możesz dostosować ten kolor według potrzeb
                }

                onExited: {
                    delegat.color = selected ? "#c9bda7" : "#d1b37b";
                }
            }
        }

    }
}
