#include "action.h"

using namespace engine::unit;

void engine::unit::Action::start() {
  if (!_unit->currentAction()) {
    _unit->setCurrentAction(this);
  } else {
    _unit->setNextAction(this);
  }
}

void Action::stop() {
  void* current = _unit->currentAction();
  if (current == this) {
    void* next = _unit->nextAction();
    if (next) {
      _unit->setCurrentAction(next);
      _unit->setNextAction(nullptr);
    } else {
      _unit->setCurrentAction(_unit->idleAction());
    }
  }
}
