#include "stdafx.h"
#include "field/object/FieldObjectDefinition.h"

#define X FieldObjectType::Undefined
#define G FieldObjectType::Undefined
#define P FieldObjectType::Portal
#define B FieldObjectType::BigDot
#define _ FieldObjectType::SmallDot
#define s FieldObjectType::Undefined


namespace pacman {
namespace state {
namespace field {

std::vector<std::vector<FieldObjectType>> GetFieldObjectDefinition() {
  std::vector<std::vector<FieldObjectType>> result = {
    { X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, B, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, B, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, X },
    { X, X, _, X, X, X, _, X, _, X, X, X, X, X, _, X, _, X, X, X, _, X, X },
    { X, X, _, _, _, _, _, X, _, _, _, X, _, _, _, X, _, _, _, _, _, X, X },
    { X, X, X, X, X, X, _, X, X, X, s, X, s, X, X, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, s, s, s, s, s, s, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, X, X, G, X, X, s, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, X, s, s, s, X, s, X, _, X, X, X, X, X, X },
    { X, P, s, s, s, s, _, s, s, X, s, s, s, X, s, s, _, s, s, s, s, P, X },
    { X, X, X, X, X, X, _, X, s, X, X, X, X, X, s, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, s, s, s, s, s, s, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, X, X, X, X, X, s, X, _, X, X, X, X, X, X },
    { X, X, X, X, X, X, _, X, s, X, X, X, X, X, s, X, _, X, X, X, X, X, X },
    { X, X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X, X },
    { X, X, _, X, X, X, _, X, X, X, _, X, _, X, X, X, _, X, X, X, _, X, X },
    { X, X, B, _, _, X, _, _, _, _, _, s, _, _, _, _, _, X, _, _, B, X, X },
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

