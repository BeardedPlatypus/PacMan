#include "NodeMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <state_machine/IStateMachine.h>

#pragma region using_statements
using ::testing::_;
using ::testing::Eq;
using ::testing::Return;
#pragma endregion


namespace pacman {
namespace update {
namespace state_machine {

TEST(StateMachineTest, Constructor_ExpectedValues) {
  // Setup
  auto p_node0 = INode<AxisDirection, PlayerControlEvent>::Construct(AxisDirection::None);

  AxisDirection expected_value = AxisDirection::Negative;
  auto p_node1 = INode<AxisDirection, PlayerControlEvent>::Construct(expected_value);

  std::vector<std::unique_ptr<INode<AxisDirection, PlayerControlEvent>>> nodes = {};
  nodes.push_back(std::move(p_node0));
  nodes.push_back(std::move(p_node1));

  // Call
  auto state_machine = IStateMachine<AxisDirection, PlayerControlEvent>::Construct(nodes, 1);

  // Assert
  EXPECT_EQ(state_machine->GetCurrentValue(), expected_value);
}


TEST(StateMachineTest, Move_MovesActiveNode) {
  // Setup
  AxisDirection expected_value = AxisDirection::Negative;
  auto p_node0 = INode<AxisDirection, PlayerControlEvent>::Construct(expected_value);

  auto p_node1 = INode<AxisDirection, PlayerControlEvent>::Construct(AxisDirection::None);

  PlayerControlEvent expected_event = PlayerControlEvent::NegativeKeyPress;
  p_node1->AddConnection(p_node0.get(), expected_event);

  std::vector<std::unique_ptr<INode<AxisDirection, PlayerControlEvent>>> nodes = {};
  nodes.push_back(std::move(p_node0));
  nodes.push_back(std::move(p_node1));

  auto state_machine = IStateMachine<AxisDirection, PlayerControlEvent>::Construct(nodes, 1);

  // Call
  state_machine->Move(expected_event);

  // Assert
  EXPECT_EQ(state_machine->GetCurrentValue(), expected_value);
}


}
}
}
