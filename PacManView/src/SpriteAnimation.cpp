#include "stdafx.h"
#include "SpriteAnimation.h"

#include <math.h>

namespace pacman {
namespace view {

SpriteAnimation::SpriteAnimation(float time_per_frame,
								 const std::vector<std::reference_wrapper<const Sprite>>& sprites) :
	frames_per_second(1.0 / time_per_frame), 
	seconds_per_frame(time_per_frame), 
	animation_sprites(std::vector<std::reference_wrapper<const Sprite>>(sprites)),
	n_frames(sprites.size()),
	internal_cur_time(0.0F) { }


void SpriteAnimation::updateTime(float d_time) {
	float new_time = this->getInternalTime() + (d_time * this->frames_per_second);
	this->setInternalTime(new_time);
}


void SpriteAnimation::resetTime() {
  this->setInternalTime(0.f);
}


inline float SpriteAnimation::getExactTime() const {
  return this->getInternalTime() * this->getTimePerFrame();
}


inline void SpriteAnimation::setExactTime(float new_time) {
  this->setInternalTime(new_time * this->getFramesPerSecond());

}


void SpriteAnimation::setInternalTime(float new_time) {
	float n_frames = (float) this->getNFrames();
    if (new_time > n_frames)
      new_time = fmod(new_time, n_frames);
  
	 this->internal_cur_time = new_time; 
}


const Sprite& SpriteAnimation::getActiveSprite() const {
	return this->animation_sprites.at(floorf(this->getInternalTime()));
}


SpriteAnimation SpriteAnimation::DeepClone() const {
	return SpriteAnimation(this->getTimePerFrame(),
						   this->animation_sprites);
}

} // view
} // pacman