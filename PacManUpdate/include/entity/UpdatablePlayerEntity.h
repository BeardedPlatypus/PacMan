#pragma once

#include <array>
#include "IUpdatablePlayerEntity.h"

namespace pacman {
namespace update {

class UpdatablePlayerEntity final : public IUpdatablePlayerEntity {
public:
  UpdatablePlayerEntity(state::IEntityState* p_player_state);

  inline AxisType GetActiveAxisType() const final;
  inline void SetActiveAxisType(AxisType new_active_axis_type) final;

  inline IUpdatableEntityAxis* GetXAxis() const final;
  inline IUpdatableEntityAxis* GetYAxis() const final;
  inline IUpdatableEntityAxis* GetActiveAxis() const final;

  inline IPlayerMovementAxis* GetPlayerMovementXAxis() const final;
  inline IPlayerMovementAxis* GetPlayerMovementYAxis() const final;
  inline IPlayerMovementAxis* GetActivePlayerMovementAxis() const final;
  inline IPlayerMovementAxis* GetInactivePlayerMovementAxis() const final;
  inline void SwapActiveAxis() final;

  inline float GetSpeed() const final;

  inline state::Direction GetMovingDirection() const final;
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
