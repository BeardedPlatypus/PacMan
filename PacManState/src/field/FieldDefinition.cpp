#include "stdafx.h"
#include "field/FieldDefinition.h"

#define X TileType::Solid
#define _ TileType::Space
#define G TileType::Gate
#define O TileType::OutOfBounds

namespace pacman {
namespace state {
namespace field {

std::vector<std::vector<TileType>> GetFieldDefinition() {
  std::vector<std::vector<TileType>> result = {
    { O, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, O }, 
    { O, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, O },
    { O, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, O },
    { O, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, O },
    { O, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, O },
    { O, X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X, O },
    { O, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, O },
    { O, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, O },
    { O, X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X, O },
    { O, X, X, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, X, X, O }, 
    { O, O, O, O, O, X, _, X, _, _, _, _, _, _, _, X, _, X, O, O, O, O, O }, 
    { O, O, O, O, O, X, _, X, _, X, X, G, X, X, _, X, _, X, O, O, O, O, O }, 
    { O, X, X, X, X, X, _, X, _, X, _, _, _, X, _, X, _, X, X, X, X, X, O }, 
    { X, _, _, _, _, _, _, _, _, X, _, _, _, X, _, _, _, _, _, _, _, _, X }, 
    { O, X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X, O }, 
    { O, O, O, O, O, X, _, X, _, _, _, _, _, _, _, X, _, X, O, O, O, O, O }, 
    { O, O, O, O, O, X, _, X, _, X, X, X, X, X, _, X, _, X, O, O, O, O, O }, 
    { O, X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X, O }, 
    { O, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, O },
    { O, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, O },
    { O, X, _, _, _, X, _, _, _, _, _, _, _, _, _, _, _, X, _, _, _, X, O },
    { O, X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X, O }, 
    { O, X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X, O }, 
    { O, X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X, O }, 
    { O, X, _, X, X, X, X, X, X, X, _, X, _, X, X, X, X, X, X, X, _, X, O }, 
    { O, X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X, O },
    { O, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, O },
  };

  return result;
}

}
}
}