#pragma once

#include <array>
#include "IUpdatablePlayerEntity.h"

namespace pacman {
namespace update {

/// <summary>
/// <see cref="UpdatablePlayerEntity" /> wraps and extends a 
/// <see cref="state::ISpatialState" />.
/// </summary>
/// <seealso cref="IUpdatablePlayerEntity" />
class UpdatablePlayerEntity final : public IUpdatablePlayerEntity {
public:  
  /// <summary>
  /// Creates a new <see cref="UpdatablePlayerEntity"/>.
  /// </summary>
  /// <param name="p_player_state"> 
  /// Pointer to the observed <see cref="ISpatialState"/>.
  /// </param>
  /// <param name="p_x_axis">
  /// <see cref="std::unique_ptr{IUpdatableEntityAxis}"/> containing the x-axis.
  /// </param>
  /// <param name="p_y_axis">
  /// <see cref="std::unique_ptr{IUpdatableEntityAxis}"/> containing the y-axis.
  /// </param>
  /// <param name="p_x_movement_axis">
  /// <see cref="std::unique_ptr{IPlayerMovementAxis}"/> containing the movement x-axis.
  /// </param>
  /// <param name="p_y_movement_axis">
  /// <see cref="std::unique_ptr{IPlayerMovementAxis}"/> containing the movement y-axis.
  /// </param>
  explicit UpdatablePlayerEntity(state::ISpatialState* p_player_state,
                                 std::unique_ptr<IUpdatableEntityAxis> p_x_axis,
                                 std::unique_ptr<IUpdatableEntityAxis> p_y_axis,
                                 std::unique_ptr<IPlayerMovementAxis> p_x_movement_axis,
                                 std::unique_ptr<IPlayerMovementAxis> p_y_movement_axis);

  AxisType GetActiveAxisType() const final;
  void SetActiveAxisType(AxisType new_active_axis_type) final;

  IUpdatableEntityAxis* GetXAxis() const final;
  IUpdatableEntityAxis* GetYAxis() const final;
  IUpdatableEntityAxis* GetActiveAxis() const final;

  IPlayerMovementAxis* GetPlayerMovementXAxis() const final;
  IPlayerMovementAxis* GetPlayerMovementYAxis() const final;
  IPlayerMovementAxis* GetActivePlayerMovementAxis() const final;
  IPlayerMovementAxis* GetInactivePlayerMovementAxis() const final;
  void SwapActiveAxis() final;

  float GetSpeed() const final;

  state::Direction GetMovingDirection() const final;
  void SetMovingDirection(state::Direction direction) final;

  void Update(float dt) final;

  void SetIsMoving(bool is_moving) final;

  void Reset() final;
private:
  state::ISpatialState* p_player_state;

  int active_axis = 0;

  std::array<std::unique_ptr<IUpdatableEntityAxis>, 2> axii;
  std::array<std::unique_ptr<IPlayerMovementAxis>, 2> movement_axii;
};

}
}
