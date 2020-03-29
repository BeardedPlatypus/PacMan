#pragma once

#include "entity/IEntityStateRenderer.h"
#include <gmock/gmock.h>


class EntityStateRendererMock : public pacman::renderer::entity::IEntityStateRenderer {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(void, Render, (float, float), (const));
};
