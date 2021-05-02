#pragma once

namespace engine::math {
class Vector2d {
 public:
  explicit Vector2d();
  explicit Vector2d(float x, float y);
  Vector2d(const Vector2d &) = default;
  Vector2d &operator=(const Vector2d &) = default;
  Vector2d &operator+(const Vector2d &);
  Vector2d &operator+=(const Vector2d &);
  Vector2d operator*(float);

  bool operator==(const Vector2d &) const;
  bool operator!=(const Vector2d &) const;

 private:
  float _x, _y;
};
}  // namespace engine::math
