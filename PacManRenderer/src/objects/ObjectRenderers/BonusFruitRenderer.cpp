#include "pch.h"
#include "objects/ObjectRenderers/BonusFruitRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"


namespace pacman {
namespace renderer {
namespace objects {

BonusFruitRenderer::BonusFruitRenderer(view::IViewAPI* p_view_api,
                                       const state::level::ILevelManager* p_level_manager) : 
    _p_view_api(p_view_api),
    _p_level_manager(p_level_manager) { }


void BonusFruitRenderer::Initialise() {
  this->_p_view_api->RequestSprite(values::object_sprite_bonus_cherry,
                                   values::bonus_sprite_file,
                                   0 * values::bonus_tile_size,
                                   0 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_strawberry,
                                   values::bonus_sprite_file,
                                   1 * values::bonus_tile_size,
                                   0 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_orange,
                                   values::bonus_sprite_file,
                                   2 * values::bonus_tile_size,
                                   0 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_apple,
                                   values::bonus_sprite_file,
                                   3 * values::bonus_tile_size,
                                   0 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_melon,
                                   values::bonus_sprite_file,
                                   0 * values::bonus_tile_size,
                                   1 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_galaxy_boss,
                                   values::bonus_sprite_file,
                                   1 * values::bonus_tile_size,
                                   1 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_bell,
                                   values::bonus_sprite_file,
                                   2 * values::bonus_tile_size,
                                   1 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);

  this->_p_view_api->RequestSprite(values::object_sprite_bonus_key,
                                   values::bonus_sprite_file,
                                   3 * values::bonus_tile_size,
                                   1 * values::bonus_tile_size,
                                   values::bonus_tile_size,
                                   values::bonus_tile_size);
}


float BonusFruitRenderer::CalculateLocation(int val, float scale) const {
  return ((float) val * (float) values::tile_size - 3.F) * scale;

}


const std::string& BonusFruitRenderer::GetBonusFruitSprite() const {
  if (this->_p_level_manager->GetCurrentLevel() < 1) {
    return values::object_sprite_bonus_cherry;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 2) {
    return values::object_sprite_bonus_strawberry;
  }
  
  if (this->_p_level_manager->GetCurrentLevel() < 3) {
    return values::object_sprite_bonus_orange;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 5) {
    return values::object_sprite_bonus_apple;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 7) {
    return values::object_sprite_bonus_melon;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 9) {
    return values::object_sprite_bonus_galaxy_boss;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 11) {
    return values::object_sprite_bonus_bell;
  }

  return values::object_sprite_bonus_key;

}


void BonusFruitRenderer::RenderObject(int x, int y, float scale, float render_offset_y) const {
  this->_p_view_api->RenderSprite(this->GetBonusFruitSprite(),
                                  this->CalculateLocation(x, scale), 
                                  this->CalculateLocation(y, scale) + scale * render_offset_y,
                                  scale * 0.75F);
}

}
}
}
