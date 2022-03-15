var object
var component
var objects = {}

function createObject(id, type, x, y, width, height) {
    switch (type) {
    case "ball":
        component = Qt.createComponent("ObjectBall.qml")
        break
    case "box":
        component = Qt.createComponent("ObjectBox.qml")
        break
    case "wall":
        console.log(id, type, x, y, width, height)
        component = Qt.createComponent("ObjectWall.qml")
        break
    default:
        return
    }

    objects[id] = component.createObject(graphicContext, {
                                             "x": x,
                                             "y": y,
                                             "width": width,
                                             "height": height
                                         })
}

function moveObject(id, type, x, y, angle) {
    object = objects[id]
    object.x = x
    object.y = y
    if(angle !== 0) {
        object.rotate(angle)
    }
}
