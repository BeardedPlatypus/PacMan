#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {
  
/// <summary>
/// Possible directions entities can be moving.
/// </summary>
enum class DllExport Direction {
  Up,
  Down,
  Left,
  Right,
};

}
}
