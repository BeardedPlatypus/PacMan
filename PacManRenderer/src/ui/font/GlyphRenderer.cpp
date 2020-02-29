#include "pch.h"
#include "ui/font/GlyphRenderer.h"
#include "ui/UISpriteValues.h"

namespace pacman {
namespace renderer {
namespace ui {

GlyphRenderer::GlyphRenderer(view::IViewAPI* p_view_api) :
    _p_view_api(p_view_api) {}


void GlyphRenderer::Initialise() {
  this->InitialiseSprites();
}


void GlyphRenderer::RenderGlyph(char glyph, float x, float y, float scale) {
  this->_p_view_api->RenderSprite(this->glyph_mapping.at(glyph), x, y, scale);
}


void GlyphRenderer::InitialiseSprites() {
  std::string glyphs = "0123456789-/abcdefghijklmnopqrstuvwxyz.>";

  size_t i = 0;
  size_t j = 0;
  for (const char& c : glyphs) {
    AddGlyphSprite(c, i, j);

    if (i < 7) {
      i += 1;
    }
    else {
      i = 0;
      j += 1;
    }
  }
}


inline void GlyphRenderer::AddGlyphSprite(char c, int x_index, int y_index) {
  std::string sprite_label = "glyph_";
  sprite_label.append(1, c);

  this->_p_view_api->RequestSprite(sprite_label,
                                   values::font_file,
                                   x_index * values::glyph_size, 
                                   y_index * values::glyph_size,
                                   values::glyph_size, 
                                   values::glyph_size);

  this->glyph_mapping[c] = sprite_label;
}

}
}
}
