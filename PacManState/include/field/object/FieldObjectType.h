#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {
namespace field {

enum class DllExport FieldObjectType {
  Portal = 1,
};


bool IsDefined(FieldObjectType t);

}
}
}
