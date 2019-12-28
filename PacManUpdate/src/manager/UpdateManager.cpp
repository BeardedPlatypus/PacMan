#include "pch.h"
#include "manager/UpdateManager.h"

#include "commands/QuitCommand.h"
#include "commands/ChangePlayerDirectionCommand.h"
#include "entity/UpdatePlayer.h"

#include "SystemEventType.h"
#include "KeyboardEventType.h"
#include "Scancode.h"


namespace pacman {
namespace update {

UpdateManager::UpdateManager(state::IGameState* p_game_state,
                             controller::api::IControllerAPI* p_controller_manager) :
    p_game_state(p_game_state),
    p_controller_manager(p_controller_manager) {}


void UpdateManager::Initialise() {
  this->p_player_entity = IUpdatablePlayerEntity::Construct(this->p_game_state->GetPlayerState());

  this->InitialiseCommands();
}


void UpdateManager::Update(float dt) {
  this->p_player_entity->Update(dt);
  UpdatePlayerLocation(this->p_player_entity.get(),
                       this->p_game_state->GetField(),
                       dt);
}


void UpdateManager::InitialiseCommands() {
  this->p_controller_manager->RegisterSystemCommand(controller::api::SystemEventType::Quit,
                                                    commands::GetQuitCommand(this->p_game_state));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyUp,
                                                      controller::api::Scancode::Escape,
                                                      commands::GetQuitCommand(this->p_game_state));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyDown,
                                                      controller::api::Scancode::W,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementYAxis(), 
                                                                                                state_machine::PlayerControlEvent::NegativeKeyPress));
  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyUp,
                                                      controller::api::Scancode::W,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementYAxis(), 
                                                                                                state_machine::PlayerControlEvent::NegativeKeyRelease));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyDown,
                                                      controller::api::Scancode::A,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementXAxis(), 
                                                                                                state_machine::PlayerControlEvent::NegativeKeyPress));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyUp,
                                                      controller::api::Scancode::A,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementXAxis(), 
                                                                                                state_machine::PlayerControlEvent::NegativeKeyRelease));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyDown,
                                                      controller::api::Scancode::S,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementYAxis(), 
                                                                                                state_machine::PlayerControlEvent::PositiveKeyPress));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyUp,
                                                      controller::api::Scancode::S,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementYAxis(), 
                                                                                                state_machine::PlayerControlEvent::PositiveKeyRelease));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyDown,
                                                      controller::api::Scancode::D,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementXAxis(), 
                                                                                                state_machine::PlayerControlEvent::PositiveKeyPress));

  this->p_controller_manager->RegisterKeyboardCommand(controller::api::KeyboardEventType::KeyUp,
                                                      controller::api::Scancode::D,
                                                      commands::GetChangePlayerDirectionCommand(this->p_player_entity->GetPlayerMovementXAxis(), 
                                                                                                state_machine::PlayerControlEvent::PositiveKeyRelease));
}

}
}