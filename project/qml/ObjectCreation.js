var object
var component
var objects = {}

function createObjects(id, radius) {
    component = Qt.createComponent("ObjectBall.qml")
    object = component.createObject(graphicContext, {
                                        "x": 0,
                                        "y": 0,
                                        "width": radius,
                                        "height": radius
                                    })

    objects[id] = object
}

function createBoxObjects(id, width, height) {
    component = Qt.createComponent("ObjectBox.qml")
    object = component.createObject(graphicContext, {
                                        "x": 0,
                                        "y": 0,
                                        "width": width,
                                        "height": height
                                    })
    objects[id] = object
}

function createStaticObjects(id, x, y, width, height) {
    component = Qt.createComponent("ObjectWall.qml")
    object = component.createObject(graphicContext, {
                                        "x": x,
                                        "y": y,
                                        "width": width,
                                        "height": height
                                    })
    objects[id] = object
}

function moveObject(id, x, y, angle) {
    object = objects[id]
    object.x = x
    object.y = y
    object.rotate(angle)
}
