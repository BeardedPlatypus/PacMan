#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// The scancodes currently defined within this controller component.
/// </summary>
enum class DllExport Scancode {
	W,
	A,
	S,
	D,
	Escape,
	ArrowUp,
	ArrowLeft,
	ArrowDown,
	ArrowRight,
  UnmappedCode,
};

}
}
}
