#include "pch.h"
#include "field/FieldLayer.h"

#include <utility>

#include "CommonSpriteValues.h"
#include "field/FieldSpriteValues.h"
#include "field/FieldLayerHelper.h"


namespace pacman {
namespace renderer {

FieldLayer::FieldLayer(float scale,
                       view::IViewAPI* p_view_api,
                       state::field::IField* p_field) :
    scale(scale),
    p_view_api(p_view_api),
    p_field(p_field) { }


void FieldLayer::Initialise() {
  this->InitialiseSprites();
  this->InitialiseRenderField();
}


void FieldLayer::InitialiseSprites() {
  this->p_view_api->RequestSprite(values::field_sprite_straight,
                                  values::field_sprite_file,
                                  0, 0, values::tile_size, values::tile_size);

  this->p_view_api->RequestSprite(values::field_sprite_corner,
                                  values::field_sprite_file,
                                  values::tile_size, 0, values::tile_size, values::tile_size);

  this->p_view_api->RequestSprite(values::field_sprite_end,
                                  values::field_sprite_file,
                                  values::tile_size * 2, 0, values::tile_size, values::tile_size);

  this->p_view_api->RequestSprite(values::field_sprite_junction,
                                  values::field_sprite_file,
                                  values::tile_size * 3, 0, values::tile_size, values::tile_size);

  this->p_view_api->RequestSprite(values::field_sprite_gate_connect,
                                  values::field_sprite_file,
                                  0, values::tile_size, values::tile_size, values::tile_size);

  this->p_view_api->RequestSprite(values::field_sprite_gate,
                                  values::field_sprite_file,
                                  values::tile_size, values::tile_size, values::tile_size, values::tile_size);
}


void FieldLayer::InitialiseRenderField() {
  std::vector<unsigned int> field_values = FieldLayerHelper::CalculateFieldVisualisation(this->p_field);
  int x_dim = p_field->GetXDimension();

  for (auto j = 0; j < this->p_field->GetYDimension(); j++) {
    for (auto i = 0; i < x_dim; i++) {
      int index = i + j * x_dim;
      FieldSpriteDescription description = FieldLayerHelper::FieldValueToSpriteType(field_values[index]);

      if (description.SpriteType == FieldSpriteType::Undefined) 
        continue;

      this->p_sprite_map->try_emplace(description.SpriteType,
                                      std::make_unique<std::vector<FieldLayerSpriteDescription>>());

      this->p_sprite_map->at(description.SpriteType)->push_back(FieldLayerSpriteDescription(i, j, description.Orientation));
    }
  }
}


void FieldLayer::Render() const {
  std::pair<FieldSpriteType, std::string> sprite_types[] = 
  { 
    std::pair(FieldSpriteType::Corner,      values::field_sprite_corner),
    std::pair(FieldSpriteType::End,         values::field_sprite_end),
    std::pair(FieldSpriteType::Gate,        values::field_sprite_gate),
    std::pair(FieldSpriteType::GateConnect, values::field_sprite_gate_connect),
    std::pair(FieldSpriteType::Junction,    values::field_sprite_junction),
    std::pair(FieldSpriteType::Straight,    values::field_sprite_straight),
  };

  for (auto val : sprite_types) {
    for (auto sprite_def : *(this->p_sprite_map->at(val.first))) {
      this->p_view_api->RenderSprite(val.second,
                                     sprite_def.x * (float) values::tile_size * this->scale,
                                     sprite_def.y * (float) values::tile_size * this->scale,
                                     this->scale, 
                                     sprite_def.Orientation.Rotation,
                                     sprite_def.Orientation.IsFlippedX,
                                     sprite_def.Orientation.IsFlippedY);
    }
  }
}

}
}
