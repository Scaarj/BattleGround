#include "wall.h"

Wall::Wall(b2World &world, float x, float y, float width, float height) {
  _height = height;
  _width = width;
  _bodyDef.type = b2_staticBody;
  _bodyDef.position.Set(x, y);
  _shape.SetAsBox(_width, _height);
  _body = world.CreateBody(&_bodyDef);

  _fixtureDef.shape = &_shape;
  _body->CreateFixture(&_fixtureDef);
}

b2Body *Wall::body() const { return _body; }

float Wall::height() const { return _height; }

float Wall::width() const { return _width; }
