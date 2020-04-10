#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace state {
  
/// <summary>
/// The <see cref="GhostEntityType"/> describes the possible ghost entities 
/// within a PacMan game.
/// </summary>
enum class DllExport GhostEntityType {
  Blinky,
  Pinky,
  Inky,
  Clyde,
};

}
}

