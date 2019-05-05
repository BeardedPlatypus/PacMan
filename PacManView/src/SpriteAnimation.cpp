#include "stdafx.h"
#include "SpriteAnimation.h"

#include <math.h>

namespace pacman {
namespace view {

SpriteAnimation::SpriteAnimation(float time_per_frame,
								 const std::vector<std::reference_wrapper<const Sprite>>& sprites) :
	time_per_frame(time_per_frame), 
	animation_sprites(std::vector<std::reference_wrapper<const Sprite>>(sprites)),
	cur_time(0.0F) { }


void SpriteAnimation::update(float d_time) {
	this->cur_time = fmod(cur_time + (d_time / this->time_per_frame), this->animation_sprites.size());
}


const Sprite& SpriteAnimation::getActiveSprite() const {
	return this->animation_sprites.at(floorf(this->cur_time));
}


SpriteAnimation SpriteAnimation::DeepClone() const {
	return SpriteAnimation(this->time_per_frame,
						   this->animation_sprites);
}

} // view
} // pacman