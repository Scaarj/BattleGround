#pragma once

#include <Box2D/Box2D.h>

class BasicUnit {
 public:
  BasicUnit(b2World& world, float x, float y);

  float x() const;
  float y() const;
  float angle() const;
  float width() const;
  float height() const;

 protected:
  virtual float halfWidth() const = 0;
  virtual float halfHeight() const = 0;

 protected:
  b2Body* _body;
  b2BodyDef _bodyDef;
};
