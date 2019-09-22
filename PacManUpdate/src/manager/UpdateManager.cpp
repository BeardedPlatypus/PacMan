#include "pch.h"
#include "manager/UpdateManager.h"

#include "commands/QuitCommand.h"
#include "commands/ChangePlayerDirectionCommand.h"
#include "entity/UpdatePlayer.h"

namespace pacman {
namespace update {

UpdateManager::UpdateManager(state::IGameState* p_game_state,
                             controller::IControllerManager* p_controller_manager) :
    p_game_state(p_game_state),
    p_controller_manager(p_controller_manager) {}


void UpdateManager::Initialise() {
  this->InitialiseCommands();
}


void UpdateManager::Update(float dt) {
  UpdatePlayer(this->p_game_state->GetPlayerState(),
               this->p_game_state->GetField(),
               dt);
}


void UpdateManager::InitialiseCommands() {
  this->p_controller_manager->RegisterSystemCommand(pacman::controller::SystemEventType::Quit,
                                                    commands::GetQuitCommand(this->p_game_state));

  this->p_controller_manager->RegisterKeyboardCommand(pacman::controller::KeyboardEventType::KeyUp,
                                                      pacman::controller::keyboard::Scancode::Escape,
                                                      commands::GetQuitCommand(this->p_game_state));

  this->p_controller_manager->RegisterKeyboardCommand(pacman::controller::KeyboardEventType::KeyDown,
                                                      pacman::controller::keyboard::Scancode::W,
                                                      commands::GetChangePlayerDirectionCommand(this->p_game_state->GetPlayerState(), 
                                                                                                state::Direction::Up));
  this->p_controller_manager->RegisterKeyboardCommand(pacman::controller::KeyboardEventType::KeyDown,
                                                      pacman::controller::keyboard::Scancode::A,
                                                      commands::GetChangePlayerDirectionCommand(this->p_game_state->GetPlayerState(), 
                                                                                                state::Direction::Left));
  this->p_controller_manager->RegisterKeyboardCommand(pacman::controller::KeyboardEventType::KeyDown,
                                                      pacman::controller::keyboard::Scancode::S,
                                                      commands::GetChangePlayerDirectionCommand(this->p_game_state->GetPlayerState(), 
                                                                                                state::Direction::Down));
  this->p_controller_manager->RegisterKeyboardCommand(pacman::controller::KeyboardEventType::KeyDown,
                                                      pacman::controller::keyboard::Scancode::D,
                                                      commands::GetChangePlayerDirectionCommand(this->p_game_state->GetPlayerState(), 
                                                                                                state::Direction::Right));

}

}
}