#pragma once
#define DllExport __declspec( dllexport )

#include <vector>

#include "Sprite.h"

namespace pacman {
namespace view {

class DllExport SpriteAnimation {
public:	
	/// <summary>
	/// Construct a new <see cref="SpriteAnimation"/>.
	/// </summary>
	/// <param name="time_per_frame"> The time per frame. </param>
	/// <param name="sprites"> The set of sprites to be rendered as a sequence. </param>
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
	
	/// <summary>
	/// Create a deep clone of this <see cref="SpriteAnimation" />.
	/// </summary>
	/// <returns> A deep clone of this <see cref="SpriteAnimation" />. </returns>
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