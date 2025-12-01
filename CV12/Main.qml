import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 600
    visible: true
    title: qsTr("Gallery")

    header: ToolBar {
        id: toolBar

        height: parent.height * 0.05

        RowLayout {
            anchors.fill: parent
            spacing: 20

            ToolButton {
                height: parent.height * 0.9
                width: height
                contentItem: Text {
                    text: qsTr("...")
                }
                onClicked: drawer.open()
            }

            Label {
                text: pictures[imageSelector.currentIndex].name
                horizontalAlignment: Qt.AlignHCenter
                font.pointSize: 14
                font.bold: true
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Text {
                    text: qsTr("Menu")
                }

                onClicked: mainMenu.open()

                Menu {
                    id: mainMenu
                    y: toolBar.height

                    MenuItem {
                        text: qsTr("Quit")
                        onTriggered: Qt.quit()
                    }
                }
            }
        }
    }

    Drawer {
        id: drawer
        width: parent.width * 0.6
        height: parent.height

        ListView {
            id: imageSelector
            spacing: 20
            focus: true

            anchors.fill: parent
            anchors.margins: 20

            model: pictures

            delegate: Column {
                width: parent.width
                spacing: 5

                Image {
                    fillMode: Image.PreserveAspectFit
                    width: parent.width
                    source: model.url

                    anchors.horizontalCenter: parent.horizontalCenter

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            imageSelector.currentIndex = index
                            drawer.close()
                        }
                    }
                }
                Label {
                    text: model.name
                    font.bold: index === imageSelector.currentIndex ? true : false

                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    Image {
        id: photo
        visible: false
        width: parent.width - 40
        fillMode: Image.PreserveAspectFit
        source: pictures[imageSelector.currentIndex].url

        Rectangle {
            color: "transparent"
            border.color: "white"
            border.width: 10

            anchors.margins: -10
            anchors.fill: parent
        }

        Component.onCompleted: {
            photo.x = parent.width / 2 - photo.width / 2
            photo.y = parent.height / 2 - photo.height / 2
            photo.visible = true
        }

        PinchArea {
            anchors.fill: parent
            pinch.target: photo
            pinch.minimumRotation: -360
            pinch.maximumRotation: 360
            pinch.minimumScale: 0.1
            pinch.maximumScale: 10
            pinch.dragAxis: Pinch.XAndYAxis
        }
    }

    /*ListModel {
        id: pictures

        ListElement {
            name: "Space";
            url: "1.jpg"
        }

        ListElement {
            name: "Dog";
            url: "2.webp"
        }

        ListElement {
            name: "Bird";
            url: "3.jpg"
        }
    }*/

}
