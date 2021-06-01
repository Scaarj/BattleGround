#pragma once

#include "basicunit.h"

class Box : public BasicUnit {
 public:
  Box(b2World& world, float x, float y, float width, float height);
  virtual float halfWidth() const override;
  virtual float halfHeight() const override;

 public:
  float _halfWidth, _halfHeight;
  b2PolygonShape _dynamicBox;
  b2FixtureDef _fixtureDef;
};
