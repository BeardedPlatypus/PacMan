#pragma once

#include <string>

#include "entity/update/IAnimationUpdateBehaviour.h"
#include "IViewAPI.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace update {

class StaticAnimationUpdateBehaviour final : public IAnimationUpdateBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="StaticAnimationUpdateBehaviour"/>.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI"/>.</param>
  /// <param name="animation_label">The animation label to update.</param>
  StaticAnimationUpdateBehaviour(view::IViewAPI* p_view_api,
                                 const std::string& animation_label);

  void Update(float dtime) final;

private:
  view::IViewAPI* _p_view_api;
  const std::string _animation_label;
};

}
}
}
}
