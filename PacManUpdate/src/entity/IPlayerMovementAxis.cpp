#include "pch.h"
#include "entity/IPlayerMovementAxis.h"
#include "entity/PlayerMovementAxis.h"


namespace pacman {
namespace update {

std::unique_ptr<IPlayerMovementAxis> IPlayerMovementAxis::Construct() {
  return std::make_unique<PlayerMovementAxis>();
}

}
}