#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include <QTimer>

#include <map>
#include <memory>

#include "environmentfactory.h"
#include "unitfactory.h"
#include "wall.h"

class World : public QObject {
  Q_OBJECT

 public:
  static constexpr float gravity = 500.f;
  static constexpr float framePerSecond = 60;
  static constexpr float timeStep = 1.f / framePerSecond;
  static constexpr int velocityIterations = 100;
  static constexpr int positionIterations = 100;

 public:
  explicit World(QObject* parent = nullptr);
  void init();
  void createFloor(float x, float y, float width, float height);

 signals:
  void createBallObject(int id, float radius);
  void createBoxObject(int id, float width, float height);
  void updateObject(int id, float x, float y, float angle);
  void createStaticObject(int id, float x, float y, float width, float height);

 public slots:
  void onTick();
  void createBall(float x, float y, float radius);
  void createBox(float x, float y, float width, float height);

  void createOnClick(int, int);
  void createOnRightClick(int, int);

 private:
  QTimer _timer;

  std::map<int, BasicUnit*> _units;
  std::map<int, Wall*> _blocks;

  int _unitIndex;

  b2World _world;
  UnitFactory _factory;
  EnvironmentFactory _environmentFactory;
};
