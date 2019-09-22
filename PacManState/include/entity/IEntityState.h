#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/Direction.h"


namespace pacman {
namespace state {

/// <summary>
/// <see cref="IEntityState" /> describes the state of an entity within the
/// pacman game.
/// </summary>
class DllExport IEntityState {
public:  
  /// <summary>
  /// Construct a new <see cref="IEntityState" /> with the given parameters.
  /// </summary>
  /// <param name="x"> The world x position. </param>
  /// <param name="y"> The world y position. </param>
  /// <param name="dir"> The <see cref="Direction" />. </param>
  /// <returns>A <see cref="std::unique_ptr"/> containing an instance of a <see cref="IEntityState"/>.</returns>
  static std::unique_ptr<IEntityState> Construct(float x, float y, Direction dir);

  virtual ~IEntityState() {}
  
  /// <summary>
  /// Get the world x-position of this <see cref="IEntityState" />.
  /// </summary>
  /// <returns> 
  /// The x-position of this <see cref="IEntityState" />
  /// </returns>
  virtual float GetXPosition() const = 0;
  
  /// <summary>
  /// Get the world y-position of this <see cref="IEntityState" />.
  /// </summary>
  /// <returns> 
  /// The y-position of this <see cref="IEntityState" />
  /// </returns>
  virtual float GetYPosition() const = 0;
  
  /// <summary>
  /// Set the world x-position of this <see cref="IEntityState" />.
  /// </summary>
  /// <param name="new_x">The ne world x position.</param>
  // <post-condition> 
  // | (new this)->GetXPosition() == <paramref name="new_x" />
  // </post-condition>
  virtual void SetXPosition(float new_x) = 0;

  /// <summary>
  /// Set the world y-position of this <see cref="IEntityState" />.
  /// </summary>
  /// <param name="new_y">The ne world y position.</param>
  // <post-condition> 
  // | (new this)->GetYPosition() == <paramref name="new_y" />
  // </post-condition>
  virtual void SetYPosition(float new_y) = 0;
  
  /// <summary>
  /// Get the direction of this <see cref="Direction" />.
  /// </summary>
  /// <returns> 
  /// The <see cref="Direction" /> of this <see cref="IEntityState" />. 
  /// </returns>
  virtual Direction GetDirection() const = 0;
  
  /// <summary>
  /// Set the direction of this <see cref="IEntityState" />.
  /// </summary>
  /// <param name="direction"> The new  <see cref="Direction" />. </param>
  // <post-condition>
  // | (new this)->GetDirection() == <paramref name="direction" />
  // </post-condition>
  virtual void SetDirection(Direction direction) = 0;
};

}
}