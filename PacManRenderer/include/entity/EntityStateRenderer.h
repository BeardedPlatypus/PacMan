#pragma once

#include <memory>
#include <unordered_map>

#include "entity/IEntityStateRenderer.h"
#include "entity/animation/IAnimationRenderConfig.h"
#include "entity/render/EntityRenderConfig.h"
#include "IViewAPI.h"


namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="EntityStateRenderer"/> provides the methods to render entity states.
/// </summary>
/// <seealso cref="IEntityStateRenderer" />
class EntityStateRenderer final : public IEntityStateRenderer {
public:  
  /// <summary>
  /// Creates a new <see cref="EntityStateRenderer"/>.
  /// </summary>
  /// <param name="p_render_config">
  /// A pointer to the <see cref="render::EntityRenderConfig"/> of this <see cref="EntityStateRenderer"/>.
  /// </param>
  explicit EntityStateRenderer(std::unique_ptr<render::EntityRenderConfig> p_render_config,
                        std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_animation_configs,
                        view::IViewAPI* p_view_api);

  void Initialise() final;
  void Update(float dtime) final;
  void Render(float scale,
              float render_offset_y) const final;
  void Reset() final;

private:
  std::unique_ptr<render::EntityRenderConfig> _p_render_config;
  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> _p_animation_configs;
  view::IViewAPI* _p_view_api;
};

}
}
}
