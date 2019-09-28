#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <entity/IEntityState.h>
#include <optional>

#include "entity/IUpdatableEntityAxis.h"


namespace pacman {
namespace update {
  
/// <summary>
/// <see cref="IUpdatablePlayerEntity" /> wraps and extends a 
/// <see cref="state::IEntityState" />.
/// </summary>
class DllExport IUpdatablePlayerEntity {
public:  
  /// <summary>
  /// Construct a new <see cref="IUpdatablePlayerEntity" /> with the given 
  /// <paramref name="p_player_state" />.
  /// </summary>
  /// <param name="p_player_state">
  /// A pointer to the <see cref="state::IEntityState" /> it will wrap.
  /// </param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the new 
  /// <see cref="IUpdatablePlayerEntity"/>.
  /// </returns>
  static std::unique_ptr<IUpdatablePlayerEntity> Construct(state::IEntityState* p_player_state);
  
  /// <summary>
  /// Get the x axis of this <see cref="IUpdatablePlayerEntity"/>.
  /// </summary>
  /// <returns> A pointer to the x axis.</returns>
  virtual IUpdatableEntityAxis* GetXAxis() const = 0;

  /// <summary>
  /// Get the y axis of this <see cref="IUpdatablePlayerEntity"/>.
  /// </summary>
  /// <returns> A pointer to the y axis.</returns>
  virtual IUpdatableEntityAxis* GetYAxis() const = 0;
  
  /// <summary>
  /// Get the speed of this <see cref="IUpdatablePlayerEntity"/>.
  /// </summary>
  /// <returns>The speed.</returns>
  virtual float GetSpeed() const = 0;
  
  /// <summary>
  /// Get the current moving direction of this 
  /// <see cref="IUpdatablePlayerEntity" />.
  /// </summary>
  /// <returns>The current moving direction.</returns>
  virtual state::Direction GetMovingDirection() const = 0;  

  /// <summary>
  /// Set the current moving direction of this
  /// <see cref="IUpdatablePlayerEntity" /> to <paramref name="direction" />.
  /// </summary>
  /// <param name="direction">The direction.</param>
  /// <postcondition>
  /// | (new this)->GetMovingDirection() == direction;
  /// </postcondition
  virtual void SetMovingDirection(state::Direction direction) = 0;
  
  /// <summary>
  /// Get the next direction of this <see cref="IUpdatablePlayerEntity" />.
  /// </summary>
  /// <returns>The next direction.</returns>
  virtual std::optional<state::Direction> GetNextDirection() const = 0;
  
  /// <summary>
  /// Set the next direction of this <see cref="IUpdatablePlayerEntity" /> 
  /// to the specified <paramref name="direction"/>.
  /// </summary>
  /// <param name="direction">The direction.</param>
  /// <postcondition>
  /// | (new this)->GetNextDirection() == direction;
  /// </postcondition
  virtual void SetNextDirection(std::optional<state::Direction> direction) = 0;
};

}
}
