#pragma once

#include "level/ILevelManager.h"
#include "gmock/gmock.h"


class LevelManagerMock : public pacman::state::level::ILevelManager {
public:
  MOCK_METHOD((unsigned int), GetCurrentLevel, (), (const));
  MOCK_METHOD(void, IncrementCurrentLevel, ());
  MOCK_METHOD((unsigned int), GetTotalNDots, (), (const));
  MOCK_METHOD((unsigned int), GetDotsLeftInCurrentLevel, (), (const));
  MOCK_METHOD((unsigned int), GetDotsConsumedInCurrentLevel, (), (const));
  MOCK_METHOD(void, IncrementDotsConsumedInCurrentLevel, ());
};
