#include "pch.h"
#include "entity/animation/GhostSpriteConfigRepository.h"
#include "entity/EntitySpriteValues.h"


namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

GhostSpriteConfigRepository::GhostSpriteConfigRepository() {
  this->InitialiseMovingSpriteConfigs();
}


std::vector<std::shared_ptr<animation::SpriteRenderConfig>> GhostSpriteConfigRepository::GetMovingHorizontalSpriteConfigs(state::GhostEntityType ghost_entity_type) const {
  return this->moving_horizontal_sprites.at(ghost_entity_type);
}


std::vector<std::shared_ptr<animation::SpriteRenderConfig>> GhostSpriteConfigRepository::GetMovingUpSpriteConfigs(state::GhostEntityType ghost_entity_type) const {
  return this->moving_up_sprites.at(ghost_entity_type);
}


std::vector<std::shared_ptr<animation::SpriteRenderConfig>> GhostSpriteConfigRepository::GetMovingDownSpriteConfigs(state::GhostEntityType ghost_entity_type) const {
  return this->moving_down_sprites.at(ghost_entity_type);
}


std::shared_ptr<SpriteRenderConfig> GetGhostSpriteConfig(const std::string& label,
  int x,
  int y) {
  return std::make_shared<SpriteRenderConfig>(label,
    values::entity_sprite_file,
    x * values::entity_tile_size,
    y * values::entity_tile_size,
    values::entity_tile_size,
    values::entity_tile_size);
}


void AddSprites(std::unordered_map<state::GhostEntityType, std::vector<std::shared_ptr<SpriteRenderConfig>>, EnumClassHash>& sprite_map,
  state::GhostEntityType ghost_type,
  int row_index,
  int dir_index,
  const std::string& direction_label) {
  std::vector<std::shared_ptr<SpriteRenderConfig>> sprites = {
      GetGhostSpriteConfig(direction_label + "_0", dir_index * 2,     row_index),
      GetGhostSpriteConfig(direction_label + "_1", dir_index * 2 + 1, row_index),
  };

  sprite_map.insert(std::make_pair(ghost_type, sprites));
}


void GhostSpriteConfigRepository::InitialiseMovingSpriteConfigs() {
  std::vector<state::GhostEntityType> ghosts = {
    state::GhostEntityType::Blinky,
    state::GhostEntityType::Pinky,
    state::GhostEntityType::Inky,
    state::GhostEntityType::Clyde,
  };

  for (size_t i = 0; i < ghosts.size(); i++) {
    AddSprites(this->moving_horizontal_sprites, 
               ghosts.at(i), 
               i + 2, 0,
               state::GetGhostName(ghosts.at(i)) + "_moving_horizontal");
    AddSprites(this->moving_up_sprites, 
               ghosts.at(i), 
               i + 2, 1,
               state::GetGhostName(ghosts.at(i)) + "_moving_up");
    AddSprites(this->moving_down_sprites, 
               ghosts.at(i),
               i + 2, 2,
               state::GetGhostName(ghosts.at(i)) + "_moving_down");
  }
}

}
}
}
}
