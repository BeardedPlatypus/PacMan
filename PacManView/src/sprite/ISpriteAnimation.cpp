#include "stdafx.h"
#include "sprite/ISpriteAnimation.h"

#include "sprite/SpriteAnimation.h"

namespace pacman {
namespace view {

std::unique_ptr<ISpriteAnimation> ISpriteAnimation::Construct(float time_per_frame,
  				                                                    const std::vector<std::reference_wrapper<const Sprite>>& sprites) {
	return std::make_unique<SpriteAnimation>(time_per_frame, sprites);
}

}
}
