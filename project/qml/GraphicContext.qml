import QtQuick 2.12
import QtQuick.Controls 2.5

import "ObjectCreation.js" as ObjectCreationScript

Rectangle {

    id: graphicContext
    anchors.fill: parent
    color: "steelblue"
    border.width: 10
    border.color: "#44096d"

    Connections {
        target: World

        onCreateBallObject: {
            ObjectCreationScript.createObjects(id, radius)
        }

        onCreateBoxObject: {
            ObjectCreationScript.createBoxObjects(id, width, height)
        }

        onUpdateObject: {
            ObjectCreationScript.moveObject(id, x, y, angle)
        }
        onCreateStaticObject: {
            ObjectCreationScript.createStaticObjects(id, x, y, width, height)
        }
    }
}
