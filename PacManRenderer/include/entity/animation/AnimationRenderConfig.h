#pragma once

#include <memory>
#include <vector>
#include <string>

#include "entity/animation/IAnimationRenderConfig.h"
#include "entity/animation/IAnimationUpdateBehaviour.h"
#include "entity/animation/SpriteRenderConfig.h"

#include "IViewAPI.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cerf="AnimationRenderConfig"/> contains all relevant data to
/// render a single animation.
/// </summary>
class AnimationRenderConfig final : public IAnimationRenderConfig {
public:  
  /// <summary>
  /// Creates a new <see cref="AnimationRenderConfig"/>.
  /// </summary>
  /// <param name="animation_label">The animation label.</param>
  /// <param name="animation_frame_labels">The animation frame labels.</param>
  /// <param name="sprites">The sprite configurations.</param>
  /// <param name="p_animation_update_behaviour">A pointer to the animation update behaviour.</param>
  AnimationRenderConfig(view::IViewAPI* p_view_api,
                        const std::string animation_label,
                        float time_per_frame,
                        const std::vector<std::string>& animation_frame_labels,
                        const std::vector<std::shared_ptr<SpriteRenderConfig>>& sprites,
                        const std::unique_ptr<IAnimationUpdateBehaviour> p_animation_update_behaviour);
  
  std::string GetLabel() const final;
  void Initialise() final;
  void Update(float dtime) final;
  void Reset() final;

private:  
  /// <summary>
  /// Initialises the sprite defined with <paramref name="sprite_config" />.
  /// </summary>
  /// <param name="sprite_config">The sprite configuration.</param>
  /// <remarks>
  /// This will not call anything if a sprite with the provided name already exists.
  /// </remarks>
  void InitialiseSprite(const SpriteRenderConfig& sprite_config);
  void InitialiseSpriteAnimation();

  view::IViewAPI* _p_view_api;

  const std::string _animation_label;
  float _time_per_frame;
  const std::vector<std::string> _animation_frame_labels;
  const std::vector<std::shared_ptr<SpriteRenderConfig>> _sprites;
  std::unique_ptr<IAnimationUpdateBehaviour> _p_animation_update_behaviour;
};

}
}
}
}
