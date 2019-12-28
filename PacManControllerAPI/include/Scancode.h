#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace controller {
namespace api {

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
