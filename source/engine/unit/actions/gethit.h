#pragma once

#include "../../math/vector2d.h"
#include "../action.h"

namespace engine::unit::actions {
class GetHit : public Action {
 public:
  GetHit(Unit* unit);
  virtual void timeTick(float time) override;
};
}  // namespace engine::unit::actions
