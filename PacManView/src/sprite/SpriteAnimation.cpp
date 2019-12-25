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


void SpriteAnimation::updateTime(float d_time) {
	float new_time = this->getInternalTime() + (d_time * this->getFramesPerSecond());
	this->setInternalTime(new_time);
}


void SpriteAnimation::resetTime() {
  this->setInternalTime(0.F);
}


inline float SpriteAnimation::getExactTime() const {
  return this->getInternalTime() * this->getTimePerFrame();
}


inline void SpriteAnimation::setExactTime(float new_time) {
  this->setInternalTime(new_time * this->getFramesPerSecond());

}


void SpriteAnimation::setInternalTime(float new_time) {
	float n_frames = (float) this->getNFrames();
  if (new_time > n_frames) {
    new_time = (float) fmod(new_time, n_frames);
  }
  
  this->_internal_cur_time = new_time; 
}


const Sprite& SpriteAnimation::getActiveSprite() const {
	return this->_animation_sprites.at((size_t) floorf(this->getInternalTime()));
}


std::unique_ptr<ISpriteAnimation> SpriteAnimation::DeepClone() const {
	return ISpriteAnimation::Construct(this->getTimePerFrame(),
						                         this->_animation_sprites);
}

} // view
} // pacman