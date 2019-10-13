#pragma once

#include "state_machine/INode.h"
#include <gmock/gmock.h>

#include <entity/AxisDirection.h>
#include <state_machine/events/PlayerControlEvent.h>


class NodeMock : public pacman::update::state_machine::INode<pacman::update::AxisDirection, pacman::update::state_machine::PlayerControlEvent> {
public:
  MOCK_CONST_METHOD0(GetValue, pacman::update::AxisDirection());
  MOCK_CONST_METHOD1(GetConnectedNode, pacman::update::state_machine::INode<pacman::update::AxisDirection, pacman::update::state_machine::PlayerControlEvent>* (pacman::update::state_machine::PlayerControlEvent e));
  MOCK_METHOD2(AddConnection, void(pacman::update::state_machine::INode<pacman::update::AxisDirection, pacman::update::state_machine::PlayerControlEvent>* p_node, pacman::update::state_machine::PlayerControlEvent e));
};
