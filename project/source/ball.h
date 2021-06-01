#pragma once

#include "basicunit.h"

class Ball : public BasicUnit {
 public:
  Ball(b2World& world, float x, float y, float radius);

  virtual float halfWidth() const override;
  virtual float halfHeight() const override;
  float radius() const;

 public:
  b2CircleShape _dynamicBox;
  b2FixtureDef _fixtureDef;
  float _radius;
};
