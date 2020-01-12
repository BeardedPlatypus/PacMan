#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"

namespace pacman {
namespace renderer {
namespace objects {

class SmallDotRenderer final : public IObjectRenderer {
public:
  void RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const final;

private:
  float CalculateLocation(int val, float scale) const;
};

}
}
}
