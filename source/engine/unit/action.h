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
  Action(Unit* unit) : _unit(unit), _interruptible(true) {}
  virtual ~Action() {}
  virtual void start();
  virtual void stop();
  virtual void timeTick(float time) = 0;
  bool iSstart() { return _isStart; }

  bool interruptible() const;

 protected:
  bool _isStart;
  bool _interruptible;
  Unit* _unit;
};

}  // namespace engine::unit
