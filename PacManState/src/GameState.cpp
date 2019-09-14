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


void GameState::SetField(std::unique_ptr<field::IField> p_field) {
  this->p_field = std::move(p_field);
}


}
}