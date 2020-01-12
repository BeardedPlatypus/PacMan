#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"


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
  void RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const final;

private:
  float CalculateLocation(int val, float scale) const;
};

}
}
}
