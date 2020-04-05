#include "pch.h"
#include "entity/animation/AnimationRenderConfig.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

AnimationRenderConfig::AnimationRenderConfig(view::IViewAPI* p_view_api,
                                             const std::string& animation_label,
                                             float time_per_frame,
                                             const std::vector<std::string>& animation_frame_labels,
                                             const std::vector<std::shared_ptr<SpriteRenderConfig>>& sprites,
                                             std::unique_ptr<IAnimationUpdateBehaviour> p_animation_update_behaviour) :
    _p_view_api(p_view_api),
    _animation_label(animation_label),
    _time_per_frame(time_per_frame),
    _animation_frame_labels(animation_frame_labels),
    _sprites(sprites),
    _p_animation_update_behaviour(std::move(p_animation_update_behaviour)) { }


inline std::string AnimationRenderConfig::GetLabel() const { 
  return this->_animation_label; 
}


void AnimationRenderConfig::Initialise() {
  for (const std::shared_ptr<SpriteRenderConfig>& config : this->_sprites)
    InitialiseSprite(*config);

  this->InitialiseSpriteAnimation();
}


inline void AnimationRenderConfig::InitialiseSprite(const SpriteRenderConfig& sprite_config) {
  if (this->_p_view_api->HasSprite(sprite_config.GetSpriteLabel())) return;

  this->_p_view_api->RequestSprite(sprite_config.GetSpriteLabel(),
                                   sprite_config.GetTextureFilePath(),
                                   sprite_config.GetX(),
                                   sprite_config.GetY(),
                                   sprite_config.GetW(),
                                   sprite_config.GetH());
}


inline void AnimationRenderConfig::InitialiseSpriteAnimation() {
  this->_p_view_api->RequestSpriteAnimation(this->_animation_label,
                                            this->_time_per_frame,
                                            this->_animation_frame_labels);
}


inline void AnimationRenderConfig::Update(float dtime) {
  this->_p_animation_update_behaviour->Update(dtime);
}

inline void AnimationRenderConfig::Reset() {
  this->_p_view_api->ResetAnimationTime(this->GetLabel());
}

}
}
}
}
