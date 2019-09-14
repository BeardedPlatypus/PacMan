#pragma once

#include "field/FieldSpriteOrientation.h"

namespace pacman {
namespace renderer {
  
/// <summary>
/// The <see cref="FieldLayerSpriteDescription"/> provides a description for
/// a single sprite, it defines the position and the orientation of this sprite.
/// </summary>
struct FieldLayerSpriteDescription {
  /// <summary>
  /// Construct a new <see cref="FieldLayerSpriteDescription"/>.
  /// </summary>
  /// <param name="x">The x position.</param>
  /// <param name="y">The y position.</param>
  /// <param name="orientation">The orientation.</param>
  FieldLayerSpriteDescription(int x, int y,
                              FieldSpriteOrientation orientation) :
      x(x), y(y),
      Orientation(orientation) {}

  /// <summary>
  /// The orientation of the corresponding sprite.
  /// </summary>
  const FieldSpriteOrientation Orientation;
  
  /// <summary>
  /// The x location of this Sprite.
  /// </summary>
  const int x;

  /// <summary>
  /// The y location of this Sprite.
  /// </summary>
  const int y;
};

}
}
