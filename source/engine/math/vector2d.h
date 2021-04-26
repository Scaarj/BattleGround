#pragma once

namespace engine::math {
class vector2d {
 public:
  explicit vector2d();
  explicit vector2d(float x, float y) : _x(x), _y(y) {}
  vector2d(const vector2d &) = default;
  vector2d &operator=(const vector2d &) = default;
  vector2d &operator+(const vector2d &);

  bool operator==(const vector2d &) const;
  bool operator!=(const vector2d &) const;

 private:
  float _x, _y;
};
}  // namespace engine::math
