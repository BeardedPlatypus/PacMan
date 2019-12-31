#pragma once

#include "field/object/FieldObjectType.h"

namespace pacman {
namespace state {
namespace field {

class FieldObject final {
public:
  FieldObject(int x, int y, FieldObjectType type) : 
      _x(x), _y(y), _type(type) { }

  FieldObjectType GetType() const { return this->_type; }
  int GetX() const { return this->_x; }
  int GetY() const { return this->_y; }

private:
  int _x;
  int _y;
  FieldObjectType _type;
};

}
}
}
