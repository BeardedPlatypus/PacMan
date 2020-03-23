#include "pch.h"
#include "entity/render/AnimationPositionProvider.h"

#include "CommonSpriteValues.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

AnimationPositionProvider::AnimationPositionProvider(std::unique_ptr<GetAxiiContainer> p_axii_container) :
    _p_axii_container(std::move(p_axii_container)) { }


inline float AnimationPositionProvider::GetXPosition(float scale) const {
  return (this->_p_axii_container->GetXAxis()->GetPosition() - 0.5F * 0.5F) *
         (float) values::tile_size * scale;
}


inline float AnimationPositionProvider::GetYPosition(float scale, float render_offset) const {
  return (this->_p_axii_container->GetYAxis()->GetPosition() - 0.5F * 0.5F) *
         (float)values::tile_size * scale + render_offset * scale;
}

}
}
}
}
