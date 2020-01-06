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

/// <summary>
/// <see cref="IFieldObjectManager"/> provides the interface to query whether
/// objects are defined at specific locations on the field, and if they are
/// which type they are. 
/// </summary>
class DllExport IFieldObjectManager {
public:  
  /// <summary>
  /// Constructs a new <see cref="IFieldOjbectManager"/> given the specified
  /// <paramref name="field_objects"/> and <see cref="IField"/>.
  /// </summary>
  /// <param name="field_objects"> The field objects. </param>
  /// <param name="p_field"> 
  /// The <see cref="IField"/> on which the objects are defined.
  /// </param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the newly constructed 
  /// <see cref="IFieldObjectManager"/>.
  /// </returns>
  static std::unique_ptr<IFieldObjectManager> Construct(const std::vector<std::vector<FieldObjectType>>& field_objects,
                                                        const IField* p_field);
  
  /// <summary>
  /// Finalizes this <see cref="IFieldObjectManager"/>.
  /// </summary>
  virtual ~IFieldObjectManager() = default;
  
  /// <summary>
  /// Gets the type of the object at the specified <paramref name="index"/>.
  /// </summary>
  /// <param name="index"> The <see cref="FieldIndex"/>. </param>
  /// <returns> 
  /// The type of object at the specified <paramref name="index"/>. 
  /// </returns>
  virtual FieldObjectType GetObjectType(FieldIndex index) const = 0;

  /// <summary>
  /// Gets the type of the object at the specified 
  /// (<paramref name="x"/>, <paramref name="y"/>) location.
  /// </summary>
  /// <param name="x"> The x location. </param>
  /// <param name="y"> The y location. </param>
  /// <returns> 
  /// The type of object at the specified 
  /// (<paramref name="x"/>, <paramref name="y"/>) location.
  /// </returns>
  virtual FieldObjectType GetObjectType(int x, int y) const = 0;
  
  /// <summary>
  /// Adds the <paramref name="field_object"/> to this 
  /// <see cref="IFieldObjectManager"/>.
  /// </summary>
  /// <param name="field_object"> The field object. </param>
  // <post-condition>
  /// | (new this)->GetOBjectType(field_object.x, field_object.y) == field_object.type;
  /// </post-condition>
  virtual void AddFieldObject(const FieldObject& field_object) = 0;
  
  /// <summary>
  /// Removes the field object at the specified <paramref name="index"/>.
  /// </summary>
  /// <param name="index">The index.</param>
  // <post-condition>
  /// | NOT (new this)->HasObjectAt(index)
  /// </post-condition>
  virtual void RemoveFieldObject(FieldIndex index) = 0;

  /// <summary>
  /// Removes the field object at the specified
  /// (<paramref name="x"/>, <paramref name="y"/>) location.
  /// </summary>
  /// <param name="x"> The x location. </param>
  /// <param name="y"> The y location. </param>
  // <post-condition>
  /// | NOT (new this)->HasObjectAt(x, y)
  /// </post-condition>
  virtual void RemoveFieldObject(int x, int y) = 0;
    
  /// <summary>
  /// Determines whether this <see cref="IFieldObjectManager"/> 
  /// [has a FieldObject at] [the specified index].
  /// </summary>
  /// <param name="index"> The index. </param>
  /// <returns>
  /// <c>true</c> if this <see cref="IFieldObjectManager"/> 
  /// [has a FieldObject at] [the specified index]; otherwise, <c>false</c>.
  /// </returns>
  virtual bool HasObjectAt(FieldIndex index) const = 0;
  
  /// <summary>
  /// Determines whether this <see cref="IFieldObjectManager"/> 
  /// [has a FieldObject at] [the specified (x, y) location].
  /// </summary>
  /// <param name="x"> The x location. </param>
  /// <param name="y"> The y location. </param>
  /// <returns>
  /// <c>true</c> if this <see cref="IFieldObjectManager"/> 
  /// [has a FieldObject at] [the specified (x, y) location]; 
  /// otherwise, <c>false</c>.
  /// </returns>
  virtual bool HasObjectAt(int x, int y) const = 0;
  
  /// <summary>
  /// Gets all the defined field objects within this 
  /// <see cref="IFieldObjectManager"/>.
  /// </summary>
  /// <returns>
  /// All field objects defined in this <see cref="IFieldObjectManager"/>
  /// </returns>
  virtual const std::vector<FieldObject>& GetAllFieldObjects() = 0;
};

}
}
}
