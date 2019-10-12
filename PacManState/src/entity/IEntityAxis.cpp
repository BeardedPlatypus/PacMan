#include "stdafx.h"
#include "entity/IEntityAxis.h"
#include "entity/EntityAxis.h"


namespace pacman {
namespace state {

std::unique_ptr<IEntityAxis> IEntityAxis::Construct(float position) {
  return std::make_unique<EntityAxis>(position);
}

}
}