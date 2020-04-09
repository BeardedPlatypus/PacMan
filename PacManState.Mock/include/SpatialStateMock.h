#pragma once

#include "entity/spatial/ISpatialState.h"
#include "gmock/gmock.h"


class SpatialStateMock : public pacman::state::ISpatialState {
public:
  MOCK_METHOD(pacman::state::IEntityAxis*, GetXAxis, (), (const));
  MOCK_METHOD(pacman::state::IEntityAxis*, GetYAxis, (), (const));

  MOCK_METHOD(pacman::state::Direction, GetDirection, (), (const));
  MOCK_METHOD(void, SetDirection, (pacman::state::Direction direction));

  MOCK_METHOD(float, GetSpeed, (), (const));
  MOCK_METHOD(void, SetSpeed, (float new_speed));

  MOCK_METHOD(bool, IsMoving, (), (const));
  MOCK_METHOD(void, SetIsMoving, (bool));

  MOCK_METHOD(void, Reset, ());
};
