#pragma once
#define DllExport __declspec( dllexport )

#include <vector>

#include "Sprite.h"

namespace pacman {
namespace view {

class DllExport SpriteAnimation {
public:
	SpriteAnimation(float time_per_frame, 
					const std::vector<std::reference_wrapper<const Sprite>>& sprites);
	
	/// <summary>
	/// Update this SpriteAnimation with the specified delta time.
	/// </summary>
	/// <param name="d_time">The d time.</param>
	void update(float d_time);
	
	/// <summary>
	/// Get the current active sprite of this animation.
	/// </summary>
	/// <returns> The current active sprite. </returns>
	const Sprite& getActiveSprite() const;

	SpriteAnimation DeepClone() const;

private:	
	/// <summary> The set of sprites of this animation. </summary>
	const std::vector<std::reference_wrapper<const Sprite>> animation_sprites;	
	/// <summary> The time per frame. </summary>
	const float time_per_frame;

	/// <summary> The current time of this animation. </summary>
	float cur_time;
};

}
}