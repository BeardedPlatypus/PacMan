#pragma once
#define DllExport __declspec( dllexport )

#include <vector>

#include "Sprite.h"


namespace pacman {
namespace view {

/// <summary>
/// The SpriteAnimation provides a container for multiple sprites which are
/// played with a specified time per frame. The SpriteAnimation can be updated
/// with a dTime. This will move the internal clock forward.
/// When <see cref="getActiveSprite" /> is retrieved, the currently active
/// <see cref="Sprite" /> is retrieved based upon the time per frame and the
/// current internally stored time.
/// </summary>
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
	/// <post-condition>
	///   (new this)->getCurrentTime() == this->getCurrentTime() + d_time
	/// </post-condition>
	void updateTime(float d_time);
	
	/// <summary>
	/// Resets the time of this SpriteAnimation back to zero.
	/// </summary>
	/// <post-condition>
	///   (new this)->getCurrentTime() == 0.0
	/// </post-condition>
	void resetTime() { this->cur_time = 0.f; }
	
	/// <summary>
	/// Get the current time of this <see cref="SpriteAnimation" />.
	/// </summary>
	/// <returns> The current time of this <see cref="SpriteAnimation" />. </returns>
	inline float getCurrentTime() const { return this->cur_time; }

  /// <summary>
  /// Sets the current time to the specified time.
  /// </summary>
  /// <param name="new_time">The new time.</param>
  /// <post-condition>
  /// (new this)->getCurrentTime() == <paramref name="new_time />
  /// </post-condition>
  inline void setCurrentTimeTo(float new_time) { this->cur_time = new_time; }
	
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
  const float frames_per_second;

  /// <summary> The current time of this animation. </summary>
  float cur_time;
  
  /// <summary> The n frames of this <see cref="SpriteAnimation />. </summary>
  const int n_frames;
};

}
}