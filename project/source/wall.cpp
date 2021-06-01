#include "wall.h"

Wall::Wall(b2World &world, float x, float y, float width, float height) {
  _halfHeight = height / 2;
  _halfWidth = width / 2;
  _bodyDef.type = b2_staticBody;
  _bodyDef.position.Set(x + _halfWidth, y + _halfHeight);
  _shape.SetAsBox(_halfWidth, _halfHeight);
  _body = world.CreateBody(&_bodyDef);

  _fixtureDef.shape = &_shape;
  _body->CreateFixture(&_fixtureDef);
}

float Wall::height() const { return _halfHeight * 2; }

float Wall::width() const { return _halfWidth * 2; }

float Wall::x() const { return _body->GetPosition().x - _halfWidth; }

float Wall::y() const { return _body->GetPosition().y - _halfHeight; }
