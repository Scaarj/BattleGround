#pragma once

#include <Box2D/Box2D.h>
#include "basicunit.h"

class Wall : public BasicUnit {
 public:
  Wall(b2World& world, float x, float y, float width, float height);
  virtual float width() const override;
  virtual float height() const override;

 private:
  float _width, _height;
};
