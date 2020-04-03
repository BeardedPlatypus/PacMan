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


void StringRenderer::RenderString(const IStringRenderData& string_data,
                                  float scale) {
  float char_scale = string_data.GetFontScale() * scale;
  float offset_x = this->GetOffset(string_data.GetString(), 
                                   char_scale, 
                                   string_data.GetJustification());

  for (size_t i = 0; i < string_data.GetString().length(); i++) {
    char c = string_data.GetString().at(i);

    if (c == ' ') continue;

    float x_loc = string_data.GetX() + i * values::glyph_size * char_scale + offset_x;
    this->_p_glyph_renderer->RenderGlyph(c, x_loc, string_data.GetY(), char_scale);
  }
}


float StringRenderer::GetOffset(const std::string& string, float scale, Justification justification) {
  float offset_characters = 0.F;

  switch (justification)
  {
  case pacman::renderer::ui::Justification::FlushLeft:
    break;
  case pacman::renderer::ui::Justification::Centre:
    offset_characters = -1.F * string.length() / 2.F;
    break;
  case pacman::renderer::ui::Justification::FlushRight:
    offset_characters = -1.F * string.length();
    break;
  default:
    break;
  }

  return offset_characters * scale * values::glyph_size;
}

}
}
}