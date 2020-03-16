#pragma once

#include "IRenderLayer.h"
#include "gmock/gmock.h"


class RenderLayerMock : public pacman::renderer::IRenderLayer {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(void, Render, (), (const));
};
