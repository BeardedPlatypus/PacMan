#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <entity/IEntityState.h>
#include <optional>

#include "entity/IUpdatableEntityAxis.h"


namespace pacman {
namespace update {

class DllExport IUpdatablePlayerEntity {
public:
  static std::unique_ptr<IUpdatablePlayerEntity> Construct(state::IEntityState* p_player_state);

  virtual IUpdatableEntityAxis* GetXAxis() const = 0;
  virtual IUpdatableEntityAxis* GetYAxis() const = 0;

  virtual float GetSpeed() const = 0;

  virtual state::Direction GetMovingDirection() const = 0;
  virtual void SetMovingDirection(state::Direction direction) = 0;

  virtual std::optional<state::Direction> GetNextDirection() const = 0;
  virtual void SetNextDirection(std::optional<state::Direction> direction) = 0;
};

}
}
