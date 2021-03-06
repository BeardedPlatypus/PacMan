#pragma once

#include "state_machine/INode.h"
#include <gmock/gmock.h>

#include <entity/AxisDirection.h>
#include <state_machine/events/PlayerControlEvent.h>


class NodeMock : public pacman::update::state_machine::INode<pacman::update::AxisDirection, pacman::update::state_machine::PlayerControlEvent> {
public:
  using NodeAlias = pacman::update::state_machine::INode<pacman::update::AxisDirection, pacman::update::state_machine::PlayerControlEvent>;
  MOCK_METHOD(pacman::update::AxisDirection, GetValue, (), (const));
  MOCK_METHOD(NodeAlias*, GetConnectedNode, (pacman::update::state_machine::PlayerControlEvent e), (const));
  MOCK_METHOD(void, AddConnection, (NodeAlias*, pacman::update::state_machine::PlayerControlEvent));
};
