#pragma once

#include <string>

#include "entity/animation/IAnimationUpdateBehaviour.h"
#include "IViewAPI.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// The <see cref="StaticAnimationUpdateBehaviour"/> updates the provided 
/// animation always with the provided difference in time.
/// </summary>
/// <seealso cref="IAnimationUpdateBehaviour" />
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
