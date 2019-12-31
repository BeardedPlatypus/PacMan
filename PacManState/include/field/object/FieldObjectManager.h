#pragma once

#include "field/object/IFieldObjectManager.h"

#include <map>

namespace pacman {
namespace state {
namespace field {

class FieldObjectManager final : public IFieldObjectManager {
public:
  FieldObjectManager(const std::vector<std::vector<FieldObjectType>>& field_objects);

  void AddFieldObject(const FieldObject& field_object) final;
  void RemoveFieldObject(int x, int y) final;
  bool HasObjectAt(int x, int y) const final;

  const std::vector<FieldObject>& GetAllFieldObjects() final;
private:
  void InitialiseObjectTypesFromDefinition(const std::vector<std::vector<FieldObjectType>>& field_objects);
  inline int CalculateKeyFromPosition(int x, int y) const { return y * this->_x_dim + x; }

  std::map<int, FieldObjectType> _field_object_types = std::map<int, FieldObjectType>();

  const int _x_dim;

  void UpdateFieldObjectsCache();

  bool _cache_invalidated = true;
  std::vector<FieldObject> _cached_field_objects;
};

}
}
}
