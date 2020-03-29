#pragma once

#include <memory>
#include <vector>

#include "IRenderLayer.h"
#include "entity/IRenderEntity.h"

namespace pacman {
namespace renderer {

/// <summary>
/// <see cref="EntityLayer"/> is responsible for rendering all Entities, 
/// i.e. pacman and the ghosts.
/// </summary>
/// <seealso cref="IRenderLayer" />
class EntityLayer final : public IRenderLayer {
public:  
  /// <summary>
  /// Creates a new <see cref="EntityLayer"/>.
  /// </summary>
  /// <param name="p_render_entities">The collection of <see cref="entity::IEntityStateRenderer"/> to render.</param>
  /// <param name="scale">The scale.</param>
  /// <param name="render_offset_y">The render offset y.</param>
  EntityLayer(std::unique_ptr<std::vector<std::unique_ptr<entity::IRenderEntity>>> p_render_entities,
              float scale, 
              float render_offset_y);

  void Initialise() final;
  void Update(float dtime);
  void Render() const final;

private:  
  /// <summary>
  /// A pointer to the render entities rendered by this EntityLayer.
  /// </summary>
  std::unique_ptr<std::vector<std::unique_ptr<entity::IRenderEntity>>> _p_render_entities;

  /// <summary>
  /// The scale to render with.
  /// </summary>
  const float _scale;

  /// <summary>
  /// The render offset of this layer
  /// </summary>
  const float _render_offset_y;
};

}
}
