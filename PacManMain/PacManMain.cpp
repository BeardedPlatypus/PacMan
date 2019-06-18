// PacManMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

#include <PlayerState.h>
#include <ControllerManager.h>
#include <manager/IViewManager.h>

#include <SDL2/SDL.h>

#undef main // Required for SDL2


void viewConfiguration(pacman::view::IViewManager& manager) {

	std::string file_path = "./assets/characters.png";

	manager.requestSprite("test1", file_path,  pacman::view::ClipRect(0, 32, 16, 16));
	manager.requestSprite("test2", file_path, pacman::view::ClipRect(16, 32, 16, 16));

	manager.requestSprite("test3", file_path,  pacman::view::ClipRect(0, 48, 16, 16));
	manager.requestSprite("test4", file_path, pacman::view::ClipRect(16, 48, 16, 16));

	manager.requestSprite("test5", file_path,  pacman::view::ClipRect(0, 64, 16, 16));
	manager.requestSprite("test6", file_path, pacman::view::ClipRect(16, 64, 16, 16));

	manager.requestSprite("test7", file_path,  pacman::view::ClipRect(0, 80, 16, 16));
	manager.requestSprite("test8", file_path, pacman::view::ClipRect(16, 80, 16, 16));

	manager.requestSprite("p1", file_path,  pacman::view::ClipRect(0, 0, 16, 16));
	manager.requestSprite("p2", file_path, pacman::view::ClipRect(16, 0, 16, 16));
	manager.requestSprite("p3", file_path, pacman::view::ClipRect(32, 0, 16, 16));

	auto sprites1 = std::vector<std::string>();
	sprites1.push_back("test1");
	sprites1.push_back("test2");

	manager.requestSpriteAnimation("anim1", 0.3F, sprites1);

	auto sprites2 = std::vector<std::string>();
	sprites2.push_back("test3");
	sprites2.push_back("test4");

	manager.requestSpriteAnimation("anim2", 0.3F, sprites2);

	auto sprites3 = std::vector<std::string>();
	sprites3.push_back("test5");
	sprites3.push_back("test6");

	manager.requestSpriteAnimation("anim3", 0.3F, sprites3);

	auto sprites4 = std::vector<std::string>();
	sprites4.push_back("test7");
	sprites4.push_back("test8");

	manager.requestSpriteAnimation("anim4", 0.3F, sprites4);

	auto sprites5 = std::vector<std::string>();
	sprites5.push_back("p1");
	sprites5.push_back("p2");
	sprites5.push_back("p3");
	sprites5.push_back("p2");

	manager.requestSpriteAnimation("anim5", 0.175F, sprites5);
}


void render(pacman::view::IViewManager& manager) {
	int x = 640 / 2 - 16;
	int y = 48 * 2 + 4;

	manager.initialiseRender();
	
	manager.renderSpriteAnimation("anim1", x, y, 4.0);
	manager.renderSpriteAnimation("anim2", x - 16.F * 4, y, 4.0);
	manager.renderSpriteAnimation("anim3", x - 32.F * 4, y, 4.0);
	manager.renderSpriteAnimation("anim4", x - 48.F * 4, y, 4.0);
	manager.renderSpriteAnimation("anim5", x + 32.F * 4, y, 4.0);

	manager.finaliseRender();
}



int main() {
  auto player_state = pacman::state::PlayerState(5.0, 1.0, 2.0);
  auto game_state = pacman::state::GameState();

  auto view_manager = pacman::view::IViewManager::construct();
  view_manager->initialise();
  viewConfiguration(*view_manager);

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
	  view_manager->update(dtime);
	  render(*view_manager);
	  //   Play music or anything like that.
  }
 
  delete controller_manager;

  return 0;
}
