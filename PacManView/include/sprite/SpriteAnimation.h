#pragma once

#include "sprite/ISpriteAnimation.h"
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
class SpriteAnimation final : public ISpriteAnimation {
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

  void updateTime(float d_time) final;
  void resetTime() final;
  inline float getExactTime() const final;
  inline void setExactTime(float new_time) final;
  inline float getInternalTime() const final { return this->_internal_cur_time; }
  void setInternalTime(float new_time) final;
  inline int getNFrames() const final { return this->_n_frames; }
  inline float getFramesPerSecond() const final { return this->_frames_per_second; }
  inline float getTimePerFrame() const final { return this->_seconds_per_frame; }
  const Sprite& getActiveSprite() const final;
  std::unique_ptr<ISpriteAnimation> DeepClone() const final;

private:	
  /// <summary> 
  /// The set of sprites of this animation. 
  ///</summary>
  const std::vector<std::reference_wrapper<const Sprite>> _animation_sprites;	

  /// <summary> 
  /// The time per frame. 
  /// </summary>
  const float _frames_per_second;
  
  /// <summary>
  /// The number of frames per time
  /// </summary>
  const float _seconds_per_frame;

  /// <summary> 
  /// The current internal time of this animation. 
  /// </summary>
  float _internal_cur_time = 0.F;
  
  /// <summary> 
  /// The n frames of this <see cref="SpriteAnimation />. 
  /// </summary>
  const int _n_frames;
};

}
}