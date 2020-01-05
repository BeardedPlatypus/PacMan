#pragma once
#define DllExport __declspec( dllexport )

#include "field/object/FieldObjectType.h"


namespace pacman {
namespace state {
namespace field {

/// <summary>
/// <see cref="FieldObject"/> defines a single field object as having a 
/// <see cref="FieldObjectType"/> and a location consisting of an x and y
/// integer index.
/// </summary>
class DllExport FieldObject final {
public:  
  /// <summary>
  /// Creates a new <see cref="FieldObject"/>.
  /// </summary>
  /// <param name="x"> The x location. </param>
  /// <param name="y"> The y location. </param>
  /// <param name="type"> The type. </param>
  FieldObject(int x, int y, FieldObjectType type) :
      _x(x), _y(y), _type(type) { }
  
  /// <summary>
  /// Gets the type of this <see cref="FieldObject"/>.
  /// </summary>
  /// <returns> The type. </returns>
  inline FieldObjectType GetType() const { return this->_type; }
  
  /// <summary>
  /// Gets the x location of this <see cref="FieldObject"/>.
  /// </summary>
  /// <returns> The x location. </returns>
  inline int GetX() const { return this->_x; }
  
  /// <summary>
  /// Gets the y location of this <see cref="FieldObject"/>.
  /// </summary>
  /// <returns> The y location. </returns>
  inline int GetY() const { return this->_y; }

private:
  int _x;
  int _y;
  FieldObjectType _type;
};

}
}
}
