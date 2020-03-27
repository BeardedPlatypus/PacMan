#include "stdafx.h"
#include "sprite/SpriteAnimation.h"

#include <math.h>


namespace pacman {
namespace view {

SpriteAnimation::SpriteAnimation(float time_per_frame,
                                 const std::vector<std::reference_wrapper<const Sprite>>& sprites) :
    _animation_sprites(std::vector<std::reference_wrapper<const Sprite>>(sprites)),
    _frames_per_second(1.F / time_per_frame),
    _seconds_per_frame(time_per_frame),
    _n_frames(sprites.size()) { }


void SpriteAnimation::UpdateTime(float d_time) {
	float new_time = this->GetInternalTime() + (d_time * this->GetFramesPerSecond());
	this->SetInternalTime(new_time);
}


void SpriteAnimation::ResetTime() {
  this->SetInternalTime(0.F);
}


inline float SpriteAnimation::GetExactTime() const {
  return this->GetInternalTime() * this->GetTimePerFrame();
}


inline void SpriteAnimation::SetExactTime(float new_time) {
  this->SetInternalTime(new_time * this->GetFramesPerSecond());
}


void SpriteAnimation::SetInternalTime(float new_time) {
	float n_frames = (float) this->GetNFrames();
  if (new_time > n_frames) {
    new_time = (float) fmod(new_time, n_frames);
  } else if (new_time < n_frames) {
    new_time -= n_frames * floorf(new_time / n_frames);
  }
  
  this->_internal_cur_time = new_time; 
}


const Sprite& SpriteAnimation::GetActiveSprite() const {
	return this->_animation_sprites.at((size_t) floorf(this->GetInternalTime()));
}


std::unique_ptr<ISpriteAnimation> SpriteAnimation::DeepClone() const {
	return ISpriteAnimation::Construct(this->GetTimePerFrame(),
						                         this->_animation_sprites);
}

} // view
} // pacman
