#include "pch.h"
#include "commands/ChangePlayerDirectionCommand.h"


namespace pacman {
namespace update {
namespace commands {

ChangePlayerDirectionCommand::ChangePlayerDirectionCommand(IUpdatablePlayerEntity* p_player_state,
                                                           std::optional<state::Direction> direction) : 
    p_player_state(p_player_state), 
    direction(direction) {}


void ChangePlayerDirectionCommand::Execute() {
  this->p_player_state->SetNextDirection(this->direction);
}


std::unique_ptr<controller::ICommand> GetChangePlayerDirectionCommand(IUpdatablePlayerEntity* p_player_state,
                                                                      std::optional<state::Direction> direction) {
  return std::make_unique<ChangePlayerDirectionCommand>(p_player_state, direction);
}

}
}
}