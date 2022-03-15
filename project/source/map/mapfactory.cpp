#include "mapfactory.h"

using namespace map;

MapFactory::MapFactory() {}

std::shared_ptr<WorldMap> MapFactory::createMap() {
  return std::make_shared<WorldMap>(100, 200);
}
