#pragma once

#include <memory>

#include "AxisDirection.h"


namespace pacman {
namespace update {

/// <summary>
/// <see cref="IPlayerMovementAxis" /> interface describes a single movment
/// axis which the player can control. This is used within the 
/// <see cref="IUpdatablePlayerEntity"/> which can query this 
/// <see cref="IPlayerMovementAxis"/>. to determine the next direction.
/// </summary>
class IPlayerMovementAxis {
public:  
  /// <summary>
  /// Construct a new <see cref="IPlayerMovementAxis"/>.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> to the constructed
  /// <see cref="IPlayerMovementAxis"/>.
  /// </returns>
  static std::unique_ptr<IPlayerMovementAxis> Construct();
  
  /// <summary>
  /// Update this <see cref="IPlayerMovementAxis"/> with <paramref name ="dt"/>
  /// time passed.
  /// </summary>
  /// <param name="dt">The the time passed in seconds.</param>
  virtual void Update(float dt) = 0;
  
  /// <summary>
  /// Get the next direction.
  /// </summary>
  /// <returns>The next direction on this <see cref="IPlayerMovementAxis"/>.</returns>
  virtual AxisDirection GetNextDirection() const = 0;
  
  /// <summary>
  /// Change the state with the given event.
  /// </summary>
  /// <param name="axis_direction">The axis direction.</param>
  virtual void ChangeState(AxisDirection axis_direction) = 0;
};

}
}
