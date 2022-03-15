#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include <QTimer>

#include <map>
#include <memory>

#include "unitcontainer.h"
#include "unitfactory.h"

#include "map/mapfactory.h"

class World : public QObject {
  Q_OBJECT

 public:
  static constexpr float worldGravity = 100;
  static constexpr float timeStep = 1.f / 60.f;
  static constexpr int velocityIterations = 10;
  static constexpr int positionIterations = 10;

 public:
  explicit World(QObject* parent = nullptr);

  void init();

 public slots:
  void onTick();
  void createBall(float x, float y, float radius);
  void createBox(float x, float y, float width, float height);
  void createWall(float x, float y, float width, float height);
  void createOnLeftClick(float x, float y);
  void createOnRightClick(float x, float y);

 public:
  UnitContainer _unitContainer;

 private:
  QTimer _timer;
  b2World _world;
  UnitFactory _factory;

  map::MapFactory _mapFactory;
  std::shared_ptr<map::WorldMap> _map;
};
