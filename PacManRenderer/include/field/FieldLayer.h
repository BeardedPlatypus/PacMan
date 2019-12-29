#pragma once

#include <IViewAPI.h>
#include <unordered_map>
#include <vector>

#include "IRenderLayer.h"
#include "field/IField.h"
#include "field/FieldLayerSpriteDescription.h"
#include "field/EnumClassHash.h"
#include "field/FieldSpriteType.h"


namespace pacman {
namespace renderer {

/// <summary>
/// <see cref="FieldLayer" /> visualises a <see cref="IField" />.
/// </summary>
/// <seealso cref="IRenderComponent" />
class FieldLayer final : public IRenderLayer {
public:    
  /// <summary>
  /// Construct a new <see cref="FieldLayer"/> observing the specified 
  /// <see cref="IField" />.
  /// </summary>
  /// <param name="p_field">The p field.</param>
  FieldLayer(float scale,
             view::IViewAPI* p_view_api,
             state::field::IField* p_field);

  void Initialise() final;
  void Render() const final;

private:      
  /// <summary>
  /// The scale to render with
  /// </summary>
  const float scale;

  /// <summary>
  /// Initialise the sprites of this <see cref="FieldLayer" />.
  /// </summary>
  void InitialiseSprites();
  
  /// <summary>
  /// Initialises the render field of this <see cref="FieldLayer" />.
  /// </summary>
  void InitialiseRenderField();

  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="FieldLayer" />. 
  /// </summary>
  view::IViewAPI* p_view_api;

  /// <summary> 
  /// Pointer to the <see cref="IField" /> this <see cref="FieldLayer" /> 
  /// observes.
  /// </summary>
  state::field::IField* p_field;
  
  /// <summary>
  /// Pointer to the set of sprites that should be rendered as part of this
  /// <see cref="FieldLayer" />
  /// </summary>
  std::unique_ptr<std::unordered_map<FieldSpriteType,
                                     std::unique_ptr<std::vector<FieldLayerSpriteDescription>>,
                                     EnumClassHash>> p_sprite_map = 
    std::make_unique<std::unordered_map<FieldSpriteType, 
                                        std::unique_ptr<std::vector<FieldLayerSpriteDescription>>, 
                                        EnumClassHash>>();
};

}
}
