#include "stdafx.h"
#include "GameState.h"


namespace pacman {
namespace state {


GameState::GameState() { }


inline GameMode GameState::GetGameMode() const {
	return this->_mode;
}


inline void GameState::SetGameMode(GameMode game_mode) {
	this->_mode = game_mode;
}


inline field::IField* GameState::GetField() const {
  return this->_p_field.get();
}


void GameState::ConstructNewField(const std::vector<std::vector<field::TileType>>& tiles) {
  this->_p_field = field::IField::Construct(tiles);
}


inline IEntityState* GameState::GetPlayerState() const {
  return this->_p_player_state.get();
}


inline void GameState::SetPlayerState(std::unique_ptr<IEntityState> p_new_player_state) {
  this->_p_player_state = std::move(p_new_player_state);
}


void GameState::ConstructNewFieldObjects(const std::vector<std::vector<field::FieldObjectType>>& field_objects) {
  this->_p_field_object_manager = field::IFieldObjectManager::Construct(field_objects, this->GetField());
}


inline field::IFieldObjectManager* GameState::GetFieldObjectManager() const {
  return this->_p_field_object_manager.get();
}


inline score::IScoreBoard* GameState::GetScoreBoard() const {
  return this->_p_score_board.get();
}


inline void GameState::SetScoreBoard(std::unique_ptr<score::IScoreBoard> p_score_board) {
  this->_p_score_board = std::move(p_score_board);
}

}
}