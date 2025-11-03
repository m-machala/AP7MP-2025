import QtQuick

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property int clickCount: 0
    property int moveInterval: 1500
    property int moveSpeedup: 50

    Text {
        text: "Click count: " + mainWindow.clickCount
        anchors.top: parent.top
        anchors.left: parent.left
    }

    Rectangle {
        id: rectangle
        x: 50
        y: 50
        height: 100
        width: 100
        color: "lightblue"
        radius: 10

        Text {
            text: qsTr("Click me...")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var newSpeed = mainWindow.moveInterval - mainWindow.moveSpeedup
                if (newSpeed > 0) {
                    mainWindow.moveInterval -= 100
                }

                var maxX = mainWindow.width - parent.width
                var maxY = mainWindow.height - parent.height

                parent.x = Math.random() * maxX
                parent.y = Math.random() * maxY

                mainWindow.clickCount += 1
            }
        }

        Timer {
            id: moveTimer
            interval: mainWindow.moveInterval
            repeat: true
            running: true

            onTriggered: {
                var maxX = mainWindow.width - parent.width
                var maxY = mainWindow.height - parent.height

                parent.x = Math.random() * maxX
                parent.y = Math.random() * maxY
            }
        }

        Behavior on x {
            NumberAnimation {
                duration: 200
                easing.type: Easing.OutSine
            }
        }

        Behavior on y {
            NumberAnimation {
                duration: 200
                easing.type: Easing.OutSine
            }
        }
    }
}
