#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include <QTimer>

#include <map>
#include <memory>

#include "unitfactory.h"

#define WORLD_GRAVITY 9.8

class World : public QObject {
  Q_OBJECT

  constexpr static float ratio = 100;

 public:
  explicit World(QObject* parent = nullptr);

  void init();

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

  float timeStep;
  int32 velocityIterations;
  int32 positionIterations;
};
