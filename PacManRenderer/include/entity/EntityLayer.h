#pragma once

#include <manager/IViewManager.h>
#include <entity/IEntityManager.h>

#include "IRenderLayer.h"


namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="EntityLayer" /> visualises a <see cref="IEntityComponent" />.
/// </summary>
/// <seealso cref="IRenderLayer" />
class EntityLayer final : public IRenderLayer {
public:  
  /// <summary>
  /// Construct a new <see cref="EntityLayer" />.
  /// </summary>
  /// <param name="scale">The scale.</param>
  /// <param name="p_view_manager">A pointer to the view manager.</param>
  /// <param name="p_entity_manager">A pointer to the state entity manager.</param>
  /// <precondition>
  /// | p_view_manager != nullptr
  /// | p_entity_manager != nullptr
  /// </precondition>
  EntityLayer(float scale,
              view::IViewManager* p_view_manager,
              state::IEntityManager* p_entity_manager);

  void Initialise() final;
  void Render() const final;

private:    
  /// <summary>
  /// Initialises the sprites used by this <see cref="EntityLayer" />.
  /// </summary>
  void InitialiseSprites();

  /// <summary>
  /// The scale to render with.
  /// </summary>
  const float scale;

  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="EntityLayer" />. 
  /// </summary>
  view::IViewManager* p_view_manager;
  
  /// <summary>
  /// A pointer to the <see cref="IEntityManager" /> used by this
  /// <see cref="EntityLayer" />. 
  /// </summary>
  state::IEntityManager* p_entity_manager;
};

}
}
