#pragma once

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IAnimationPositionProvider"/> defines the GetXPosition and 
/// GetYPosition with which the positions to render the entity with can be
/// obtained.
/// </summary>
class IAnimationPositionProvider {
public:
  virtual ~IAnimationPositionProvider() = default;

  /// <summary>
  /// Get the x-position to render the entity at.
  /// </summary>
  /// <returns>
  /// The x-position to render the entity at.
  /// </returns>
  virtual float GetXPosition() const = 0;

  /// <summary>
  /// Get the x position to render the entity at.
  /// </summary>
  /// <returns>
  /// The y-position to render the entity at.
  /// </returns>
  virtual float GetYPosition() const = 0;
};

}
}
}
}
