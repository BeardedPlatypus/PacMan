#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <vector>

#include "field/IField.h"
#include "field/object/FieldObjectType.h"
#include "field/object/FieldObject.h"


namespace pacman {
namespace state {
namespace field {

class DllExport IFieldObjectManager {
public:
  static std::unique_ptr<IFieldObjectManager> Construct(const std::vector<std::vector<FieldObjectType>>& field_objects,
                                                        const IField* p_field);

  virtual ~IFieldObjectManager() = default;

  virtual FieldObjectType GetObjectType(FieldIndex index) const = 0;
  virtual FieldObjectType GetObjectType(int x, int y) const = 0;

  virtual void AddFieldObject(const FieldObject& field_object) = 0;

  virtual void RemoveFieldObject(FieldIndex index) = 0;
  virtual void RemoveFieldObject(int x, int y) = 0;
  
  virtual bool HasObjectAt(FieldIndex index) const = 0;
  virtual bool HasObjectAt(int x, int y) const = 0;

  virtual const std::vector<FieldObject>& GetAllFieldObjects() = 0;

};

}
}
}
