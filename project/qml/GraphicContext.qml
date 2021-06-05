import QtQuick 2.12
import QtQml 2.0
import QtQuick.Controls 2.5

import "ObjectCreation.js" as ObjectCreationScript

Rectangle {
    property alias textHint: textHint

    id: graphicContext
    anchors.fill: parent
    color: "steelblue"
    border.width: 10
    border.color: "black"

    Text {
        id: textHint
        text: "empty"
        font.pointSize: 12
        color: "#910b8d"
    }

    Connections {
        target: Objects

        onCreateObject: {
            ObjectCreationScript.createObject(id, type, x, y, width, height)
        }

        onMoveObjectTo: {
            ObjectCreationScript.moveObject(id, x, y, angle)
        }
    }
}
