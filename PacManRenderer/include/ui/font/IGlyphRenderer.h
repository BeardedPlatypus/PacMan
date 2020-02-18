#pragma once

#include <memory>


namespace pacman {
namespace renderer {
namespace ui {
  
/// <summary>
/// <see cref="IGlyphRenderer"/> defines the interface with which Glyphs can be
/// rendered.
/// </summary>
class IGlyphRenderer {
public:
  ~IGlyphRenderer() = default;
  
  /// <summary>
  /// Initialises this <see cref="IGlyphRenderer"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Renders the <paramref name="glyph"/> at the specified location with the 
  /// specified <paramref name="scale"/>.
  /// </summary>
  /// <param name="glyph">The glyph to be rendered.</param>
  /// <param name="x">The x location.</param>
  /// <param name="y">The y location.</param>
  /// <param name="scale">The scale.</param>
  virtual void RenderGlyph(char glyph, float x, float y, float scale) = 0;
};

}
}
}
