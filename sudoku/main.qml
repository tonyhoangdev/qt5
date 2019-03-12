import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    id: topObject
    visible: true
    width: 650
    height: 500
    title: qsTr("Hello World")

    Connections {
        target: myAppData

        onSendData: {
            var arr = data.split(',')
            for (var i = 0; i < arr.length; i++) {
                gridView.currentIndex = i
                gridView.currentItem.setValue = arr[i]
            }
        }
    }

    property int currentData: 0

    function getCurrentData() {
        if (++currentData >= a.length) {
            currentData = 0
        }
        return currentData
    }

    // advanced
    property var a0: [
        4,0,3,0,0,7,8,0,0,
        0,2,0,4,6,8,0,0,0,
        0,1,0,0,0,9,5,0,0,
        0,0,5,0,0,0,0,8,3,
        3,0,0,1,0,4,0,0,9,
        2,8,0,0,0,0,7,0,0,
        0,0,4,3,0,0,0,7,0,
        0,0,0,8,4,5,0,1,0,
        0,0,2,7,0,0,4,0,5
    ]
    property var a1: [
        9,0,0,0,0,0,0,7,0,
        2,0,0,1,8,0,0,6,0,
        0,5,0,0,4,0,0,0,9,
        0,8,0,0,0,7,0,0,0,
        3,0,7,0,0,0,6,0,1,
        0,0,0,5,0,0,0,9,0,
        7,0,0,0,9,0,0,3,0,
        0,2,0,0,5,1,0,0,7,
        0,3,0,0,0,0,0,0,4,
    ]
    property var a2: [
        0,3,4,0,0,0,0,0,0,
        0,0,8,5,0,0,1,4,0,
        6,7,0,8,0,0,0,0,0,
        0,0,0,0,9,0,0,0,0,
        7,9,0,0,2,0,0,3,8,
        0,0,0,0,8,0,0,0,0,
        0,0,0,0,0,4,0,6,7,
        0,1,6,0,0,3,8,0,0,
        0,0,0,0,0,0,3,9,0,
    ]
    property var a3: [
        4,0,0,0,0,1,6,0,0,
        0,0,7,9,0,0,1,0,4,
        1,0,5,0,0,0,2,0,0,
        0,0,0,0,0,0,0,3,9,
        0,7,0,0,1,0,0,4,0,
        2,4,0,0,0,0,0,0,0,
        0,0,2,0,0,0,3,0,7,
        8,0,9,0,0,6,4,0,0,
        0,0,4,0,0,0,0,0,1,
    ]
    property var a4: [
        1,6,0,0,0,0,0,0,4,
        0,5,3,4,0,0,0,1,0,
        7,0,4,0,0,6,0,2,0,
        9,0,0,5,0,0,0,0,2,
        0,0,0,2,3,8,0,0,0,
        5,0,0,0,0,9,0,0,3,
        0,7,0,8,0,0,4,0,9,
        0,4,0,0,0,1,2,8,0,
        6,0,0,0,0,0,0,3,1,
    ]

    property var a: [a0, a1, a2, a3, a4]

    // basic
    property var d0: [
        0,1,8,0,2,0,0,0,0,
        9,0,0,0,0,0,0,8,4,
        7,0,0,1,0,0,0,0,0,
        0,0,1,9,0,0,0,2,0,
        0,0,2,5,4,6,7,0,0,
        0,7,0,0,0,2,8,0,0,
        0,0,0,0,0,5,0,0,1,
        8,9,0,0,0,0,0,0,5,
        0,0,0,0,7,0,3,4,0,
    ]
    property var d1: [
        9,0,0,0,0,0,0,7,0,
        2,0,0,1,8,0,0,6,0,
        0,5,0,0,4,0,0,0,9,
        0,8,0,0,0,7,0,0,0,
        3,0,7,0,0,0,6,0,1,
        0,0,0,5,0,0,0,9,0,
        7,0,0,0,9,0,0,3,0,
        0,2,0,0,5,1,0,0,7,
        0,3,0,0,0,0,0,0,4,
    ]
    property var d2: [
        0,0,0,0,0,0,0,2,0,
        0,0,9,3,0,5,0,7,0,
        0,0,4,0,2,9,0,0,6,
        2,0,0,6,0,0,1,9,0,
        0,0,1,0,0,0,3,0,0,
        0,7,3,0,0,1,0,0,8,
        1,0,0,4,8,0,6,0,0,
        0,5,0,9,0,2,8,0,0,
        0,9,0,0,0,0,0,0,0,
    ]
    property var d3: [
        7,3,0,0,0,0,0,5,0,
        1,6,0,0,2,0,9,0,8,
        0,0,0,0,0,0,0,6,0,
        6,0,0,0,1,0,0,3,0,
        0,0,0,6,7,9,0,0,0,
        0,4,0,0,5,0,0,0,1,
        0,8,0,0,0,0,0,0,0,
        3,0,6,0,9,0,0,8,2,
        0,9,0,0,0,0,0,4,6,
    ]
    property var d4: [
        0,8,0,6,0,0,3,0,5,
        5,0,0,0,0,8,0,0,0,
        0,6,0,0,4,5,2,0,0,
        2,4,0,0,6,0,0,3,0,
        0,0,0,3,0,9,0,0,0,
        0,3,0,0,1,0,0,9,2,
        0,0,7,4,5,0,0,2,0,
        0,0,0,7,0,0,0,0,3,
        4,0,8,0,0,3,0,1,0,
    ]

    property var d: [d0, d1, d2, d3, d4]

    //
    property var b: [
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
    ]

    // set manually
    property var c: [
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
    ]

    function enCode(ab) {
        var str = ab.toString()
        myAppData.parseData(str)
    }

    Rectangle {
        id: mainSodoku
        width: 500; height: 950

        GridView {
            id: gridView
            width: 450; height: 450
            x: 2; y: 2
            cellWidth: 50; cellHeight: 50
            model: a[0]
            clip: true
            snapMode: ListView.SnapToItem

            delegate: Rectangle {
                border.color: "black"
                width: 50; height: 50

                property int value: parseInt(txt1.text)
                property alias setValue: txt1.text

                TextInput  {
                    id: txt1
                    anchors.centerIn: parent
                    width: 40; height: 40
                    text: (modelData != 0) ? modelData : ""
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: (modelData != 0) ? "red" : "black"
                    readOnly: (modelData != 0)
                    font.pixelSize: 20
                    font.weight: (modelData != 0) ? Font.Bold : Font.Normal
                }
            }
        }

        Rectangle {
            width: 450; height: 450
            border.width: 4
            border.color: "red"
            color: "transparent"
            x: 2; y: 2
        }
        Rectangle {
            color: "red"
            width: 450; height: 4
            x: 2; y: 50 * 3
        }
        Rectangle {
            color: "red"
            width: 450; height: 4
            x: 2; y: 50 * 6
        }
        Rectangle {
            color: "red"
            width: 450; height: 4
            x: 2; y: 50 * 3
        }

        Rectangle {
            color: "red"
            height: 450; width: 4
            x: 50 * 3; y: 2
        }
        Rectangle {
            color: "red"
            height: 450; width: 4
            x: 50 * 6; y: 2
        }
    }


    Column {
        x: 500; y: 10

        Rectangle {
            width: 100; height: 50
            border.color: "red"

            Text {
                anchors.centerIn: parent
                text: "Clear"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    for (var i = 0; i < 81; i ++) {
                        gridView.currentIndex = i
                        gridView.currentItem.setValue = ""
                    }
                    gridView.model = b
                }
            }
        }

        Rectangle {
            width: 100; height: 50
            border.color: "red"

            Text {
                anchors.centerIn: parent
                text: "Set Data"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    for (var i = 0; i < 81; i ++) {
                        gridView.currentIndex = i
                        c[i] = (gridView.currentItem.setValue !== "") ? gridView.currentItem.value : 0
                    }
                    gridView.model = c
                }
            }
        }

        Rectangle {
            width: 100; height: 50
            border.color: "red"

            Text {
                anchors.centerIn: parent
                text: "Resolve"
                font.bold: true
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    enCode(gridView.model)
                }
            }
        }

        Rectangle {
            width: 100; height: 50
            border.color: "red"

            Text {
                anchors.centerIn: parent
                text: "Temp Advance"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    for (var i = 0; i < 81; i ++) {
                        gridView.currentIndex = i
                        gridView.currentItem.setValue = ""
                    }
                    gridView.model = a[getCurrentData()]
                }
            }
        }

        Rectangle {
            width: 100; height: 50
            border.color: "red"

            Text {
                anchors.centerIn: parent
                text: "Temp Basic"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    for (var i = 0; i < 81; i ++) {
                        gridView.currentIndex = i
                        gridView.currentItem.setValue = ""
                    }
                    gridView.model = d[getCurrentData()]
                }
            }
        }

    }
}
