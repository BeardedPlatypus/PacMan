#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {

struct DllExport EnumClassHash {
  template <typename T>
  size_t operator()(T t) const {
    return static_cast<size_t>(t);
  }
};

}
