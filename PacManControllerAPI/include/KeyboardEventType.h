#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace controller {
namespace api {

enum class DllExport KeyboardEventType {
  KeyDown,
  KeyUp,
};

}
}
}


