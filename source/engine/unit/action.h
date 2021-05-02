#pragma once

#include <boost/signals2/signal.hpp>

#include "unit.h"

namespace engine::unit {
class Action {
 public:
  boost::signals2::signal<void()> onStart;
  boost::signals2::signal<void()> onStop;
  boost::signals2::signal<void(int)> OnTimeTick;

 public:
  Action(Unit* unit) : _unit(unit) {}
  virtual ~Action() {}
  virtual void start();
  virtual void stop();
  virtual void timeTick(float time) = 0;
  bool iSstart() { return _isStart; }

 protected:
  bool _isStart;
  Unit* _unit;
};

}  // namespace engine::unit
