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
  /// <param name="p_glyph_renderer"><see cref="std::unique_ptr"/> to the <see cref="IGlyphRenderer" />.</param>
  /// <pre-condition>
  /// <paramref name="p_glyph_renderer"/> should not be null.
  /// </pre-condition>
  /// <remarks>
  /// The ownership of <paramref name="p_glyph_renderer"/> is moved to this
  /// <see cref="StringRenderer"/>.
  /// </remarks>
  explicit StringRenderer(std::unique_ptr<IGlyphRenderer> p_glyph_renderer);

  void Initialise();

  void RenderString(const std::string& string, float x, float y, float scale) final;

private:
  std::unique_ptr<IGlyphRenderer> _p_glyph_renderer;
};

}
}
}
