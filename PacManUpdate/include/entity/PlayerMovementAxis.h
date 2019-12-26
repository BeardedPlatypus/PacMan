#pragma once

#include "IPlayerMovementAxis.h"
#include "state_machine/values/PlayerControlValue.h"
#include "state_machine/IStateMachine.h"


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
  void ChangeState(state_machine::PlayerControlEvent control_event);

private:  
  /// <summary>
  /// Initialise the state machine of this <see cref="PlayerMovementAxis"/>.
  /// </summary>
  void InitialiseStateMachine();

  /// <summary>
  /// A pointer to the state machine of this <see cref="PlayerMovementAxis"/>.
  /// </summary>
  std::unique_ptr<state_machine::IStateMachine<state_machine::PlayerControlValue,
                                               state_machine::PlayerControlEvent>> p_state;
  
  /// <summary>
  /// The time elapsed since going into a release key press.
  /// </summary>
  float time_elapsed = 0.F;
  
  /// <summary>
  /// The sticky key time.
  /// </summary>
  const float sticky_key_time = 0.25F;
  
  /// <summary>
  /// Handle a TimeOut event.
  /// </summary>
  /// <param name="dt">The time that has passed.</param>
  void HandleTimeOut(float dt);

  /// <summary>
  /// Handle the control events.
  /// </summary>
  void HandleControlEvents();

  std::vector<state_machine::PlayerControlEvent> frameEvents = 
    std::vector<state_machine::PlayerControlEvent>();
};

}
}
