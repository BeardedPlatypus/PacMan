#pragma once

#include <string>
#include <memory>

#include "entity/animation/IAnimationUpdateBehaviour.h"
#include "entity/render/IValueProvider.h"
#include "IViewAPI.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// The <see cref="ActiveInverseAnimatiounUpdateBehaviour"/> updates the provided
/// animation with the specified difference in time if it is currently being active,
/// else it will be updated with the negative difference in time.
/// Whether the animation is active is determined by the provided <see cref="IValueProvider{std::string}"/>.
/// </summary>
/// <seealso cref="IAnimationUpdateBehaviour" />
class ActiveInverseAnimationUpdateBehaviour final : public IAnimationUpdateBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="ActiveInverseAnimatiounUpdateBehaviour" />.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI" />.</param>
  /// <param name="animation_label">The animation label to update.</param>
  /// <param name="p_active_label_provider">A pointer to the active label provider.</param>
  ActiveInverseAnimationUpdateBehaviour(view::IViewAPI* p_view_api,
                                        const std::string& animation_label,
                                        std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider);

  void Update(float dtime) final;

private:
  view::IViewAPI* _p_view_api;
  const std::string _animation_label;
  std::shared_ptr<render::IValueProvider<std::string>> _p_active_label_provider;
};

}
}
}
}
