#pragma once

#include <array>
#include "IUpdatablePlayerEntity.h"

namespace pacman {
namespace update {

class UpdatablePlayerEntity final : public IUpdatablePlayerEntity {
public:
  UpdatablePlayerEntity(state::IEntityState* p_player_state);

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

private:
  state::IEntityState* p_player_state;

  int active_axis;

  std::array<std::unique_ptr<IUpdatableEntityAxis>, 2> axii;
  std::array<std::unique_ptr<IPlayerMovementAxis>, 2> movement_axii;
};

}
}
