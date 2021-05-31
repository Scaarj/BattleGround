#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include "wall.h"

class EnvironmentFactory : public QObject {
  Q_OBJECT

 public:
  EnvironmentFactory(b2World&, QObject* object);
  Wall* create(float x, float y, float width, float height);

 private:
  b2World& _world;
};
