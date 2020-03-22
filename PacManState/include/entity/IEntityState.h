#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/Direction.h"
#include "entity/IEntityAxis.h"


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
  static std::unique_ptr<IEntityState> Construct(float x, float y, Direction dir, float speed);

  virtual ~IEntityState() {}
    
  /// <summary>
  /// Gets the x <see cref="IEntityAxis"/> of this <see cref="IEntityState"/>.
  /// </summary>
  /// <returns>The x <see cref="IEntityAxis"/>.</returns>
  virtual IEntityAxis* GetXAxis() const = 0;

  /// <summary>
  /// Gets the y <see cref="IEntityAxis"/> of this <see cref="IEntityState"/>.
  /// </summary>
  /// <returns>The x <see cref="IEntityAxis"/>.</returns>
  virtual IEntityAxis* GetYAxis() const = 0;
  
  /// <summary>
  /// Get the <see cref="Direction"/> of this <see cref="IEntityState" />.
  /// </summary>
  /// <returns> 
  /// The <see cref="Direction" /> of this <see cref="IEntityState" />. 
  /// </returns>
  virtual Direction GetDirection() const = 0;
  
  /// <summary>
  /// Set the direction of this <see cref="IEntityState" />.
  /// </summary>
  /// <param name="direction"> The new  <see cref="Direction" />. </param>
  // <postcondition>
  // | (new this)->GetDirection() == <paramref name="direction" />
  // </postcondition>
  virtual void SetDirection(Direction direction) = 0;
  
  /// <summary>
  /// Get the speed of this <see cref="IEntityState" />.
  /// </summary>
  /// <returns>The speed of this <see cref="IEntityState" />.</returns>
  virtual float GetSpeed() const = 0;
  
  /// <summary>
  /// Set the speed of this <see cref="IEntityState" /> to
  /// <paramref name="speed" />.
  /// </summary>
  /// <param name="speed">The new speed.</param>
  /// <postcondition>
  /// | (new this)->GetSpeed() == <paramref name="speed" />
  /// </postcondition>
  virtual void SetSpeed(float speed) = 0;
  
  /// <summary>
  /// Value indicating whether this <see cref="IEntityState"/> is moving.
  /// </summary>
  /// <returns>
  ///   <c>true</c> if this instance is moving; otherwise, <c>false</c>.
  /// </returns>
  virtual bool IsMoving() const = 0;
  
  /// <summary>
  /// Sets the value indicating whether this <see cref="IEntityState"/> is 
  /// moving.
  /// </summary>
  /// <param name="is_moving">New IsMoving Value.</param>
  /// <post-condition>
  /// | (new this)->IsMoving() == is_moving;
  /// </post-condition>
  virtual void SetIsMoving(bool is_moving) = 0;

  /// <summary>
  /// Resets this <see cref="IEntityState"/>.
  /// </summary>
  virtual void Reset() = 0;
};

}
}
