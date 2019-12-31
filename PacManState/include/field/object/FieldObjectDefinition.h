#pragma once
#define DllExport __declspec( dllexport )

#define X (FieldObjectType)-1
#define _ (FieldObjectType)-1
#define G (FieldObjectType)-1
#define P FieldObjectType::Portal

#include <vector>
#include "field/object/FieldObjectType.h" 

namespace pacman {
namespace state {
namespace field {

DllExport std::vector<std::vector<FieldObjectType>> GetFieldDefinition() {
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
}

}
}
}


#undef X
#undef _
#undef G
#undef P

