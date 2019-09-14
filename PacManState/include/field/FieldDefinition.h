#pragma once
#define DllExport __declspec( dllexport )

#define X TileType::Solid
#define _ TileType::Space
#define G TileType::Gate

#include <vector>
#include "field/TileType.h" 

namespace pacman {
namespace state {
namespace field {

DllExport std::vector<std::vector<TileType>> GetFieldDefinition() {
  std::vector<std::vector<TileType>> result = {
    { X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X }, 
    { X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X },
    { X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X },
    { X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X },
    { X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X },
    { X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X },
    { X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X },
    { X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X },
    { X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X },
    { X, X, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, _, _, _, _, _, _, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, X, X, G, X, X, _, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, X, _, _, _, X, _, X, _, X, X, X, X, X }, 
    { _, _, _, _, _, _, _, _, X, _, _, _, X, _, _, _, _, _, _, _, _ }, 
    { X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, _, _, _, _, _, _, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X }, 
    { X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X }, 
    { X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X },
    { X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X },
    { X, _, _, _, X, _, _, _, _, _, _, _, _, _, _, _, X, _, _, _, X },
    { X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X }, 
    { X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X }, 
    { X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X }, 
    { X, _, X, X, X, X, X, X, X, _, X, _, X, X, X, X, X, X, X, _, X }, 
    { X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X },
    { X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X },
  };

  return result;
}


}
}
}
