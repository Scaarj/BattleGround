#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include <QTimer>

#include <map>
#include <memory>

#include "unitfactory.h"

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
  void createFloor();

 signals:
  void createObject(int, float);
  void moveObjectTo(int, float, float, float);

 public slots:
  void onTick();
  void createBall(float, float);
  void createOnClick(int, int);

 private:
  QTimer _timer;

  std::map<int, std::shared_ptr<BasicUnit>> _units;
  int _unitIndex;

  b2World _world;
  UnitFactory _factory;

  b2BodyDef groundBodyDef;
  b2Body* groundBody;
  b2PolygonShape groundBox;
};
