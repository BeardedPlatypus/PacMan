#pragma once

#include "entity/IUpdatablePlayerEntity.h"
#include <gmock/gmock.h>


class UpdatablePlayerEntityMock : public pacman::update::IUpdatablePlayerEntity {
public:
  MOCK_METHOD(pacman::update::AxisType, GetActiveAxisType, (), (const));
  MOCK_METHOD(void, SetActiveAxisType, (pacman::update::AxisType));
  MOCK_METHOD(pacman::update::IUpdatableEntityAxis*, GetXAxis, (), (const));
  MOCK_METHOD(pacman::update::IUpdatableEntityAxis*, GetYAxis, (), (const));
  MOCK_METHOD(pacman::update::IUpdatableEntityAxis*, GetActiveAxis, (), (const));
  MOCK_METHOD(float, GetSpeed, (), (const));
  MOCK_METHOD(pacman::update::IPlayerMovementAxis*, GetPlayerMovementXAxis, (), (const));
  MOCK_METHOD(pacman::update::IPlayerMovementAxis*, GetPlayerMovementYAxis, (), (const));
  MOCK_METHOD(pacman::update::IPlayerMovementAxis*, GetActivePlayerMovementAxis, (), (const));
  MOCK_METHOD(pacman::update::IPlayerMovementAxis*, GetInactivePlayerMovementAxis, (), (const));
  MOCK_METHOD(void, SwapActiveAxis, ());
  MOCK_METHOD(pacman::state::Direction, GetMovingDirection, (), (const));
  MOCK_METHOD(void, SetMovingDirection, (pacman::state::Direction));
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(void, SetIsMoving, (bool));
};
