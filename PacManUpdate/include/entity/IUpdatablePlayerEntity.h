#pragma once

#include <memory>
#include <entity/IEntityState.h>
#include <optional>

#include "entity/IUpdatableEntityAxis.h"
#include "entity/IPlayerMovementAxis.h"

#include "entity/AxisType.h"

namespace pacman {
namespace update {
  
/// <summary>
/// <see cref="IUpdatablePlayerEntity" /> wraps and extends a 
/// <see cref="state::IEntityState" />.
/// </summary>
class IUpdatablePlayerEntity {
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
  /// Get the active axis type.
  /// </summary>
  /// <returns>The current active axis type.</returns>
  virtual AxisType GetActiveAxisType() const = 0;
  
  /// <summary>
  /// Set the active axis type.
  /// </summary>
  /// <param name="new_active_axis_type">The new active axis.</param>
  virtual void SetActiveAxisType(AxisType new_active_axis_type) = 0;
  
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
  /// Get the axis on which pacman is travelling.
  /// </summary>
  /// <returns>The axis on which pacman is currently travelling.</returns>
  virtual IUpdatableEntityAxis* GetActiveAxis() const = 0;
  
  /// <summary>
  /// Get the speed of this <see cref="IUpdatablePlayerEntity"/>.
  /// </summary>
  /// <returns>The speed.</returns>
  virtual float GetSpeed() const = 0;
  
  /// <summary>
  /// Get the player movement x-axis.
  /// </summary>
  /// <returns>The x <see cref="IPlayerMovementAxis"/>.</returns>
  virtual IPlayerMovementAxis* GetPlayerMovementXAxis() const = 0;

  /// <summary>
  /// Get the player movement x-axis.
  /// </summary>
  /// <returns>The x <see cref="IPlayerMovementAxis"/>.</returns>
  virtual IPlayerMovementAxis* GetPlayerMovementYAxis() const = 0;
  
  /// <summary>
  /// Gets the player movement axis on which pacman is travelling.
  /// </summary>
  /// <returns>The axis on which pacman is travelling.</returns>
  virtual IPlayerMovementAxis* GetActivePlayerMovementAxis() const = 0;

  /// <summary>
  /// Gets the player movement axis on which pacman is NOT travelling.
  /// </summary>
  /// <returns>The axis on which pacman is NOT travelling.</returns>
  virtual IPlayerMovementAxis* GetInactivePlayerMovementAxis() const = 0;
  
  /// <summary>
  /// Swap the active and inactive axii.
  /// </summary>
  virtual void SwapActiveAxis() = 0;
  
  /// <summary>
  /// Get the current moving direction of this 
  /// <see cref="IUpdatablePlayerEntity" />.
  /// </summary>
  /// <returns>The current moving direction.</returns>
  virtual state::Direction GetMovingDirection() const = 0;  
  
  /// <summary>
  /// Set the current moving direction of this 
  /// <see cref="IUpdatablePlayerEntity"/>.
  /// </summary>
  /// <param name="direction">The new direction.</param>
  virtual void SetMovingDirection(state::Direction direction) = 0;

  /// <summary>
  /// Update this <see cref="IUpdatablePlayerEntity"/> with the provided time change.
  /// </summary>
  /// <param name="dt">The time passed since the last frame.</param>
  virtual void Update(float dt) = 0;
  
  /// <summary>
  /// Set this <see cref="IUpdatablePlayerEntity"/>'s is moving to 
  /// <paramref name="is_moving"/>.
  /// </summary>
  /// <param name="is_moving">New is moving value.</param>
  virtual void SetIsMoving(bool is_moving) = 0;
};

}
}
