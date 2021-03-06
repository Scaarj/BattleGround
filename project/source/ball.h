#pragma once

#include "basicunit.h"

class Ball : public BasicUnit {
 public:
  Ball(b2World& word, float x, float y, float radius);
  virtual float width() const override;
  virtual float height() const override;

 private:
  float _radius;
};
