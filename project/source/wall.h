#pragma once

#include <Box2D/Box2D.h>

class Wall {
 public:
  Wall(b2World& world, float x, float y, float width, float height);

  float height() const;

  float width() const;

  float x() const;
  float y() const;

 private:
  b2BodyDef _bodyDef;
  b2Body* _body;
  b2PolygonShape _shape;
  b2FixtureDef _fixtureDef;
  float _halfWidth, _halfHeight;
};
