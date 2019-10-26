#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace update {
namespace state_machine {
  
/// <summary>
/// The <see cref="PlayerControlEvent"/> describes the 
/// events of the player control state machine.
/// </summary>
enum class DllExport PlayerControlEvent {
  PositiveKeyPress,
  PositiveKeyRelease,
  NegativeKeyPress,
  NegativeKeyRelease,
  TimeOut,
};

}
}
}
