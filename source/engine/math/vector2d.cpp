#include "vector2d.h"

using namespace engine::math;

Vector2d::Vector2d() : _x(0), _y(0) {}

Vector2d::Vector2d(float x, float y) : _x(x), _y(y) {}

Vector2d &Vector2d::operator+(const Vector2d &add) {
  this->_x += add._x;
  this->_y += add._y;
  return *this;
}

Vector2d &Vector2d::operator+=(const Vector2d &other) {
  return (*this + other);
}

Vector2d Vector2d::operator*(float val) {
  this->_x *= val;
  this->_y *= val;
  return *this;
}

bool Vector2d::operator==(const Vector2d &other) const {
  return _x == other._x && _y == other._y;
}

bool Vector2d::operator!=(const Vector2d &other) const {
  return !(*this == other);
}
