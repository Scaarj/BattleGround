#pragma once

#include <Box2D/Box2D.h>
#include <QObject>

class BasicUnit {
 public:
  BasicUnit(const QString& type, b2World& world, float x, float y);

  float x() const;
  float y() const;
  float angle() const;
  virtual float width() const = 0;
  virtual float height() const = 0;

  const QString& type() const;
  b2BodyType bodyType() const;

 protected:
  QString _type;
  b2BodyDef _bodyDef;
  b2Body* _body;
  b2Shape* _shape;
  b2FixtureDef _fixtureDef;
};
