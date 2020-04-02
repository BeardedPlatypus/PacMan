#include "stdafx.h"
#include "entity/ISpatialState.h"

#include "entity/SpatialState.h"


namespace pacman {
namespace state {

std::unique_ptr<ISpatialState> ISpatialState::Construct(float x, float y, Direction dir, float speed) {
  return std::make_unique<SpatialState>(x, y, dir, speed);
}

}
}