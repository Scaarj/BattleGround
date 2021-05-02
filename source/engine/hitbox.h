#pragma once

namespace engine {
class Hitbox {
 public:
  Hitbox(float width, float height);

  void moveTo(float, float);
  bool isCollided(const Hitbox&) const;

 protected:
  float _x, _y;
  float _width;
  float _height;
};

}  // namespace engine
