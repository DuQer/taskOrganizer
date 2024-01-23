import QtQuick

Item {
    id: rightPanel
    width: parent.width * 3/4
    height: parent.height

    anchors.right: parent.right

    Rectangle {
        anchors.fill: parent
        color: "#FFE3B3"
    }
    CheckboxButton {
    }
    MouseArea {
    }
}
