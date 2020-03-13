#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"


namespace pacman {
namespace renderer {
namespace objects {
  
/// <summary>
/// <see cref="BigDotRenderer"/> implements <see cref="IObjectRenderer"/> for
/// the rendering of big dots.
/// </summary>
/// <seealso cref="IObjectRenderer" />
class BigDotRenderer final : public IObjectRenderer {
public:  
  /// <summary>
  /// Create a new <see cref="BigDotRenderer"/>.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI"/>.</param>
  explicit BigDotRenderer(view::IViewAPI* p_view_api);

  void Initialise() final;

  void RenderObject(int x, int y, float scale, float render_offset_y) const final;

private:
  float CalculateLocation(int val, float scale) const;

  view::IViewAPI* _p_view_api;
};

}
}
}
