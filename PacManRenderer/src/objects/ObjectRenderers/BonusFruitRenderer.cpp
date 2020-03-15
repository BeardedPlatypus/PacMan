#include "pch.h"
#include "objects/ObjectRenderers/BonusFruitRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"


namespace pacman {
namespace renderer {
namespace objects {

BonusFruitRenderer::BonusFruitRenderer(view::IViewAPI* p_view_api) : 
    _p_view_api(p_view_api) { }


void BonusFruitRenderer::Initialise() {
  this->_p_view_api->RequestSprite(values::object_sprite_bonus_cherry,
                                   values::bonus_sprite_file,
                                   0,
                                   0,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);
}


float BonusFruitRenderer::CalculateLocation(int val, float scale) const {
  return ((float) val * (float) values::tile_size - 3.F) * scale;

}


void BonusFruitRenderer::RenderObject(int x, int y, float scale, float render_offset_y) const {
  this->_p_view_api->RenderSprite(values::object_sprite_bonus_cherry,
                                  this->CalculateLocation(x, scale), 
                                  this->CalculateLocation(y, scale) + scale * render_offset_y,
                                  scale * 0.75F);
}

}
}
}
