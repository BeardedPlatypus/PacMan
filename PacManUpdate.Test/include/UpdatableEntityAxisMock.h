#pragma once

#include "entity/IUpdatableEntityAxis.h"
#include <gmock/gmock.h>


class UpdatableEntityAxisMock : public pacman::update::IUpdatableEntityAxis {
public:
  MOCK_METHOD(float, GetPosition, (), (const));
  MOCK_METHOD(void, SetPosition, (float));
  MOCK_METHOD(int, GetCurrentIndex, (), (const));
  MOCK_METHOD(int, GetPreviousIndex, (), (const));
  MOCK_METHOD(int, GetNextTileCenter, (), (const));
  MOCK_METHOD(int, GetPreviousTileCenter, (), (const));
  MOCK_METHOD(void, Move, (float));
  MOCK_METHOD(pacman::update::AxisDirection, GetCurrentAxisDirection, (), (const));
  MOCK_METHOD(void, SetCurrentAxisDirection, (pacman::update::AxisDirection));
  MOCK_METHOD(pacman::update::AxisDirection, GetPreviousAxisDirection, (), (const));
  MOCK_METHOD(void, SetPreviousAxisDirection, (pacman::update::AxisDirection));
};
