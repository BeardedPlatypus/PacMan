#include "stdafx.h"
#include "field/object/FieldObjectManager.h"
#include "field/object/FieldObjectType.h"


namespace pacman {
namespace state {
namespace field {

FieldObjectManager::FieldObjectManager(const std::vector<std::vector<FieldObjectType>>& field_objects, 
                                       const IField* p_field) :
    _p_field(p_field) {
  this->InitialiseObjectTypesFromDefinition(field_objects);
}


void FieldObjectManager::InitialiseObjectTypesFromDefinition(const std::vector<std::vector<FieldObjectType>>& field_objects) {
  for (int j = 0; j < this->_p_field->GetYDimension(); ++j) {
    for (int i = 0; i < this->_p_field->GetXDimension(); ++i) {
      FieldObjectType val = field_objects[j][i];
      
      if (!IsDefined(val)) continue;

      FieldIndex key = this->_p_field->GetFieldIndex(i, j);
      this->_field_object_types[key] = val;
    }
  }
}


FieldObjectType FieldObjectManager::GetObjectType(FieldIndex index) const {
  return this->_field_object_types.at(index);
}


FieldObjectType FieldObjectManager::GetObjectType(int x, int y) const {
  return this->GetObjectType(this->_p_field->GetFieldIndex(x, y));
}


void FieldObjectManager::AddFieldObject(const FieldObject& field_object) {
  // TODO: add an exception here?
  int key = this->_p_field->GetFieldIndex(field_object.GetX(), 
                                          field_object.GetY());
  this->_field_object_types[key] = field_object.GetType();
  this->_cache_invalidated = true;
}


inline void FieldObjectManager::RemoveFieldObject(FieldIndex index) {
  this->_field_object_types.erase(index);
  this->_cache_invalidated = true;
}


inline void FieldObjectManager::RemoveFieldObject(int x, int y) {
  this->RemoveFieldObject(this->_p_field->GetFieldIndex(x, y));
}


inline bool FieldObjectManager::HasObjectAt(FieldIndex index) const {
  return this->_field_object_types.find(index) != this->_field_object_types.end();
}

inline bool FieldObjectManager::HasObjectAt(int x, int y) const {
  return this->HasObjectAt(this->_p_field->GetFieldIndex(x, y));
}


const std::vector<FieldObject>& FieldObjectManager::GetAllFieldObjects() {
  if (this->_cache_invalidated) {
    this->UpdateFieldObjectsCache();
  }

  return this->_cached_field_objects;
}


void FieldObjectManager::UpdateFieldObjectsCache() {
  this->_cached_field_objects.clear();

  for (auto key_value_pair : this->_field_object_types) {
    this->_cached_field_objects.push_back(FieldObject(this->_p_field->GetXFromFieldIndex(key_value_pair.first),
                                                      this->_p_field->GetYFromFieldIndex(key_value_pair.first),
                                                      key_value_pair.second));
  }

  this->_cache_invalidated = false;
}

}
}
}