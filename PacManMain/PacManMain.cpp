// PacManMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

#include <PlayerState.h>
#include <RenderManager.h>
#include <ControllerManager.h>

#include <SDL2/SDL.h>

#undef main // Required for SDL2

int main() {
  auto player_state = pacman::state::PlayerState(5.0, 1.0, 2.0);
  auto game_state = pacman::state::GameState();

  auto render_manager = new pacman::view::RenderManager();
  render_manager->init();

  auto controller_manager = new pacman::controller::ControllerManager();

  float dtime = 0.0F;
  Uint64 tick_prev = 0;
  Uint64 tick_now  = SDL_GetPerformanceCounter();
  Uint64 freq = SDL_GetPerformanceFrequency();

  while (game_state.getGameMode() != pacman::state::GameMode::ClosedGame) {
	  tick_prev = tick_now;
	  tick_now  = SDL_GetPerformanceCounter();

	  dtime = ((float)(tick_now - tick_prev)) / freq;
	  // Game Loop
	  //   Update behaviour based on previous state.
	  controller_manager->update(game_state);
	  //   Update current state based on updated behaviour.
	  //   Render the current state.
	  render_manager->render(dtime);
	  //   Play music or anything like that.
  }
 
  delete render_manager;
  delete controller_manager;

  return 0;
}
