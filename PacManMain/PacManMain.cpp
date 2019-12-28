// PacManMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

#include <GameState.h>
#include <IViewAPI.h>
#include <IControllerAPI.h>
#include <manager/IRendererManager.h>
#include <manager/IUpdateManager.h>

#include <entity/EntityState.h>

#include <field/FieldDefinition.h>

#include <SDL2/SDL.h>

#undef main // Required for SDL2


int main(int argc, char **argv) {
  if (argc != 1) return 1;

  auto p_game_state = pacman::state::IGameState::Construct();

  p_game_state->ConstructNewField(pacman::state::field::GetFieldDefinition());

  auto p_player_state = pacman::state::IEntityState::Construct(10.F,
                                                               20.F,
                                                               pacman::state::Direction::Left,
                                                               2.5F);
  p_game_state->SetPlayerState(std::move(p_player_state));

  auto p_view_api = pacman::view::IViewAPI::Construct();
  p_view_api->Initialise(800, 1000);

  auto p_renderer_manager = pacman::renderer::IRendererManager::Construct(p_game_state.get(),
                                                                          p_view_api.get());
  p_renderer_manager->Initialise();

  auto p_controller_api = pacman::controller::api::IControllerAPI::Construct();

  auto p_update_manager = pacman::update::IUpdateManager::Construct(p_game_state.get(),
                                                                    p_controller_api.get());
  p_update_manager->Initialise();
  

  float dtime = 0.0F;
  Uint64 tick_prev = 0;
  Uint64 tick_now  = SDL_GetPerformanceCounter();
  Uint64 freq = SDL_GetPerformanceFrequency();

  while (p_game_state->GetGameMode() != pacman::state::GameMode::ClosedGame) {
	  tick_prev = tick_now;
	  tick_now  = SDL_GetPerformanceCounter();

	  dtime = ((float)(tick_now - tick_prev)) / freq;
	  // Game Loop
	  //   Update behaviour based on previous state.
	  p_controller_api->Update();
    p_update_manager->Update(dtime);
	  //   Update current state based on updated behaviour.
	  //   Render the current state.
    p_view_api->InitialiseRender();
    p_renderer_manager->Render();
    p_view_api->FinaliseRender();

	  //   Play music or anything like that.
  }
 
  return 0;
}
