import QtQuick 2.12
import QtQml 2.0
import QtQuick.Controls 2.5

import "ObjectCreation.js" as ObjectCreationScript

Rectangle {
    property alias textHint: textHint

    id: graphicContext
    anchors.fill: parent

    Image {
        anchors.fill: parent
        source: "qrc:/resource/images/background1.png"
    }

    Text {
        id: textHint
        text: "empty"
        font.pointSize: 12
        color: "#910b8d"
    }

    Connections {
        target: AppCore

        function onCreateObject(id, type, x, y, width, height) {
            console.log(type)
            ObjectCreationScript.createObject(id, type, x, y, width, height)
        }

        function onMoveObjectTo(id, type, x, y, angle) {
            ObjectCreationScript.moveObject(id, type, x, y, angle)
        }
    }
}
