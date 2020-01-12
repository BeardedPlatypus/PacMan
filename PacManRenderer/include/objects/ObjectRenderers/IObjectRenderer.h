#pragma once
#include <IViewAPI.h>


namespace pacman {
namespace renderer {
namespace objects {

class IObjectRenderer {
public:
  virtual void RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const = 0;
};

}
}
}
