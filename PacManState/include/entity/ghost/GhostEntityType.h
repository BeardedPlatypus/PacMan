#pragma once
#define DllExport __declspec( dllexport )

#include <string>

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


/// <summary>
/// Get the name as a string of the ghost defined with 
/// <paramref cref="ghost_type"/>.
/// </summary>
/// <param name="ghost_type">The type of ghost.</param>
/// <returns>
/// The name as a string of the ghost defined with <paramref cref="ghost_type"/>.
/// </returns>
std::string DllExport GetGhostName(GhostEntityType ghost_type);

}
}

