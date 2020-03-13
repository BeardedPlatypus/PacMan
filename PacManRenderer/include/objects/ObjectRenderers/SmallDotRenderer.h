#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"
#include "IViewAPI.h"


namespace pacman {
namespace renderer {
namespace objects {

/// <summary>
/// <see cref="SmallDotRenderer"/> implements <see cref="IObjectRenderer"/> for
/// the rendering of small dots.
/// </summary>
/// <seealso cref="IObjectRenderer" />
class SmallDotRenderer final : public IObjectRenderer {
public:  
  /// <summary>
  /// Creates a new <see cref="SmallDotRenderer"/>.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI"/>.</param>
  explicit SmallDotRenderer(view::IViewAPI* p_view_api);

  void Initialise() final;

  void RenderObject(int x, int y, float scale, float render_offset_y) const final;

private:
  float CalculateLocation(int val, float scale) const;

  view::IViewAPI* _p_view_api;
};

}
}
}
