#include "pch.h"
#include "entity/animation/GhostAnimationConfigRepository.h"
#include "entity/animation/AnimationRenderConfig.h"
#include "entity/EntitySpriteValues.h"
#include "entity/animation/StaticAnimationUpdateBehaviour.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

std::unique_ptr<IAnimationRenderConfig> ConstructMovingAnimation(view::IViewAPI* p_view_api,
                                                                 const std::string& anim_label,
                                                                 const std::vector<std::shared_ptr<SpriteRenderConfig>>& sprites) {

  std::vector<std::string> sprite_labels = {
    sprites.at(0)->GetSpriteLabel(),
    sprites.at(1)->GetSpriteLabel(),
  };


  return std::make_unique<AnimationRenderConfig>(
    p_view_api,
    anim_label,
    0.25F, 
    sprite_labels,
    sprites,
    std::make_unique<StaticAnimationUpdateBehaviour>(p_view_api,
                                                     anim_label));
}

std::unique_ptr<IAnimationRenderConfig> GhostAnimationConfigRepository::ConstructMovingHorizontalAnimation(
    view::IViewAPI* p_view_api,
    const std::string& unique_label_id,
    state::GhostEntityType ghost_entity_type,
    const GhostSpriteConfigRepository& sprite_repository) const {
  auto sprites = sprite_repository.GetMovingHorizontalSpriteConfigs(ghost_entity_type);
  return ConstructMovingAnimation(p_view_api, unique_label_id, sprites);
}


std::unique_ptr<IAnimationRenderConfig> GhostAnimationConfigRepository::ConstructMovingUpAnimation(
    view::IViewAPI* p_view_api,
    const std::string& unique_label_id,
    state::GhostEntityType ghost_entity_type,
    const GhostSpriteConfigRepository& sprite_repository) const {
  auto sprites = sprite_repository.GetMovingUpSpriteConfigs(ghost_entity_type);
  return ConstructMovingAnimation(p_view_api, unique_label_id, sprites);
}


std::unique_ptr<IAnimationRenderConfig> GhostAnimationConfigRepository::ConstructMovingDownAnimation(
    view::IViewAPI* p_view_api,
    const std::string& unique_label_id,
    state::GhostEntityType ghost_entity_type,
    const GhostSpriteConfigRepository& sprite_repository) const {
  auto sprites = sprite_repository.GetMovingDownSpriteConfigs(ghost_entity_type);
  return ConstructMovingAnimation(p_view_api, unique_label_id, sprites);
}

}
}
}
}
