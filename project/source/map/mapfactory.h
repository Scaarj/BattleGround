#pragma once

#include "worldmap.h"

#include <memory>

namespace map {
class MapFactory {
 public:
  MapFactory();

  std::shared_ptr<WorldMap> createMap();
};
}  // namespace map
