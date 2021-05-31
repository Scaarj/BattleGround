#pragma once

#include <Box2D/Box2D.h>

class Wall {
 public:
  Wall(b2World& world, float x, float y, float width, float height);

  b2Body* body() const;

  float height() const;

  float width() const;

 private:
  b2BodyDef _bodyDef;
  b2Body* _body;
  b2PolygonShape _shape;
  b2FixtureDef _fixtureDef;
  float _width, _height;
};
