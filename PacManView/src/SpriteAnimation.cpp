#include "stdafx.h"
#include "SpriteAnimation.h"

#include <math.h>

namespace pacman {
namespace view {

SpriteAnimation::SpriteAnimation(float time_per_frame,
								 const std::vector<std::reference_wrapper<const Sprite>>& sprites) :
	frames_per_second(1.0 / time_per_frame), 
	animation_sprites(std::vector<std::reference_wrapper<const Sprite>>(sprites)),
	n_frames(sprites.size()),
	cur_time(0.0F) { }


void SpriteAnimation::updateTime(float d_time) {
	this->cur_time += (d_time * this->frames_per_second);

	if (cur_time > this->n_frames) {
		cur_time = fmod(cur_time, this->n_frames);
	}
}


const Sprite& SpriteAnimation::getActiveSprite() const {
	return this->animation_sprites.at(floorf(this->cur_time));
}


SpriteAnimation SpriteAnimation::DeepClone() const {
	return SpriteAnimation(1.0 / this->frames_per_second,
						   this->animation_sprites);
}

} // view
} // pacman