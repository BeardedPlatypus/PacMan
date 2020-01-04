#pragma once
#define DllExport __declspec( dllexport )

#include <vector>
#include "field/object/FieldObjectType.h" 

namespace pacman {
namespace state {
namespace field {

DllExport std::vector<std::vector<FieldObjectType>> GetFieldObjectDefinition();

}
}
}

