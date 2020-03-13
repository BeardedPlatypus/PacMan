#include "pch.h"
#include "objects/ObjectRenderers/BigDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"


namespace pacman {
namespace renderer {
namespace objects {

BigDotRenderer::BigDotRenderer(view::IViewAPI* p_view_api) : 
    _p_view_api(p_view_api) { }


void BigDotRenderer::Initialise() {
  this->_p_view_api->RequestSprite(values::object_sprite_big_dot,
                                   values::dots_sprite_file,
                                   0, 0,
                                   values::big_dot_tile_size,
                                   values::big_dot_tile_size);
}


float BigDotRenderer::CalculateLocation(int val, float scale) const {
  return (float) val * (float) values::tile_size * scale;
}


void BigDotRenderer::RenderObject(int x, int y, float scale, float render_offset_y) const {
  this->_p_view_api->RenderSprite(values::object_sprite_big_dot,
                                  this->CalculateLocation(x, scale), 
                                  this->CalculateLocation(y, scale) + scale * render_offset_y,
                                  scale);
}


}
}
}
