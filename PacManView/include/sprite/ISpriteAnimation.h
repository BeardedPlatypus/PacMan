#pragma once

#include <memory>
#include <vector>
#include "sprite/Sprite.h"


namespace pacman {
namespace view {

/// <summary>
/// The <see cref="ISpriteAnimation"/> defines the container for multiple sprites which are
/// shown with a specified time per frame. The <see cref="ISpriteAnimation"/> can be updated
/// with a dTime. This will move the internal clock forward. When <see cref="GetActiveSprite"/>
/// is retrieved, the currently active <see cref="Sprite"/> is retrieved based upon the 
/// time per frame and the current internally stored time.
/// </summary>
class ISpriteAnimation {
public:
  /// <summary>
  /// Construct a new <see cref="ISpriteAnimation"/>.
  /// </summary>
  /// <param name="time_per_frame"> The time per frame. </param>
  /// <param name="sprites"> The set of sprites to be rendered as a sequence. </param>
  static std::unique_ptr<ISpriteAnimation> Construct(float time_per_frame,
  				                                           const std::vector<std::reference_wrapper<const Sprite>>& sprites);

  virtual ~ISpriteAnimation() = default;

  /// <summary>
  /// Update this <see cref="ISpriteAnimation"/> with the specified delta time.
  /// </summary>
  /// <param name="d_time"> The delta time. </param>
  /// <post-condition>
  ///   (new this)->GetExactTime() == this->GetCurrentTime() + d_time
  /// </post-condition>
  virtual void UpdateTime(float d_time) = 0;
	
  /// <summary>
  /// Resets the time of this <see cref="ISpriteAnimation"/> back to zero.
  /// </summary>
  /// <post-condition>
  ///   (new this)->GetExactTime() == 0.0
  /// </post-condition>
  virtual void ResetTime() = 0;
	
  /// <summary>
  /// Get the current time of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The current time of this <see cref="ISpriteAnimation" />. 
  /// </returns>
  virtual float GetExactTime() const = 0;
  
  /// <summary>
  /// Set the time to the exact value of <paramref name=new_time>.
  /// </summary>
  /// <param name="new_time"> The new time. </param>
  /// <post-condition>
  ///   (new this)->getExactTime() == new_time
  /// </ post-condition>
  virtual void SetExactTime(float new_time) = 0;

  /// <summary>
  /// Get the time relative to the provided time per frame.
  /// </summary>
  /// <returns>
  /// The time as stored within this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual float GetInternalTime() const = 0;

  /// <summary>
  /// Set the current time relative to the frames per second to the specified 
  /// time within the range [0..this->GetNFrames()].
  /// </summary>
  /// <param name="new_time"> The new relative time. </param>
  /// <post-condition>
  /// (new this)->GetInternalTime() == <paramref name="new_time />
  /// </post-condition>
  virtual void SetInternalTime(float new_time) = 0;
 
  /// <summary>
  /// Get the number frames of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The number of frames of this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual int GetNFrames() const = 0;
  
  /// <summary>
  /// Get the frames per second of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The frames per second of this <see cref="ISpriteAnimation" /> 
  /// </returns>
  virtual float GetFramesPerSecond() const = 0;
  
  /// <summary>
  /// Get the seconds per frame of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns>
  /// The number of seconds per frame of this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual float GetTimePerFrame() const = 0;
	
  /// <summary>
  /// Get the current active sprite of this animation.
  /// </summary>
  /// <returns> The current active sprite. </returns>
  virtual const Sprite& GetActiveSprite() const = 0;
	
  /// <summary>
  /// Create a deep clone of this <see cref="SpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// A deep clone of this <see cref="ISpriteAnimation" /> returned as a 
  /// <see cref="std::unique_ptr"/>.
  /// </returns>
  virtual std::unique_ptr<ISpriteAnimation> DeepClone() const = 0;
};

}
}
