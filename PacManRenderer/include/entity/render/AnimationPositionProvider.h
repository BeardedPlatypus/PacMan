#pragma once

#include "entity/render/IAnimationPositionProvider.h"
#include "entity/render/GetAxiiContainer.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IAnimationPositionProvider"/> provides the GetXPosition and 
/// GetYPosition with which the positions to render the entity with can be
/// obtained.
/// </summary>
class AnimationPositionProvider final : public IAnimationPositionProvider {
public:  
  /// <summary>
  /// Creates a new <see cref="AnimationPositionProvider"/>.
  /// </summary>
  /// <param name="p_axii_container">A pointer to the observed <see cref="GetAxiiContainer"/>.</param>
  explicit AnimationPositionProvider(std::unique_ptr<GetAxiiContainer> p_axii_container);

  float GetXPosition(float scale) const final;
  float GetYPosition(float scale, float render_offset) const final;

private:
  std::unique_ptr<GetAxiiContainer> _p_axii_container;
};

}
}
}
}

