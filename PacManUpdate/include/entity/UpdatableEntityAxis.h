#pragma once

#include "entity/IUpdatableEntityAxis.h"


namespace pacman {
namespace update {

class UpdatableEntityAxis final : public IUpdatableEntityAxis {
public:
  explicit UpdatableEntityAxis(state::IEntityAxis* p_axis);

  float GetPosition() const final;
  void SetPosition(float new_position) final;
  int GetCurrentIndex() const final;
  int GetPreviousIndex() const final;
  int GetNextTileCenter() const final;
  int GetPreviousTileCenter() const final;

  void Move(float d_pos) final;

  inline AxisDirection GetCurrentAxisDirection() const final { return this->current_direction; }
  inline void SetCurrentAxisDirection(AxisDirection new_direction) final { this->current_direction = new_direction; }

  inline AxisDirection GetPreviousAxisDirection() const final { return this->previous_direction; }
  inline void SetPreviousAxisDirection(AxisDirection new_direction) final { this->previous_direction = new_direction; }

private:  
  /// <summary>
  /// A pointer to the <see cref="state::IEntityAxis" />.
  /// </summary>
  state::IEntityAxis* p_axis;
  
  /// <summary>
  /// The previous index
  /// </summary>
  int previous_index;
  
  /// <summary>
  /// The current direction
  /// </summary>
  AxisDirection current_direction;
  
  /// <summary>
  /// The previous direction
  /// </summary>
  AxisDirection previous_direction;
};

}
}
