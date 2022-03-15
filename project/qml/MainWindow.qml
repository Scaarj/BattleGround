import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {

    visible: true
    width: 800
    height: 600
 //   visibility: "FullScreen"
    title: qsTr("BattleGround")

    property alias textHint: graphicContext.textHint

    Text {
        text: "Hello World!"
        font.family: "Helvetica"
        font.pointSize: 24
        color: "red"
    }


    Item {
        anchors.fill: parent
        focus: true
        Keys.onPressed: event => { KeyboardEvents.keyPressed(event.key) }
    }


    MouseArea {
        id: mouseProperty
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if (mouse.button === Qt.LeftButton) {
                AppCore.createOnLeftClick(mouseX, mouseY)
            } else if (mouse.button === Qt.RightButton) {
                AppCore.createOnRightClick(mouseX, mouseY)
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
