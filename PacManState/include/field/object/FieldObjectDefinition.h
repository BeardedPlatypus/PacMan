#pragma once
#define DllExport __declspec( dllexport )

#include <vector>
#include "field/object/FieldObjectType.h" 

namespace pacman {
namespace state {
namespace field {

/// <summary>
/// Get the field objects defined on the field as a 2D vector, 
/// where each entry corresponds with either an object, or an 
/// undefined value.
/// </summary>
DllExport std::vector<std::vector<FieldObjectType>> GetFieldObjectDefinition();

}
}
}

