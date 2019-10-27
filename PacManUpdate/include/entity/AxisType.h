#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace update {
  
/// <summary>
/// The two axii within PacMan.
/// </summary>
enum class DllExport AxisType {
  X,
  Y,
};

}
}
