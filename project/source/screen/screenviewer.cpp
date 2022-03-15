#include "screenviewer.h"

#include <QDebug>

using namespace screen;

ScreenViewer::ScreenViewer(int width, int height)
    : _width(width), _height(height), _x(0), _y(0) {}

void ScreenViewer::setMap(std::shared_ptr<map::WorldMap> map) { _map = map; }

int ScreenViewer::x() const { return _x; }

int ScreenViewer::y() const { return _y; }

void ScreenViewer::move(int x, int y) {
  if (x < 0) {
    _x += 10;
  } else if (x > 0) {
    _x -= 10;
  }

  if (y < 0) {
    _y -= 10;
  } else if (y > 0) {
    _y += 10;
  }
}
