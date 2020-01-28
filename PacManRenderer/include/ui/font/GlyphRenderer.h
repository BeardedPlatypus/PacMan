#pragma once

#include <string>
#include <unordered_map>

#include <IViewAPI.h>

#include "ui/font/IGlyphRenderer.h"

namespace pacman {
namespace renderer {
namespace ui {

/// <summary>
/// <see cref="IGlyphRenderer"/> implements the interface with which Glyphs can be
/// rendered.
/// </summary>
class GlyphRenderer final : public IGlyphRenderer {
public:
  GlyphRenderer(view::IViewAPI* p_view_api);

  void Initialise() final;
  void RenderGlyph(char glyph, float x, float y, float scale) final;

private:
  void InitialiseSprites();

  void AddGlyphSprite(char c, int x_index, int y_index);

  std::unordered_map<char, std::string> glyph_mapping =
    std::unordered_map<char, std::string>();

  view::IViewAPI* _p_view_api;
};

}
}
}
