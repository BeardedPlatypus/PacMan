// PacManMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

#include <PlayerState.h>
#include <RenderManager.h>
#include <ControllerManager.h>

#undef main // Required for SDL2

int main() {
  auto player_state = pacman::state::PlayerState(5.0, 1.0, 2.0);
  auto game_state = pacman::state::GameState();

  auto render_manager = new pacman::view::RenderManager();
  render_manager->init();

  auto controller_manager = new pacman::controller::ControllerManager();

  while (game_state.getGameMode() != pacman::state::GameMode::ClosedGame) {
	  controller_manager->update(game_state);
	  render_manager->render(player_state);
  }
 
  delete render_manager;
  delete controller_manager;

  return 0;
}
