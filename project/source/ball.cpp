#include "ball.h"

Ball::Ball(b2World &world, float x, float y, float radius)
    : BasicUnit(world, x, y) {
  _radius = radius;

  _dynamicBox.m_radius = _radius;
  _fixtureDef.shape = &_dynamicBox;
  _fixtureDef.density = 0.3f;
  _fixtureDef.friction = 1.0f;
  _body->CreateFixture(&_fixtureDef);
  _body->GetFixtureList();
}

float Ball::halfWidth() const { return _radius; }

float Ball::halfHeight() const { return _radius; }

float Ball::radius() const { return _dynamicBox.m_radius; }
