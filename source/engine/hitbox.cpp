#include "hitbox.h"

using namespace engine;

Hitbox::Hitbox(float width, float height)
    : _x(0), _y(0), _width(width), _height(height) {}

void Hitbox::moveTo(float x, float y) {
  _x = x;
  _y = y;
}

bool Hitbox::isCollided(const Hitbox &other) const {
  bool xCollided = false;
  bool yCollided = false;
  if ((_x + _width >= other._x) && (_x <= other._x + other._width)) {
    xCollided = true;
  }
  if ((_y + _height >= other._y) && (_y <= other._y + other._height)) {
    yCollided = true;
  }
  if (xCollided & yCollided) {
    return true;
  }

  return false;
}
