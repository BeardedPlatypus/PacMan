#include "pch.h"
#include "entity/IUpdatableEntityAxis.h"
#include "entity/UpdatableEntityAxis.h"


namespace pacman {
namespace update {

std::unique_ptr<IUpdatableEntityAxis> IUpdatableEntityAxis::Construct(state::IEntityAxis* p_axis) {
  return std::make_unique<UpdatableEntityAxis>(p_axis);
}

}
}