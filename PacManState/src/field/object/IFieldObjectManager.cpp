#include "stdafx.h"
#include "field/object/IFieldObjectManager.h"
#include "field/object/FieldObjectManager.h"


namespace pacman {
namespace state {
namespace field {

std::unique_ptr<IFieldObjectManager> IFieldObjectManager::Construct(const std::vector<std::vector<FieldObjectType>>& field_objects) {
  return std::make_unique<FieldObjectManager>(field_objects);
}

}
}
}