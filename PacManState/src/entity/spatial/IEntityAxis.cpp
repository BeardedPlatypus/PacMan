#include "stdafx.h"
#include "entity/spatial/IEntityAxis.h"
#include "entity/spatial/EntityAxis.h"


namespace pacman {
namespace state {

std::unique_ptr<IEntityAxis> IEntityAxis::Construct(float position) {
  return std::make_unique<EntityAxis>(position);
}

}
}