#include "basicunit.h"

BasicUnit::BasicUnit(const QString& type, b2World& world, float x, float y) {
  _type = type;
  _bodyDef.position.Set(x, y);
}

float BasicUnit::x() const { return _body->GetPosition().x - width() / 2; }

float BasicUnit::y() const { return _body->GetPosition().y - height() / 2; }

float BasicUnit::angle() const { return _body->GetAngle(); }

const QString& BasicUnit::type() const { return _type; }

b2BodyType BasicUnit::bodyType() const { return _bodyDef.type; }
