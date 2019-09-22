#pragma once

#include "entity/IEntityState.h"
#include "gmock/gmock.h"


class EntityStateMock : public pacman::state::IEntityState {
public:
  MOCK_CONST_METHOD0(GetXPosition, float());
  MOCK_CONST_METHOD0(GetYPosition, float());
  MOCK_METHOD1(SetXPosition, void(float new_x));
  MOCK_METHOD1(SetYPosition, void(float new_y));

  MOCK_CONST_METHOD0(GetDirection, pacman::state::Direction());
  MOCK_METHOD1(SetDirection, void(pacman::state::Direction direction));

  MOCK_CONST_METHOD0(GetSpeed, float());
  MOCK_METHOD1(SetSpeed, void(float new_speed));
};
