#include "stdafx.h"
#include "IEntityState.h"

#include "EntityState.h"


namespace pacman {
namespace state {

std::unique_ptr<IEntityState> IEntityState::Construct(float x, float y, Direction dir) {
  return std::make_unique<EntityState>(x, y, dir);
}

}
}