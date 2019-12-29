#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// The types of system events.
/// </summary>
enum class DllExport SystemEventType {
  Quit,
};

}
}
}
