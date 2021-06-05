import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("BattleGround")

    property alias textHint: graphicContext.textHint

    Text {
        text: "Hello World!"
        font.family: "Helvetica"
        font.pointSize: 24
        color: "red"
    }

    MouseArea {
        id: mouseProperty
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if (mouse.button == Qt.LeftButton) {
                World.createOnLeftClick(mouseX, mouseY)
            } else if (mouse.button == Qt.RightButton) {
                World.createOnRightClick(mouseX, mouseY)
            }
        }

        onPositionChanged: {
            textHint.x = mouseX
            textHint.y = mouseY + 20
            textHint.text = qsTr(mouseX.toString() + " " + mouseY.toString())
        }

        GraphicContext {
            id: graphicContext
        }
    }
}
