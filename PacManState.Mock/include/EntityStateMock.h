#pragma once

#include "entity/IEntityState.h"
#include "gmock/gmock.h"

template <typename T>
class EntityStateMock : public pacman::state::IEntityState<T> {
public:
  MOCK_METHOD((pacman::state::ISpatialState*), GetSpatialState, (), (const));
  MOCK_METHOD((T*), GetBehaviouralState, (), (const));
};
