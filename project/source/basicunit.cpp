#include "basicunit.h"

BasicUnit::BasicUnit(b2World& world, float x, float y) {
  _bodyDef.type = b2_dynamicBody;
  _bodyDef.position.Set(x, y);
  _body = world.CreateBody(&_bodyDef);
}

float BasicUnit::x() const { return _body->GetPosition().x - halfWidth(); }

float BasicUnit::y() const { return _body->GetPosition().y - halfHeight(); }

float BasicUnit::angle() const { return _body->GetAngle(); }

float BasicUnit::width() const { return halfWidth() * 2; }

float BasicUnit::height() const { return halfHeight() * 2; }
