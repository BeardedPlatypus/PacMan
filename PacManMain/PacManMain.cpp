// PacManMain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

#include <GameState.h>
#include <IViewAPI.h>
#include <IControllerAPI.h>
#include <IRendererAPI.h>
#include <IUpdateAPI.h>

#include <entity/IEntityManager.h>
#include <entity/IEntityState.h>
#include <entity/player/IPacManBehaviourState.h>
#include <entity/ghost/IGhostBehaviourState.h>

#include <field/FieldDefinition.h>
#include <field/object/FieldObjectDefinition.h>

#include <SDL2/SDL.h>

#undef main // Required for SDL2


int main(int argc, char **argv) {
  if (argc != 1) return 1;

  auto p_game_state = pacman::state::IGameState::Construct();

  p_game_state->ConstructNewField(pacman::state::field::GetFieldDefinition());
  p_game_state->ConstructNewFieldObjects(pacman::state::field::GetFieldObjectDefinition());

  // Entities
  auto p_entity_manager = pacman::state::IEntityManager::Construct();

  // - Pacman
  auto p_player_spatial_state = pacman::state::ISpatialState::Construct(11.F,
                                                                        20.F,
                                                                        pacman::state::Direction::Left,
                                                                        3.0F);
  auto p_player_behavioural_state = pacman::state::IPacManBehaviourState::Construct(pacman::state::PacManStateType::Moving);
  auto p_pacman_entity = 
    pacman::state::IEntityState<pacman::state::IPacManBehaviourState>::Construct(std::move(p_player_spatial_state),
                                                                                 std::move(p_player_behavioural_state));
  p_entity_manager->SetPlayerState(std::move(p_pacman_entity));

  // - Ghosts
  auto p_blinky_spatial_state = pacman::state::ISpatialState::Construct(11.F,
                                                                        10.F,
                                                                        pacman::state::Direction::Left,
                                                                        3.0F);
  p_blinky_spatial_state->SetIsMoving(true);
  auto p_blinky_behavioural_state = pacman::state::IGhostBehaviourState::Construct(pacman::state::GhostStateType::Alive);
  auto p_blinky_entity = 
    pacman::state::IEntityState<pacman::state::IGhostBehaviourState>::Construct(std::move(p_blinky_spatial_state),
                                                                                 std::move(p_blinky_behavioural_state));
  p_entity_manager->SetBlinkyState(std::move(p_blinky_entity));

  auto p_pinky_spatial_state = pacman::state::ISpatialState::Construct(11.F,
                                                                       13.F,
                                                                       pacman::state::Direction::Up,
                                                                       3.0F);
  p_pinky_spatial_state->SetIsMoving(true);
  auto p_pinky_behavioural_state = pacman::state::IGhostBehaviourState::Construct(pacman::state::GhostStateType::Alive);
  auto p_pinky_entity = 
    pacman::state::IEntityState<pacman::state::IGhostBehaviourState>::Construct(std::move(p_pinky_spatial_state),
                                                                                std::move(p_pinky_behavioural_state));
  p_entity_manager->SetPinkyState(std::move(p_pinky_entity));

  auto p_inky_spatial_state = pacman::state::ISpatialState::Construct(10.F,
                                                                      12.F,
                                                                      pacman::state::Direction::Down,
                                                                      3.0F);
  p_inky_spatial_state->SetIsMoving(true);

  auto p_inky_behavioural_state = pacman::state::IGhostBehaviourState::Construct(pacman::state::GhostStateType::Alive);
  auto p_inky_entity = 
    pacman::state::IEntityState<pacman::state::IGhostBehaviourState>::Construct(std::move(p_inky_spatial_state),
                                                                                std::move(p_inky_behavioural_state));
  p_entity_manager->SetInkyState(std::move(p_inky_entity));

  auto p_clyde_spatial_state = pacman::state::ISpatialState::Construct(12.F,
                                                                      12.F,
                                                                      pacman::state::Direction::Down,
                                                                      3.0F);
  p_clyde_spatial_state->SetIsMoving(true);
  auto p_clyde_behavioural_state = pacman::state::IGhostBehaviourState::Construct(pacman::state::GhostStateType::Alive);
  auto p_clyde_entity = 
    pacman::state::IEntityState<pacman::state::IGhostBehaviourState>::Construct(std::move(p_clyde_spatial_state),
                                                                                std::move(p_clyde_behavioural_state));
  p_entity_manager->SetClydeState(std::move(p_clyde_entity));

  p_game_state->SetEntityManager(std::move(p_entity_manager));

  auto p_score_board = pacman::state::score::IScoreBoard::Construct();
  p_game_state->SetScoreBoard(std::move(p_score_board));

  // The current field contains 192 dots (including the big dots).
  auto p_level_manager = pacman::state::level::ILevelManager::Construct(192);
  p_game_state->SetLevelManager(std::move(p_level_manager));

  auto p_view_api = pacman::view::IViewAPI::Construct();
  p_view_api->Initialise(736, 960);

  auto p_renderer_api = pacman::renderer::IRendererAPI::Construct(p_game_state.get(),
                                                                  p_view_api.get());
  p_renderer_api->Initialise();

  auto p_controller_api = pacman::controller::api::IControllerAPI::Construct();

  auto p_update_api = pacman::update::IUpdateAPI::Construct(p_game_state.get(),
                                                            p_controller_api.get());
  p_update_api->Initialise();
  

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
    p_update_api->Update(dtime);
    p_renderer_api->Update(dtime);

	  //   Update current state based on updated behaviour.
	  //   Render the current state.
    p_view_api->InitialiseRender();
    p_renderer_api->Render();
    p_view_api->FinaliseRender();

	  //   Play music or anything like that.
  }
 
  return 0;
}
