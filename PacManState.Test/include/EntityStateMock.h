#pragma once

#include "entity/IEntityState.h"
#include "gmock/gmock.h"


class EntityStateMock : public pacman::state::IEntityState {
public:
  MOCK_METHOD(pacman::state::IEntityAxis*, GetXAxis, (), (const));
  MOCK_METHOD(pacman::state::IEntityAxis*, GetYAxis, (), (const));

  MOCK_METHOD(pacman::state::Direction, GetDirection, (), (const));
  MOCK_METHOD(void, SetDirection, (pacman::state::Direction direction));

  MOCK_METHOD(float, GetSpeed, (), (const));
  MOCK_METHOD(void, SetSpeed, (float new_speed));
};
