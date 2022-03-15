#pragma once

#include <QObject>

#include "../map/worldmap.h"

namespace screen {
class ScreenViewer : public QObject {
  Q_OBJECT
 public:
  ScreenViewer(int width, int height);

  void setMap(std::shared_ptr<map::WorldMap> map);

  int x() const;
  int y() const;

 public slots:
  void move(int x, int y);

 private:
  std::shared_ptr<map::WorldMap> _map;

  int _width;
  int _height;
  int _x;
  int _y;
};
}  // namespace screen
