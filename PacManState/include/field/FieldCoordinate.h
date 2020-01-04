#pragma once
#define DllExport __declspec( dllexport )

#include <functional>

namespace pacman {
namespace state {
namespace field {

struct DllExport FieldCoordinate {
  int x;
  int y;

  constexpr bool operator==(const FieldCoordinate& rhs) const {
    return this->x == rhs.x && this->y == rhs.y;
  }
};

}
}
}

namespace std {

template<> struct DllExport hash<pacman::state::field::FieldCoordinate> {
  size_t operator()(pacman::state::field::FieldCoordinate const& field_coordinate) const noexcept {
    size_t hash_x = hash<int>{}(field_coordinate.x);
    size_t hash_y = hash<int>{}(field_coordinate.y);

    return hash_x ^ (hash_y << 1);
  }
};

}

