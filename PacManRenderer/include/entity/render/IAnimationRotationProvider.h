#pragma once

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IAnimationRotationProvider"/> defines the 
/// rotation of a sprite.
/// </summary>
class IAnimationRotationProvider {
public:
  virtual ~IAnimationRotationProvider() = default;
  
  /// <summary>
  /// Gets the rotation of this animation.
  /// </summary>
  /// <returns>
  /// The rotation
  /// </returns>
  virtual float GetRotation() const = 0;
};

}
}
}
}
