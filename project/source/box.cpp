#include "box.h"

Box::Box(b2World& world, float x, float y, float width, float height)
    : BasicUnit(world, x, y) {
  _halfWidth = width / 2;
  _halfHeight = height / 2;
  _dynamicBox.SetAsBox(_halfWidth, _halfHeight);
  _fixtureDef.shape = &_dynamicBox;
  _fixtureDef.density = 0.3f;
  _fixtureDef.friction = 1.0f;
  _body->CreateFixture(&_fixtureDef);
  _body->GetFixtureList();
}

float Box::halfWidth() const { return _halfWidth; }

float Box::halfHeight() const { return _halfHeight; }
