#include "basicunit.h"

BasicUnit::BasicUnit(b2World& world, float x, float y) {
  _width = 0.2f;
  _height = 0.2f;

  _bodyDef.type = b2_dynamicBody;
  _bodyDef.position.Set(x - _width, y - _height);
  _body = world.CreateBody(&_bodyDef);
  _dynamicBox.m_radius = _width;

  _fixtureDef.shape = &_dynamicBox;
  _fixtureDef.density = 0.3f;
  _fixtureDef.friction = 1.0f;
  _body->CreateFixture(&_fixtureDef);
  _body->GetFixtureList();
}

b2Body* BasicUnit::body() const { return _body; }

float BasicUnit::width() const { return _width; }

float BasicUnit::height() const { return _height; }
