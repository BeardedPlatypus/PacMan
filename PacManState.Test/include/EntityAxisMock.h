#pragma once

#include "entity/IEntityAxis.h"
#include "gmock/gmock.h"


class EntityAxisMock : public pacman::state::IEntityAxis {
public:
  MOCK_CONST_METHOD0(GetPosition, float());
  MOCK_METHOD1(SetPosition, void(float position));
};
