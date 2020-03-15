#pragma once

namespace pacman {
namespace update {
namespace state_machine {
  
/// <summary>
/// The <see cref="PlayerControlEvent"/> describes the 
/// events of the player control state machine.
/// </summary>
enum class PlayerControlEvent {
  PositiveKeyPress,
  PositiveKeyRelease,
  NegativeKeyPress,
  NegativeKeyRelease,
  TimeOut,
  Reset,
};

}
}
}
