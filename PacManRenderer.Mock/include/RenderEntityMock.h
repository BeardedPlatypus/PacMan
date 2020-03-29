#pragma once

#include "entity/IRenderEntity.h"
#include <gmock/gmock.h>


class RenderEntityMock : public pacman::renderer::entity::IRenderEntity {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(void, Render, (float, float), (const));
};
