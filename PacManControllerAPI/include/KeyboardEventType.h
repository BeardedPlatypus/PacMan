#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// The types of keyboard events.
/// </summary>
enum class DllExport KeyboardEventType {
  KeyDown,
  KeyUp,
};

}
}
}


