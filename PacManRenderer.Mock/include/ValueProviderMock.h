#pragma once

#include "entity/render/IValueProvider.h"
#include <gmock/gmock.h>

template <typename T>
class ValueProviderMock : public pacman::renderer::entity::render::IValueProvider<T> {
public:
  MOCK_METHOD(T, GetValue, (), (const));
};
