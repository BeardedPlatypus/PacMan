#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"


namespace pacman {
namespace renderer {
namespace objects {

/// <summary>
/// <see cref="BonusFruitRenderer"/> implements <see cref="IObjectRenderer"/> for
/// the rendering of the bonus.
/// </summary>
/// <seealso cref="IObjectRenderer" />
class BonusFruitRenderer final : public IObjectRenderer {
public:
  /// <summary>
  /// Create a new <see cref="BonusFruitRenderer"/>.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI"/>.</param>
  explicit BonusFruitRenderer(view::IViewAPI* p_view_api);

  void Initialise() final;

  void RenderObject(int x, int y, float scale, float render_offset_y) const final;

private:
  float CalculateLocation(int val, float scale) const;

  view::IViewAPI* _p_view_api;
};

}
}
}
