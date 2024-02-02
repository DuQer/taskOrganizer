import QtQuick

Item {
    id: rightPanel
    width: parent.width * 0.75
    height: parent.height

    anchors.right: parent.right

    Rectangle {
        anchors.fill: parent
        color: "#FFE3B3"
    }

    // table view do wyświetlania tasków
    TaskTableView {
        width: rightPanel.width
        height: rightPanel.height
    }
}
