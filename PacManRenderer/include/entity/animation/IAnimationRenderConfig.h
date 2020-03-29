#pragma once

#include <string>

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="IAnimationRenderConfig"/> defines the interface
/// to store a single animation to be used within a render entity.
/// It defines the required initialisation and the update method.
/// </summary>
class IAnimationRenderConfig {
public:  
  /// <summary>
  /// Gets the label of this <see cref="IAnimationRenderConfig"/>.
  /// </summary>
  /// <returns>
  /// The label of this <see cref="IAnimationRenderConfig"/>.
  /// </returns>
  virtual std::string GetLabel() const = 0;

  /// <summary>
  /// Initialises this <see cref="IAnimationRenderConfig"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Updates this <see cref="IAnimationRenderConfig"/> with the
  /// elapsed time since the last update.
  /// </summary>
  /// <param name="dtime">The elapsed time since the last update.</param>
  virtual void Update(float dtime) = 0;
  
  /// <summary>
  /// Resets this animation.
  /// </summary>
  virtual void Reset() = 0;
};

}
}
}
}
