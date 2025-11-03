import QtQuick

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 50
        y: 50
        height: 100
        width: 100
        color: "lightblue"
        radius: 10
        focus: true

        Text {
            text: qsTr("Click me...")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: parent.rotation += 10
        }

        Keys.onLeftPressed: x -= 50
        Keys.onRightPressed: x += 50
        Keys.onUpPressed: y -= 50
        Keys.onDownPressed: y += 50

        Behavior on x {
            NumberAnimation {
                duration: 200
                easing.type: Easing.OutElastic
            }
        }

        Behavior on y {
            NumberAnimation {
                duration: 200
                easing.type: Easing.OutElastic
            }
        }
    }
}
