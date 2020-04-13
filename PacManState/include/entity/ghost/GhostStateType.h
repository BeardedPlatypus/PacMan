#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace state {

/// <Summary>
/// The different states that a Ghost can have.
/// <summary>
enum class DllExport GhostStateType {
  Eaten, 
  Edible,
  Alive,
};

}
}
