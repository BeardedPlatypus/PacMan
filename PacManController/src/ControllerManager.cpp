#include "stdafx.h"
#include "ControllerManager.h"


namespace pacman {
namespace controller {

ControllerManager::ControllerManager() {
	this->p_event = std::unique_ptr<SDL_Event>(new SDL_Event());
}


void ControllerManager::update(state::GameState& state) const {
	SDL_PollEvent(this->p_event.get());

	if (this->p_event->type == SDL_QUIT)
		state.setGameMode(state::GameMode::ClosedGame);

	if (this->p_event->type == SDL_KEYDOWN)
		state.setGameMode(state::GameMode::ClosedGame);

	if (this->p_event->type == SDL_MOUSEBUTTONDOWN)
		state.setGameMode(state::GameMode::ClosedGame);
}

}
}
