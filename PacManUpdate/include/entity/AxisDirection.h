#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace update {
  
/// <summary>
/// The three possible directions on a <see cref="IPlayerMovementAxis"/>.
/// </summary>
enum class DllExport AxisDirection {
  None,
  Positive,
  Negative,
};

}
}
