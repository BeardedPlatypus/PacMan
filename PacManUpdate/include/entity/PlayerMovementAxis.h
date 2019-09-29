#pragma once

#include "IPlayerMovementAxis.h"


namespace pacman {
namespace update {
  
/// <summary>
/// <see cref="PlayerMovementAxis"/> provides a concrete implementation of
/// <see cref="IPlayerMovementAxis"/>.
/// </summary>
/// <seealso cref="IPlayerMovementAxis" />
class PlayerMovementAxis final : public IPlayerMovementAxis {
public:  
  /// <summary>
  /// Construct a new <see cref="PlayerMovementAxis"/>.
  /// </summary>
  PlayerMovementAxis();

  void Update(float dt) final;
  AxisDirection GetNextDirection() const final;
  void ChangeState(AxisDirection changedEventDirection);

private:  
  /// <summary>
  /// Set of states this <see cref="PlayerMovementAxis"/> can be in.
  /// </summary>
  enum class InternalState {
    NoPressed,
    PositivePressed,
    PositiveReleased,
    NegativePressed,
    NegativeReleased,
    PositiveThenNegativePressed,
    NegativeThenPositivePressed,
  };
  
  /// <summary>
  /// The current state of this <see cref="PlayerMovementAxis"/>.
  /// </summary>
  InternalState current_state;
  
  /// <summary>
  /// The time elapsed since going into a release key press.
  /// </summary>
  float time_elapsed;

  const float sticky_key_time = 0.05;
};

}
}
