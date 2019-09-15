#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {
namespace field {
  
/// <summary>
/// <see cref="TileType" /> describes the different kind of tiles 
/// which the field can contain.
/// </summary>
enum class DllExport TileType {
  Space,
  Solid,
  Gate,
  OutOfBounds,
};

}
}
}
