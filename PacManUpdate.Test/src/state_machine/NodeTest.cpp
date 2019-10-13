#include <gtest/gtest.h>
#include <state_machine/INode.h>

#include <entity/AxisDirection.h>
#include <state_machine/events/PlayerControlEvent.h>


namespace pacman {
namespace update {
namespace state_machine {


TEST(NodeTest, Constructor_ExpectedValues) {
  // Setup
  AxisDirection expectedDirection = AxisDirection::Negative;

  // Call
  auto p_node = INode<AxisDirection, PlayerControlEvent>::Construct(expectedDirection);

  // Assert
  EXPECT_EQ(p_node->GetValue(), expectedDirection);
}


TEST(NodeTest, GetConnectedNode_ExpectedValue) {
  // Setup
  auto p_node = INode<AxisDirection, PlayerControlEvent>::Construct(AxisDirection::None);
  auto e = PlayerControlEvent::NegativeKey;

  // Call
  INode<AxisDirection, PlayerControlEvent>* result = p_node->GetConnectedNode(e);

  // Assert
  EXPECT_EQ(result, nullptr);
}


TEST(NodeTest, AddConnection_ExpectedValue) {
  // Setup
  auto p_node = INode<AxisDirection, PlayerControlEvent>::Construct(AxisDirection::None);

  auto p_connected_node = INode<AxisDirection, PlayerControlEvent>::Construct(AxisDirection::None);
  auto e = PlayerControlEvent::NegativeKey;

  p_node->AddConnection(p_connected_node.get(), e);

  // Call
  INode<AxisDirection, PlayerControlEvent>* result = p_node->GetConnectedNode(e);

  // Assert
  EXPECT_EQ(result, p_connected_node.get());
}

}
}
}