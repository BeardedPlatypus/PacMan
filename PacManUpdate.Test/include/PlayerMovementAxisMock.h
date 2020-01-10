#pragma once

#include "entity/IPlayerMovementAxis.h"
#include "gmock/gmock.h"

class PlayerMovementAxisMock : public pacman::update::IPlayerMovementAxis {
public:
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(pacman::update::AxisDirection, GetNextDirection, (), (const));
  MOCK_METHOD(void, ChangeState, (pacman::update::state_machine::PlayerControlEvent));
};

