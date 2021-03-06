#pragma once

#include "field/FieldSpriteOrientation.h"
#include "field/FieldSpriteType.h"


namespace pacman {
namespace renderer {
  
/// <summary>
/// The <see cref="FieldSpriteDescription"/> provides both the orientation and
/// type of a corresponding FieldSprite. This is used to construct the 
/// <see cref="FiledLayer" />.
/// </summary>
struct FieldSpriteDescription {
  /// <summary>
  /// Construct a new <see cref="FieldSpriteDescription"/>.
  /// </summary>
  /// <param name="spriteType">Type of the sprite.</param>
  /// <param name="orientation">The orientation.</param>
  FieldSpriteDescription(FieldSpriteType spriteType,
                         FieldSpriteOrientation orientation) : 
      SpriteType(spriteType),
      Orientation(orientation)
  {};
  
  /// <summary>
  /// The type of field sprite of the corresponding sprite.
  /// </summary>
  const FieldSpriteType SpriteType;  

  /// <summary>
  /// The orientation of the corresponding sprite.
  /// </summary>
  const FieldSpriteOrientation Orientation;

};

}
}
