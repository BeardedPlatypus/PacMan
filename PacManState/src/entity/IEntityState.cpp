#include "stdafx.h"
#include "entity/IEntityState.h"

#include "entity/EntityState.h"


namespace pacman {
namespace state {

std::unique_ptr<IEntityState> IEntityState::Construct(float x, float y, Direction dir, float speed) {
  return std::make_unique<EntityState>(x, y, dir, speed);
}

}
}