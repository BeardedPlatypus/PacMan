#pragma once

#include "entity/IUpdatableEntityAxis.h"


namespace pacman {
namespace update {

class UpdatableEntityAxis final : public IUpdatableEntityAxis {
public:
  UpdatableEntityAxis(state::IEntityAxis* p_axis);

  inline float GetPosition() const final;
  inline int GetCurrentIndex() const final;
  inline int GetPreviousIndex() const final;

  void Move(float d_pos) final;

private:  
  /// <summary>
  /// A pointer to the <see cref="state::IEntityAxis" />.
  /// </summary>
  state::IEntityAxis* p_axis;
  
  /// <summary>
  /// The previous index
  /// </summary>
  int previous_index;
};

}
}
