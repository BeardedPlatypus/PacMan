#pragma once

namespace pacman {
namespace update {
namespace state_machine {

/// <summary>
/// The <see cref="PlayerControlValue"/> describes the states
/// of the player control state machine.
/// </summary>
enum class PlayerControlValue {
  NoKeyPressed,
  NegativePressed,
  PositivePressed,
  NegativeSticky,
  PositiveSticky,
  NegativeThenPositivePressed,
  PositiveThenNegativePressed,
};

}
}
}


