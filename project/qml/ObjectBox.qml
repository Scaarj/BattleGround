import QtQuick 2.0

Item {
    property alias rotationPos: rotationPos
    function rotate(angle) {
        var angleRad = angle * (180 / 3.14)
        rotationPos.angle = angleRad
    }

    Image {
        anchors.fill: parent
        source: "qrc:/resource/images/box.png"
        transform: Rotation {
            id: rotationPos
            origin.x: width / 2
            origin.y: height / 2
        }
    }
}
