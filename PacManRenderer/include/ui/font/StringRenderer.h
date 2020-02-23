#pragma once

#include "IStringRenderer.h"
#include "IGlyphRenderer.h"


namespace pacman {
namespace renderer {
namespace ui {

/// <summary>
/// <see cref="StringRenderer"/> implements the interface with which strings can
/// be rendered.
/// </summary>
class StringRenderer : public IStringRenderer {
public:  
  /// <summary>
  /// Creates a new <see cref="StringRenderer" />.
  /// </summary>
  /// <param name="_p_glyph_renderer">Pointer to the <see cref="IGlyphRenderer" />.</param>
  /// <pre-condition>
  /// <paramref name="_p_glyph_renderer"/> should not be null.
  /// </pre-condition>
  explicit StringRenderer(IGlyphRenderer* p_glyph_renderer);

  void RenderString(const std::string& string, float x, float y, float scale) final;

private:
  IGlyphRenderer* _p_glyph_renderer;
};

}
}
}
