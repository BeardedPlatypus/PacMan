#include "stdafx.h"
#include "GameState.h"


namespace pacman {
namespace state {


GameState::GameState() : mode(MainMenu) { }


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


void GameState::SetPlayerState(std::unique_ptr<IEntityState> p_player_state) {
  this->p_player_state = std::move(p_player_state);
}

}
}