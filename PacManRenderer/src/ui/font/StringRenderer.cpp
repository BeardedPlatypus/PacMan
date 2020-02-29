#include "pch.h"
#include "ui/font/StringRenderer.h"
#include "ui/UISpriteValues.h"


namespace pacman {
namespace renderer {
namespace ui {

StringRenderer::StringRenderer(std::unique_ptr<IGlyphRenderer> p_glyph_renderer) : 
    _p_glyph_renderer(std::move(p_glyph_renderer)) { }


void StringRenderer::Initialise() {
  this->_p_glyph_renderer->Initialise();
}


void StringRenderer::RenderString(const std::string& string,
                                  float x, float y, float scale,
                                  Justification justification) {
  float offset_x = this->GetOffset(string, scale, justification);

  for (size_t i = 0; i < string.length(); i++) {
    char c = string.at(i);

    if (c == ' ') continue;

    this->_p_glyph_renderer->RenderGlyph(c, x + i * values::glyph_size * scale + offset_x, y, scale);
  }
}


float StringRenderer::GetOffset(const std::string& string, float scale, Justification justification) {
  float offset_characters = 0.F;

  switch (justification)
  {
    break;
  case pacman::renderer::ui::Justification::Centre:
    offset_characters = -1.F * string.length() / 2.F;
    break;
  case pacman::renderer::ui::Justification::FlushRight:
    offset_characters = -1.F * string.length();
    break;
  case pacman::renderer::ui::Justification::FlushLeft:
  default:
    break;
  }

  return offset_characters * scale * values::glyph_size;
}

}
}
}