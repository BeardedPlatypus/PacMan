#pragma once

#include <manager/IViewManager.h>

#include "IRenderComponent.h"
#include "field/IField.h"


namespace pacman {
namespace renderer {

/// <summary>
/// <see cref="FieldLayer" /> visualises a <see cref="IField" />.
/// </summary>
/// <seealso cref="IRenderComponent" />
class FieldLayer final : public IRenderComponent {
public:    
  /// <summary> Name of the sprite file containing the field. </summary>
  const std::string field_sprite_file = "field.png";

  /// <summary>
  /// Construct a new <see cref="FieldLayer"/> observing the specified 
  /// <see cref="IField" />.
  /// </summary>
  /// <param name="p_field">The p field.</param>
  FieldLayer(view::IViewManager p_view_manager,
             const state::field::IField* const p_field);

  void Initialise() final;
  void Render() const final;

private:  
  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="FieldLayer" />. 
  /// </summary>
  view::IViewManager* p_view_manager;

  /// <summary> 
  /// Pointer to the <see cref="IField" /> this <see cref="FieldLayer" /> 
  /// observes.
  /// </summary>
  const state::field::IField* const p_field;
};

}
}
