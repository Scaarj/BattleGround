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

        function onCreateBallObject(id, radius) {
            ObjectCreationScript.createObjects(id, radius)
        }

        function onCreateBoxObject(id, width, height) {
           ObjectCreationScript.createBoxObjects(id, width, height)
        }

        function onUpdateObject(id, x, y, angle) {
            ObjectCreationScript.moveObject(id, x, y, angle)
        }

        function onCreateStaticObject(id, x, y, width, height) {
            ObjectCreationScript.createStaticObjects(id, x, y, width, height)
        }
    }
}
