#include "PlayerMovementAxisMock.h"
#include <gtest/gtest.h>

#include <commands/ChangePlayerDirectionCommand.h>

namespace pacman {
namespace update {
namespace commands {

TEST(ChangePlayerDirectionCommandTest, Execute_SetsPlayerDirectionCorrectly) {
  // Setup
  state_machine::PlayerControlEvent expected_control_event = 
    state_machine::PlayerControlEvent::NegativeKeyPress;

  PlayerMovementAxisMock movement_axis;
  EXPECT_CALL(movement_axis, ChangeState(expected_control_event)).Times(1);

  auto p_command = GetChangePlayerDirectionCommand(&movement_axis, expected_control_event);

  // Call
  p_command->Execute();
}

}
}
}
