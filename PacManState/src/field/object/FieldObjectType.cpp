#include "stdafx.h"
#include "field/object/FieldObjectType.h"


namespace pacman {
namespace state {
namespace field {

bool IsDefined(FieldObjectType t) {
  return t == FieldObjectType::Portal;
}


}
}
}