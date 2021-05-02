#include "ground.h"

using namespace engine::unit;

Ground::Ground(Unit* unit) : actionWalk(unit), actionIdle(nullptr) {
  actionIdle = (actions::Idle*)unit->idleAction();
}

void Ground::walk() { actionWalk.start(); }

void Ground::stay() { actionWalk.stop(); }

void Ground::setSpeed(float speed) { actionWalk.setSpeed(speed); }
