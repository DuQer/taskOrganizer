import QtQuick
import QtQuick.Controls

Item {
    width: 200
    height: 40

    CheckBox {
        id: myCheckBox
        anchors.centerIn: parent
        text: "Delete"
        property bool isChecked

        onClicked: {
            myCheckBox.isChecked = !myCheckBox.isChecked;
            console.log(myCheckBox.checked);
        }
    }
}
