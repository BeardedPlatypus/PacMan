#pragma once

#include "IRenderLayer.h"
#include "ui/font/IStringRenderer.h"


namespace pacman {
namespace renderer {

/// <summary>
/// <see cref="UILayer"/> visualises the UI layer.
/// </summary>
/// <seealso cref="IRenderLayer"/>
class UILayer final : public IRenderLayer {
public:
  UILayer(float scale,
          std::unique_ptr<ui::IStringRenderer> p_string_renderer,
          float render_offset_y);

  void Initialise() final;

  inline void Update(float dtime) {
    // FieldLayer is static
  }

  void Render() const final;

private:  
  /// <summary>
  /// The scale with which will be rendered.
  /// </summary>
  const float scale;
    
  /// <summary>
  /// The string renderer used by this <see cref="UILayer"/>.
  /// </summary>
  std::unique_ptr<ui::IStringRenderer> p_string_renderer;

  /// <summary>
  /// The render offset of this layer
  /// </summary>
  const float render_offset_y;
};

}
}
