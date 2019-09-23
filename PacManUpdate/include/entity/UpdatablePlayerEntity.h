#pragma once

#include "IUpdatablePlayerEntity.h"

namespace pacman {
namespace update {

class UpdatablePlayerEntity final : public IUpdatablePlayerEntity {
public:
  UpdatablePlayerEntity(state::IEntityState* p_player_state);

  inline IUpdatableEntityAxis* GetXAxis() const final;
  inline IUpdatableEntityAxis* GetYAxis() const final;

  inline float GetSpeed() const final;

  inline state::Direction GetMovingDirection() const final;
  inline void SetMovingDirection(state::Direction direction) final;

  inline std::optional<state::Direction> GetNextDirection() const final;
  inline void SetNextDirection(std::optional<state::Direction> direction) final;

private:
  state::IEntityState* p_player_state;

  std::unique_ptr<IUpdatableEntityAxis> p_x_axis;
  std::unique_ptr<IUpdatableEntityAxis> p_y_axis;


  std::optional<state::Direction> next_direction;
};

}
}
