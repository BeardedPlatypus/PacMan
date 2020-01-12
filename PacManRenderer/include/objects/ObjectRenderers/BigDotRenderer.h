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
  BigDotRenderer() {}

  void RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const final;

private:
  float CalculateLocation(int val, float scale) const;
};

}
}
}
