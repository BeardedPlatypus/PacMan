#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace update {
namespace state_machine {

enum class DllExport PlayerControlEvent {
  PositiveKey,
  NegativeKey,
  TimeOut,
};

}
}
}
