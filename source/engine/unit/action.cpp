#include "action.h"

using namespace engine::unit;

void engine::unit::Action::start() { _unit->startAction(this); }

void Action::stop() { _unit->stopAction(this); }

bool Action::interruptible() const { return _interruptible; }
