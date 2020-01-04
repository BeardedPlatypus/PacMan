#pragma once

#include "field/object/IFieldObjectManager.h"

#include <map>

namespace pacman {
namespace state {
namespace field {

class FieldObjectManager final : public IFieldObjectManager {
public:
  explicit FieldObjectManager(const std::vector<std::vector<FieldObjectType>>& field_objects,
                              const IField* p_field);

  FieldObjectType GetObjectType(FieldIndex index) const final;
  FieldObjectType GetObjectType(int x, int y) const final;

  void AddFieldObject(const FieldObject& field_object) final;

  void RemoveFieldObject(FieldIndex index) final;
  void RemoveFieldObject(int x, int y) final;

  bool HasObjectAt(FieldIndex index) const final;
  bool HasObjectAt(int x, int y) const final;

  const std::vector<FieldObject>& GetAllFieldObjects() final;
private:
  void InitialiseObjectTypesFromDefinition(const std::vector<std::vector<FieldObjectType>>& field_objects);

  std::map<FieldIndex, FieldObjectType> _field_object_types = 
    std::map<FieldIndex, FieldObjectType>();

  const IField* _p_field;

  void UpdateFieldObjectsCache();

  bool _cache_invalidated = true;
  std::vector<FieldObject> _cached_field_objects;
};

}
}
}
