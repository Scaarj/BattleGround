import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("BattleGround")

    MouseArea {
    anchors.fill: parent
    onClicked: {
        World.createOnClick(mouseX, mouseY)
    }
    GraphicContext {}

    }
}
