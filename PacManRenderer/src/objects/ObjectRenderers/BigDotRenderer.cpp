#include "pch.h"
#include "objects/ObjectRenderers/BigDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"


namespace pacman {
namespace renderer {
namespace objects {

float BigDotRenderer::CalculateLocation(int val, float scale) const {
  return (float) val * (float) values::tile_size * scale;
}


void BigDotRenderer::RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const {
  p_view_api->RenderSprite(values::object_sprite_big_dot,
                           this->CalculateLocation(x, scale), 
                           this->CalculateLocation(y, scale),
                           scale);
}


}
}
}