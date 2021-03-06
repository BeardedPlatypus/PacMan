#pragma once

#include "objects/ObjectRenderers/IObjectRenderer.h"
#include <gmock/gmock.h>


class ObjectRendererMock : public pacman::renderer::objects::IObjectRenderer {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, RenderObject, (int, int, float, float), (const));
};
