#include "pch.h"
#include "commands/ChangePlayerDirectionCommand.h"


namespace pacman {
namespace update {
namespace commands {

ChangePlayerDirectionCommand::ChangePlayerDirectionCommand(state::IEntityState* p_player_state,
                                                           state::Direction direction) : 
    p_player_state(p_player_state), 
    direction(direction) {}


void ChangePlayerDirectionCommand::Execute() {
  this->p_player_state->SetDirection(this->direction);
}


std::unique_ptr<controller::ICommand> GetChangePlayerDirectionCommand(state::IEntityState* p_player_state,
                                                                      state::Direction direction) {
  return std::make_unique<ChangePlayerDirectionCommand>(p_player_state, direction);
}

}
}
}