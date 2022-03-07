#include "box.h"

Box::Box(b2World& world, float x, float y, float width, float height)
    : BasicUnit(QString("box"), world, x, y), _width(width), _height(height) {
  b2PolygonShape* boxShape = new b2PolygonShape;

  _bodyDef.type = b2_dynamicBody;
  _body = world.CreateBody(&_bodyDef);
  boxShape->SetAsBox(_width / 2, _height / 2);
  _fixtureDef.shape = boxShape;
  _fixtureDef.density = 0.3f;
  _fixtureDef.friction = 1.0f;
  _body->CreateFixture(&_fixtureDef);
}

float Box::width() const { return _width; }

float Box::height() const { return _height; }
