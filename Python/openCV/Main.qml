import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    visible: true
    width: 400
    height: 600
    color: "teal"
    title: "Lomunyak Application Window"

    Rectangle {
        id: mainPanel

        anchors.fill: parent
        anchors.margins: 10
        radius: 12
        color: "grey"

        Rectangle {
            id: startBox

            width: 50
            height: 50
            color: "maroon"

            anchors.centerIn: parent

            Text {
                id: heading

                text: "Lomunyak Isaya"
            }

            Button {
                id: startsys

                text: "START"
            }
        }
    }
}
