#include "stdafx.h"
#include "field/object/FieldObjectManager.h"
#include "field/object/FieldObjectType.h"


namespace pacman {
namespace state {
namespace field {

FieldObjectManager::FieldObjectManager(const std::vector<std::vector<FieldObjectType>>& field_objects) :
    _x_dim(field_objects[0].size()) {
  this->InitialiseObjectTypesFromDefinition(field_objects);
}


void FieldObjectManager::InitialiseObjectTypesFromDefinition(const std::vector<std::vector<FieldObjectType>>& field_objects) {
  for (int j = 0; j < field_objects.size(); ++j) {
    for (int i = 0; i < this->_x_dim; ++i) {
      FieldObjectType val = field_objects[j][i];
      
      if (!IsDefined(val)) continue;

      int key = this->CalculateKeyFromPosition(i, j);
      this->_field_object_types[key] = val;
    }
  }
}


void FieldObjectManager::AddFieldObject(const FieldObject& field_object) {
  // TODO: add an exception here?
  int key = this->CalculateKeyFromPosition(field_object.GetX(), 
                                           field_object.GetY());
  this->_field_object_types[key] = field_object.GetType();
  this->_cache_invalidated = true;
}


inline void FieldObjectManager::RemoveFieldObject(int x, int y) {
  this->_field_object_types.erase(CalculateKeyFromPosition(x, y));
  this->_cache_invalidated = true;
}


inline bool FieldObjectManager::HasObjectAt(int x, int y) const {
  return this->_field_object_types.find(this->CalculateKeyFromPosition(x, y)) != this->_field_object_types.end();
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
    this->_cached_field_objects.push_back(FieldObject(key_value_pair.first % this->_x_dim,
                                                      key_value_pair.first / this->_x_dim,
                                                      key_value_pair.second));
  }

  this->_cache_invalidated = false;
}

}
}
}