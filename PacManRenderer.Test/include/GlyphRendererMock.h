#pragma once

#include "ui/font/IGlyphRenderer.h"
#include <gmock/gmock.h>


class GlyphRendererMock : public pacman::renderer::ui::IGlyphRenderer {
public:
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, RenderGlyph, (char, float, float, float));
};
