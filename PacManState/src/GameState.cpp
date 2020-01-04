#include "stdafx.h"
#include "GameState.h"


namespace pacman {
namespace state {


GameState::GameState() { }


GameMode GameState::GetGameMode() const {
	return this->mode;
}


void GameState::SetGameMode(GameMode game_mode) {
	this->mode = game_mode;
}


field::IField* GameState::GetField() const {
  return this->p_field.get();
}


void GameState::ConstructNewField(const std::vector<std::vector<field::TileType>>& tiles) {
  this->p_field = field::IField::Construct(tiles);
}


IEntityState* GameState::GetPlayerState() const {
  return this->p_player_state.get();
}


void GameState::SetPlayerState(std::unique_ptr<IEntityState> p_new_player_state) {
  this->p_player_state = std::move(p_new_player_state);
}


void GameState::ConstructNewFieldObjects(const std::vector<std::vector<field::FieldObjectType>>& field_objects) {
  this->p_field_object_manager = field::IFieldObjectManager::Construct(field_objects, this->GetField());
}


field::IFieldObjectManager* GameState::GetFieldObjectManager() const {
  return this->p_field_object_manager.get();
}


}
}