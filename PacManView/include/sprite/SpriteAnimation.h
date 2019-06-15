#pragma once
#define DllExport __declspec( dllexport )

#include <vector>

#include "sprite/Sprite.h"


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
  /// <post-condition>
  /// (new this)->getNFrames() == <paramref name="sprites">.size()
  /// (new this)->getCurrentTime() == 0.f
  /// </post-condition>
  SpriteAnimation(float time_per_frame,
  				const std::vector<std::reference_wrapper<const Sprite>>& sprites);

  /// <summary>
  /// Update this SpriteAnimation with the specified delta time.
  /// </summary>
  /// <param name="d_time">The d time.</param>
  /// <post-condition>
  ///   (new this)->getExactTime() == this->getCurrentTime() + d_time
  /// </post-condition>
  void updateTime(float d_time);
	
  /// <summary>
  /// Resets the time of this SpriteAnimation back to zero.
  /// </summary>
  /// <post-condition>
  ///   (new this)->getExactTime() == 0.0
  /// </post-condition>
  void resetTime();
	
  /// <summary>
  /// Get the current time of this <see cref="SpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The current time of this <see cref="SpriteAnimation" />. 
  /// </returns>
  inline float getExactTime() const;
  
  /// <summary>
  /// Set the time to the exact value of <paramref name=new_time>.
  /// </summary>
  /// <param name="new_time">The new time.</param>
  /// <post-condition>
  ///   (new this)->getExactTime() == new_time
  /// </ post-condition>
  inline void setExactTime(float new_time);

  /// <summary>
  /// Get the time relative to the provided time per frame.
  /// </summary>
  /// <returns>
  /// The time as stored within this <see cref="SpriteAnimation" />.
  /// </returns>
  inline float getInternalTime() const { return this->internal_cur_time; }

  /// <summary>
  /// Set the current time relative to the frames per second to the specified 
  /// time within the range [0..getNFrames()].
  /// </summary>
  /// <param name="new_time">The new relative time.</param>
  /// <post-condition>
  /// (new this)->getInternalTime() == <paramref name="new_time />
  /// </post-condition>
  void setInternalTime(float new_time);
 
  /// <summary>
  /// Gets the number frames of this <see cref="SpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The number of frames of this <see cref="SpriteAnimation" />.
  /// </returns>
  inline int getNFrames() const { return this->n_frames; }
  
  /// <summary>
  /// Get the frames per second of this <see cref="SpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The frames per second of this <see cref="SpriteAnimation" /> 
  /// </returns>
  inline float getFramesPerSecond() const { return this->frames_per_second; }
  
  /// <summary>
  /// Get the seconds per frame of this <see cref="SpriteAnimation" />.
  /// </summary>
  /// <returns>
  /// The number of seconds per frame of this <see cref="SpriteAnimation" />.
  /// </returns>
  inline float getTimePerFrame() const { return this->seconds_per_frame; }
	
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
  /// <summary> 
  /// The set of sprites of this animation. 
  ///</summary>
  const std::vector<std::reference_wrapper<const Sprite>> animation_sprites;	

  /// <summary> 
  /// The time per frame. 
  /// </summary>
  const float frames_per_second;
  
  /// <summary>
  /// The number of frames per time
  /// </summary>
  const float seconds_per_frame;

  /// <summary> 
  /// The current internal time of this animation. 
  /// </summary>
  float internal_cur_time;
  
  /// <summary> 
  /// The n frames of this <see cref="SpriteAnimation />. 
  /// </summary>
  const int n_frames;
};

}
}