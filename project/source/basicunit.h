#pragma once

#include <Box2D/Box2D.h>

class BasicUnit {
 public:
  BasicUnit(b2World& world, float, float);

  b2Body* body() const;

  float width() const;

  float height() const;

 private:
  b2BodyDef _bodyDef;
  b2Body* _body;
  b2CircleShape _dynamicBox;
  b2FixtureDef _fixtureDef;
  float _width, _height;
};
