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


inline IEntityManager* GameState::GetEntityManager() const {
  return this->_p_entity_manager.get();
}


inline void GameState::SetEntityManager(std::unique_ptr<IEntityManager> p_entity_manager) {
  this->_p_entity_manager= std::move(p_entity_manager);
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


inline level::ILevelManager* GameState::GetLevelManager() const {
  return this->_p_level_manager.get();
}


inline void GameState::SetLevelManager(std::unique_ptr<level::ILevelManager> p_level_manager) {
  this->_p_level_manager = std::move(p_level_manager);
}

}
}