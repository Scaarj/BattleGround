import QtQuick 2.12
import QtQuick.Controls 2.5

import "ObjectCreation.js" as ObjectCreationScript

Rectangle {
    id: graphicContext
    anchors.fill: parent
    color: "steelblue"
    border.width: 10
    border.color: "black"

    Connections {
        target: World

        function onCreateObject(id, width, height) {
            ObjectCreationScript.createObjects(id, width)
        }

        function onMoveObjectTo(id, x, y, angle) {
            ObjectCreationScript.moveObject(id, x, y, angle)
        }
    }
}
