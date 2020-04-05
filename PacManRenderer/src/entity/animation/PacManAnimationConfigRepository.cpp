#include "pch.h"
#include "entity/animation/PacManAnimationConfigRepository.h"

#include "entity/animation/ActiveInverseAnimationUpdateBehaviour.h"
#include "entity/animation/AnimationRenderConfig.h"

#include "entity/EntitySpriteValues.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {


std::unique_ptr<IAnimationRenderConfig> GetMovingAnimation(
    view::IViewAPI* p_view_api,
    const std::string& anim_label,
    const std::vector<std::string> sprite_frames,
    const PacManSpriteConfigRepository& sprite_repository,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) {
  std::unique_ptr<ActiveInverseAnimationUpdateBehaviour> p_update_behaviour = 
    std::make_unique<animation::ActiveInverseAnimationUpdateBehaviour>(p_view_api, 
                                                                       anim_label,
                                                                       p_active_label_provider);

  return std::make_unique<AnimationRenderConfig>(p_view_api, 
                                                 anim_label,
                                                 0.125F, 
                                                 sprite_frames, 
                                                 sprite_repository.GetMovingSpriteConfigs(),
                                                 std::move(p_update_behaviour));
}


std::unique_ptr<IAnimationRenderConfig> PacManAnimationConfigRepository::ConstructForwardMovingAnimation(
    view::IViewAPI* p_view_api,
    const std::string& unique_label_id,
    const PacManSpriteConfigRepository& sprite_repository,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) const {
  const std::string animation_label = values::pacman_moving_anim + unique_label_id;

  std::vector<std::string> labels_forward = {
    values::pacman_moving_anim_0,
    values::pacman_default,
    values::pacman_moving_anim_1,
    values::pacman_default,
  };

  return GetMovingAnimation(p_view_api, 
                            animation_label, 
                            labels_forward, 
                            sprite_repository, 
                            std::move(p_active_label_provider));
}


std::unique_ptr<IAnimationRenderConfig> PacManAnimationConfigRepository::ConstructBackwardMovingAnimation(
    view::IViewAPI* p_view_api,
    const std::string& unique_label_id,
    const PacManSpriteConfigRepository& sprite_repository,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) const {
  const std::string animation_label = values::pacman_moving_anim_back + unique_label_id;

  std::vector<std::string> labels_backward = {
    values::pacman_default,
    values::pacman_moving_anim_1,
    values::pacman_default,
    values::pacman_moving_anim_0,
  };

  return GetMovingAnimation(p_view_api, 
                            animation_label, 
                            labels_backward, 
                            sprite_repository, 
                            std::move(p_active_label_provider));
}
  
}
}
}
}
