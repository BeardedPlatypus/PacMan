#include "stdafx.h"
#include "GameState.h"


namespace pacman {
namespace state {


GameState::GameState(GameMode game_mode) : mode(game_mode) { }

GameState::GameState() : GameState(MainMenu) { }

GameMode GameState::getGameMode() const {
	return this->mode;
}

void GameState::setGameMode(GameMode game_mode) {
	this->mode = game_mode;
}

}
}