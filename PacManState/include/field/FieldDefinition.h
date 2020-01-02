#pragma once
#define DllExport __declspec( dllexport )

#include <vector>
#include "field/TileType.h" 

namespace pacman {
namespace state {
namespace field {

DllExport std::vector<std::vector<TileType>> GetFieldDefinition();

}
}
}

