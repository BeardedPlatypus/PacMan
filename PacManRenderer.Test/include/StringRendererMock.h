#pragma once

#include "ui/font/IStringRenderer.h"
#include "ui/font/IStringRenderData.h"
#include <gmock/gmock.h>


class StringRendererMock : public pacman::renderer::ui::IStringRenderer {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, RenderString, (const pacman::renderer::ui::IStringRenderData&, float));
};
