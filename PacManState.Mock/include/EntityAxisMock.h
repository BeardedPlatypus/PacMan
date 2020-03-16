#pragma once

#include "entity/IEntityAxis.h"
#include "gmock/gmock.h"


class EntityAxisMock : public pacman::state::IEntityAxis {
public:
  MOCK_METHOD(float, GetPosition, (), (const));
  MOCK_METHOD(void, SetPosition, (float position));
};
