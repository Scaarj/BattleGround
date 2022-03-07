#pragma once

#include "basicunit.h"

class Box : public BasicUnit {
 public:
  Box(b2World& word, float x, float y, float width, float height);
  virtual float width() const override;
  virtual float height() const override;

 private:
  float _width, _height;
};
