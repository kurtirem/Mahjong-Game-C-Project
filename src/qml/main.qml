import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 800
    height: 800
    title: "Mahjong - Turtle Layout"

    property int tileWidth: 50
    property int tileHeight: 70
    property int spacing: 5

    function tileImageName(type, value) {
        if (type === "Bamboo") {
            return "bamboo" + value + ".png"
        } else if (type === "Circle") {
            return "circle" + value + ".png"
        } else if (type === "Pinyin") {
            return "pinyin" + value + ".png"
        } else {
            // For special tiles: chrysanthemum, fall, lotus, orchid, peony, spring, summer, winter
            return type.toLowerCase() + ".png"
        }
    }

    Repeater {
        model: tileModel
        Rectangle {
            width: tileWidth
            height: tileHeight

            // Previous offsets were +50 in x and -50 in y. Now doubling:
            // +100 in x and -100 in y
            x: (model.column * (tileWidth + spacing)) + 100
            y: (model.row * (tileHeight + spacing)) - (model.layer * 10) - 100

            z: model.layer * 10
            color: model.selected ? "#ffcc00" : "#f0f0f0"
            border.width: 1
            border.color: "#999"
            radius: 5
            opacity: model.open ? 1.0 : 0.4

            Image {
                anchors.centerIn: parent
                source: "qrc:/images/" + tileImageName(model.type, model.value)
                width: parent.width - 10
                height: parent.height - 10
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    board.selectTile(model.row, model.column)
                }
            }
        }
    }

    Button {
        text: "Shuffle"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: board.shuffle()
    }
}
