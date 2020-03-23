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
  /// <param name="scale">The scale with which to render.</param>
  /// <returns>
  /// The x-position to render the entity at.
  /// </returns>
  virtual float GetXPosition(float scale) const = 0;

  /// <summary>
  /// Get the x position to render the entity at.
  /// </summary>
  /// <param name="scale">The scale with which to render.</param>
  /// <param name="render_offset">The offset in game space.</param>
  /// <returns>
  /// The y-position to render the entity at.
  /// </returns>
  virtual float GetYPosition(float scale,
                             float render_offset) const = 0;
};

}
}
}
}
