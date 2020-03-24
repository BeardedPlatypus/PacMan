#pragma once

#include <memory>

#include "entity/IRenderEntity.h"
#include "entity/render/EntityRenderConfig.h"
#include "IViewAPI.h"


namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="RenderEntity"/> provides the methods to render entities.
/// </summary>
/// <seealso cref="IRenderEntity" />
class RenderEntity final : public IRenderEntity {
public:  
  /// <summary>
  /// Creates a new <see cref="RenderEntity"/>.
  /// </summary>
  /// <param name="p_render_config">
  /// A pointer to the <see cref="render::EntityRenderConfig"/> of this <see cref="RenderEntity"/>.
  /// </param>
  explicit RenderEntity(std::unique_ptr<render::EntityRenderConfig> p_render_config,
                        view::IViewAPI* p_view_api);

  void Initialise() final;
  void Update(float dtime) final;
  void Render(float scale,
              float render_offset_y) const final;

private:
  std::unique_ptr<render::EntityRenderConfig> _p_render_config;
  view::IViewAPI* _p_view_api;
};

}
}
}
