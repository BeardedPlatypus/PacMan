#pragma once

#include <IViewAPI.h>
#include <field/object/IFieldObjectManager.h>

#include <memory>
#include <unordered_map>

#include "IRenderLayer.h"
#include "objects/ObjectRenderers/IObjectRenderer.h"


namespace pacman {
namespace renderer {

using RenderMapping = std::unordered_map<state::field::FieldObjectType, std::unique_ptr<objects::IObjectRenderer>>;

/// <summary>
/// <see cref="ObjectLayer"/> visualises the objects contained in a 
/// <see cref="IFieldObjectManager"/>.
/// </summary>
/// <seealso cref="IRenderLayer" />
class ObjectLayer final : public IRenderLayer {
public:  
  /// <summary>
  /// Create a new <see cref="ObjectLayer"/>.
  /// </summary>
  /// <param name="scale">The scale with which to render.</param>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI"/>.</param>
  /// <param name="p_object_manager">A pointer to the <see cref="IFieldObjectManager"/>.</param>
  /// <param name="p_obj_renderers">A mapping of objects to their corresponding renderers.</param>
  ObjectLayer(float scale,
              view::IViewAPI* p_view_api,
              state::field::IFieldObjectManager* p_object_manager,
              std::unique_ptr<RenderMapping> p_obj_renderers);

  void Initialise() final;

  inline void Update(float dtime) final {
    // ObjectLayer is static.
  }

  void Render() const final;

private:
  /// <summary>
  /// The scale to render with
  /// </summary>
  const float scale;

  /// <summary>
  /// Initialise the sprites of this <see cref="ObjectLayer" />.
  /// </summary>
  void InitialiseSprites();
  
  /// <summary>
  /// Determines whether this has a renderer for the specified 
  /// <paramref name="type"/>.
  /// </summary>
  /// <param name="type">The type.</param>
  /// <returns>
  ///   <c>true</c> if [has renderer for type]; otherwise, <c>false</c>.
  /// </returns>
  bool HasRendererForType(state::field::FieldObjectType type) const;

  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="FieldLayer" />. 
  /// </summary>
  view::IViewAPI* p_view_api;
  
  /// <summary>
  /// A pointer to the observed <see cref="state::field::IFieldObjectManager"/>.
  /// </summary>
  state::field::IFieldObjectManager* p_object_manager;

  /// <summary>
  /// A <see cref="std::unique_ptr"/> containing a mapping from 
  /// <see cref="state::field::FieldObjectType"/> to its corresponding
  /// <see cref="IObjectRenderer"/>.
  /// </summary>
  std::unique_ptr<RenderMapping> p_render_mapping;
};

}
}
