#include "pch.h"
#include "commands/ChangePlayerDirectionCommand.h"


namespace pacman {
namespace update {
namespace commands {

ChangePlayerDirectionCommand::ChangePlayerDirectionCommand(IPlayerMovementAxis* p_axis,
                                                           state_machine::PlayerControlEvent direction_changed_event) : 
    p_movement_axis(p_axis), 
    direction_changed_event(direction_changed_event) {}


void ChangePlayerDirectionCommand::Execute() {
  this->p_movement_axis->ChangeState(this->direction_changed_event);
}


std::unique_ptr<controller::ICommand> GetChangePlayerDirectionCommand(IPlayerMovementAxis* p_axis,
                                                                      state_machine::PlayerControlEvent direction_changed_event) {
  return std::make_unique<ChangePlayerDirectionCommand>(p_axis, direction_changed_event);
}

}
}
}