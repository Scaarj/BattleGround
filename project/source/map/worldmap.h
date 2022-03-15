#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include <QTimer>

#include "gravity.h"

namespace map {
class WorldMap {
 public:
  WorldMap(int width, int height);

 private:
  int _width;
  int _height;
};
}  // namespace map
