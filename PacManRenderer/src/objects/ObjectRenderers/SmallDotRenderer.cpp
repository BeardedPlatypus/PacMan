#include "pch.h"
#include "objects/ObjectRenderers/SmallDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"


namespace pacman {
namespace renderer {
namespace objects {

float SmallDotRenderer::CalculateLocation(int val, float scale) const {
  int additional_offset = (values::tile_size - values::small_dot_tile_size) / 2;
  return ((float) val * (float) values::tile_size + (float) additional_offset ) * scale;

}


void SmallDotRenderer::RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale, float render_offset_y) const {
  p_view_api->RenderSprite(values::object_sprite_small_dot,
                           this->CalculateLocation(x, scale), 
                           this->CalculateLocation(y, scale) + scale * render_offset_y,
                           scale);
}


}
}
}
