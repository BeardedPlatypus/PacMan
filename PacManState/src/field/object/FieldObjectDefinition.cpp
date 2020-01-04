#include "stdafx.h"
#include "field/object/FieldObjectDefinition.h"

#define X (FieldObjectType)-1
#define _ (FieldObjectType)-1
#define G (FieldObjectType)-1
#define P FieldObjectType::Portal


namespace pacman {
namespace state {
namespace field {

std::vector<std::vector<FieldObjectType>> GetFieldObjectDefinition() {
  std::vector<std::vector<FieldObjectType>> result = {
    { X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, X },
    { X, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, X },
    { X, X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X, X },
    { X, X, X, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, _, _, _, _, _, _, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, X, X, G, X, X, _, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, X, _, _, _, X, _, X, _, X, X, X, X, X, X },
    { X, P, _, _, _, _, _, _, _, X, _, _, _, X, _, _, _, _, _, _, _, P, X },
    { X, X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, _, _, _, _, _, _, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, X, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, _, _, _, X, _, _, _, _, _, _, _, _, _, _, _, X, _, _, _, X, X },
    { X, X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X, X },
    { X, X, X, X, _, X, _, X, _, X, X, X, X, X, _, X, _, X, _, X, X, X, X },
    { X, X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, X, X, X, X, _, X, _, X, X, X, X, X, X, X, _, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X },
  };

  return result;
}

}
}
}

