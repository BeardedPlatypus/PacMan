#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <vector>
#include "sprite/Sprite.h"


namespace pacman {
namespace view {

/// <summary>
/// The ISpriteAnimation defines the container for multiple sprites which are
/// played with a specified time per frame. The ISpriteAnimation can be updated
/// with a dTime. This will move the internal clock forward.
/// When <see cref="getActiveSprite" /> is retrieved, the currently active
/// <see cref="Sprite" /> is retrieved based upon the time per frame and the
/// current internally stored time.
/// </summary>
class DllExport ISpriteAnimation {
public:
  /// <summary>
  /// Construct a new <see cref="ISpriteAnimation"/>.
  /// </summary>
  /// <param name="time_per_frame"> The time per frame. </param>
  /// <param name="sprites"> The set of sprites to be rendered as a sequence. </param>
  static std::unique_ptr<ISpriteAnimation> Construct(float time_per_frame,
  				                                           const std::vector<std::reference_wrapper<const Sprite>>& sprites);

  virtual ~ISpriteAnimation() {}

  /// <summary>
  /// Update this ISpriteAnimation with the specified delta time.
  /// </summary>
  /// <param name="d_time">The d time.</param>
  /// <post-condition>
  ///   (new this)->getExactTime() == this->getCurrentTime() + d_time
  /// </post-condition>
  virtual void updateTime(float d_time) = 0;
	
  /// <summary>
  /// Resets the time of this ISpriteAnimation back to zero.
  /// </summary>
  /// <post-condition>
  ///   (new this)->getExactTime() == 0.0
  /// </post-condition>
  virtual void resetTime() = 0;
	
  /// <summary>
  /// Get the current time of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The current time of this <see cref="ISpriteAnimation" />. 
  /// </returns>
  virtual float getExactTime() const = 0;
  
  /// <summary>
  /// Set the time to the exact value of <paramref name=new_time>.
  /// </summary>
  /// <param name="new_time">The new time.</param>
  /// <post-condition>
  ///   (new this)->getExactTime() == new_time
  /// </ post-condition>
  virtual void setExactTime(float new_time) = 0;

  /// <summary>
  /// Get the time relative to the provided time per frame.
  /// </summary>
  /// <returns>
  /// The time as stored within this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual float getInternalTime() const = 0;

  /// <summary>
  /// Set the current time relative to the frames per second to the specified 
  /// time within the range [0..getNFrames()].
  /// </summary>
  /// <param name="new_time">The new relative time.</param>
  /// <post-condition>
  /// (new this)->getInternalTime() == <paramref name="new_time />
  /// </post-condition>
  virtual void setInternalTime(float new_time) = 0;
 
  /// <summary>
  /// Gets the number frames of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The number of frames of this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual int getNFrames() const = 0;
  
  /// <summary>
  /// Get the frames per second of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns> 
  /// The frames per second of this <see cref="ISpriteAnimation" /> 
  /// </returns>
  virtual inline float getFramesPerSecond() const = 0;
  
  /// <summary>
  /// Get the seconds per frame of this <see cref="ISpriteAnimation" />.
  /// </summary>
  /// <returns>
  /// The number of seconds per frame of this <see cref="ISpriteAnimation" />.
  /// </returns>
  virtual float getTimePerFrame() const = 0;
	
  /// <summary>
  /// Get the current active sprite of this animation.
  /// </summary>
  /// <returns> The current active sprite. </returns>
  virtual const Sprite& getActiveSprite() const = 0;
	
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
