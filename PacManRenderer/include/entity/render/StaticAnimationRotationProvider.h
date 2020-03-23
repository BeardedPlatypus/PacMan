#pragma once

#include "entity/render/IAnimationRotationProvider.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="StaticAnimationRotationProvider"/> provides
/// a static rotation of a sprite.
/// </summary>
class StaticAnimationRotationProvider final : public IAnimationRotationProvider {
public:  
  /// <summary>
  /// Crates a new <see cref="StaticAnimationRotationProvider"/>.
  /// </summary>
  /// <param name="rotation_value">The rotation value to return.</param>
  explicit StaticAnimationRotationProvider(float rotation_value);
  
  /// <summary>
  /// Gets the rotation of this animation.
  /// </summary>
  /// <returns>
  /// The rotation
  /// </returns>
  float GetRotation() const;

private:
  const float _rotation_value;
};

}
}
}
}
