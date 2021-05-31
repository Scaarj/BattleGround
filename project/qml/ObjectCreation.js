var object
var component;
var objects = {}

function createObjects(id, width) {
    var size = width * 2
    component = Qt.createComponent("ObjectBall.qml");
    object = component.createObject(graphicContext, {x: 0, y: 0, width: size, height: size});
    objects[id] = object
}

function moveObject(id, x, y, angle) {
    object = objects[id]
    object.x = x
    object.y = y
    object.rotate(angle)
}
