#include "pch.h"
#include "ui/font/StringRenderer.h"
#include "ui/UISpriteValues.h"


namespace pacman {
namespace renderer {
namespace ui {

StringRenderer::StringRenderer(IGlyphRenderer* p_glyph_renderer) : 
    _p_glyph_renderer(p_glyph_renderer) { }


void StringRenderer::RenderString(const std::string& string,
                                  float x, float y, float scale) {
  for (size_t i = 0; i < string.length(); i++) {
    char c = string.at(i);

    if (c == ' ') continue;

    this->_p_glyph_renderer->RenderGlyph(c, x + i * values::glyph_size * scale, y, scale);
  }
}


}
}
}