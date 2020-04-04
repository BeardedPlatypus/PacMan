#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace state {

/// <summary>
/// The different states that PacMan can have.
/// </summary>
enum class DllExport PacManStateType {
  Moving,
  Dying,
};

}
}
