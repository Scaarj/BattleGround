#include "ball.h"

Ball::Ball(b2World& world, float x, float y, float radius)
    : BasicUnit(QString("ball"), world, x, y), _radius(radius) {
  b2CircleShape* circleShape = new b2CircleShape;
  _bodyDef.type = b2_dynamicBody;
  _body = world.CreateBody(&_bodyDef);
  circleShape->m_radius = radius;
  _fixtureDef.shape = circleShape;
  _fixtureDef.density = 0.3f;
  _fixtureDef.friction = 1.0f;
  _body->CreateFixture(&_fixtureDef);
}

float Ball::width() const { return _radius * 2; }

float Ball::height() const { return _radius * 2; }
