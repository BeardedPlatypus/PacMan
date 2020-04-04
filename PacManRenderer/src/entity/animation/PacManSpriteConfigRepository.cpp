#include "pch.h"
#include "entity/animation/PacManSpriteConfigRepository.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

std::vector<std::shared_ptr<animation::SpriteRenderConfig>> PacManSpriteConfigRepository::GetMovingSpriteConfigs() const {
  return {
    this->p_default,
    this->p_moving_0,
    this->p_moving_1,
  };
}

}
}
}
}
