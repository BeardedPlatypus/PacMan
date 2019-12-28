#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace renderer {

/// <summary>
/// The <see cref="FieldSpriteType"/> decribes the 6 possible sprites with which
/// the playing field is rendererd.
/// </summary>
enum class DllExport FieldSpriteType {
  Straight,
  Corner,
  End,
  Junction,
  GateConnect,
  Gate,
  Undefined,
};

}
}
