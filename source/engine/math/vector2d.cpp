#include "vector2d.h"

using namespace engine::math;

vector2d::vector2d() {}

vector2d &vector2d::operator+(const vector2d &add) {
  this->_x += add._x;
  this->_y += add._y;
  return *this;
}

bool vector2d::operator==(const vector2d &other) const {
  return _x == other._x && _y == other._y;
}

bool vector2d::operator!=(const vector2d &other) const {
  return !(*this == other);
}
