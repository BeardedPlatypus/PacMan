#include "pch.h"
#include "field/FieldLayerHelper.h"


namespace pacman {
namespace renderer {

FieldSpriteDescription FieldLayerHelper::FieldValueToSpriteType(unsigned int value) {
  if ((value & 2) == 2)
    return FieldSpriteDescription(FieldSpriteType::Gate, FieldSpriteOrientation(0.F));

  switch (value)
  {
  // End parts
  // |o|o|o|
  // |o|x|o|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 12) + (1 <<16)):
    return FieldSpriteDescription(FieldSpriteType::End, FieldSpriteOrientation(0.F));
  // |o|o|o|
  // |x|x|o|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 10) + (1 << 12) + (1 << 14) + (1 <<16)):
  // |x|x|-|
  // |x|x|-|
  // |o|o|-|
  case (1 + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 14) + (1 << 16) + (1 << 17)):
  // |o|o|-|
  // |x|x|-|
  // |x|x|-|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 16) + (1 << 17)):
    return FieldSpriteDescription(FieldSpriteType::End, FieldSpriteOrientation(90.F));
  // |o|x|o|
  // |o|x|o|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 12) + (1 << 14) + (1 <<16)):
    return FieldSpriteDescription(FieldSpriteType::End, FieldSpriteOrientation(180.F));
  // |o|o|o|
  // |o|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 12) + (1 << 14) + (1 <<16)):
  // |-|x|x|
  // |-|x|x|
  // |-|o|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 16)):
  // |-|o|o|
  // |-|x|x|
  // |-|x|x|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13)):
    return FieldSpriteDescription(FieldSpriteType::End, FieldSpriteOrientation(90.F));
  // Junction parts
  // |-|x|o|
  // |-|x|x|
  // |-|x|x|
  case (1 + (1 << 2) + (1 << 3) + (1 << 6) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13)):
  // |-|x|x|
  // |-|x|x|
  // |-|x|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13) + (1 << 16)):
  // |o|x|o|
  // |o|x|x|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 12) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Junction, FieldSpriteOrientation(0.F));
  // |-|-|-|
  // |x|x|x|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 12) + (1 << 16)):
  // |x|x|x|
  // |x|x|x|
  // |o|x|o|
  case (1 + (1 << 12) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Junction, FieldSpriteOrientation(90.F));
  // |o|x|-|
  // |x|x|-|
  // |x|x|-|
  case (1 + (1 << 2) + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 16) + (1 << 17)):
  // |x|x|-|
  // |x|x|-|
  // |o|x|-|
  case (1 + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 16) + (1 << 17)):
  // |o|x|o|
  // |x|x|o|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 10) + (1 << 12) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Junction, FieldSpriteOrientation(180.F));
  // |o|x|o|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 12) + (1 << 14) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Junction, FieldSpriteOrientation(270.F));
  // GateConnect
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 11) + (1 << 14) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::GateConnect, FieldSpriteOrientation(0.F));
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 9) + (1 << 12) + (1 << 14)):
    return FieldSpriteDescription(FieldSpriteType::GateConnect, FieldSpriteOrientation(0.F, true, false));
  // Corner
  // |-|-|-|
  // |-|x|x|
  // |-|x|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13) + (1 << 16)):
  // |o|o|o|
  // |o|x|x|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 12) + (1 << 16)):
  // |o|o|o|
  // |o|x|x|
  // |o|x|x|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 12)):
    return FieldSpriteDescription(FieldSpriteType::Corner, FieldSpriteOrientation(0.F));
  // |-|-|-|
  // |x|x|-|
  // |o|x|-|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 16) + (1 << 17)):
  // |o|o|o|
  // |x|x|o|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 10) + (1 << 12) + (1 << 16)):
  // |o|o|o|
  // |x|x|o|
  // |x|x|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 10) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Corner, FieldSpriteOrientation(90.F));
  // |o|x|-|
  // |x|x|-|
  // |-|-|-|
  case (1 + (1 << 2) + (1 << 6) + (1 << 7) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17)):
  // |o|x|o|
  // |x|x|o|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 10) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |x|x|o|
  // |x|x|o|
  // |o|o|o|
  case (1 + (1 << 6) + (1 << 10) + (1 << 12) + (1 << 14) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Corner, FieldSpriteOrientation(180.F));
  // |-|x|o|
  // |-|x|x|
  // |-|-|-|
  case (1 + (1 << 2) + (1 << 3) + (1 << 6) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17)):
  // |o|x|o|
  // |o|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |o|x|x|
  // |o|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 8) + (1 << 12) + (1 << 14) + (1 << 16)):
    return FieldSpriteDescription(FieldSpriteType::Corner, FieldSpriteOrientation(270.F));
  // Vertical Straight
  // |-|x|o|
  // |-|x|o|
  // |-|x|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 6) + (1 << 8) + (1 << 9) + (1 << 10) + (1 << 12) + (1 << 13) + (1 << 16)):
  // |-|x|x|
  // |-|x|o|
  // |-|x|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 8) + (1 << 9) + (1 << 10) + (1 << 12) + (1 << 13) + (1 << 16)):
  // |-|x|o|
  // |-|x|o|
  // |-|x|x|
  case (1 + (1 << 2) + (1 << 3) + (1 << 6) + (1 << 8) + (1 << 9) + (1 << 10) + (1 << 12) + (1 << 13)):
  // |o|x|-|
  // |o|x|-|
  // |o|x|-|
  case (1 + (1 << 2) + (1 << 6) + (1 << 7) + (1 << 8) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 16) + (1 << 17)):
  // |x|x|-|
  // |o|x|-|
  // |o|x|-|
  case (1 + (1 << 6) + (1 << 7) + (1 << 8) + (1 << 10) + (1 << 11) + (1 << 12) + (1 << 16) + (1 << 17)):
  // |o|x|-|
  // |o|x|-|
  // |x|x|-|
  case (1 + (1 << 2) + (1 << 6) + (1 << 7) + (1 << 8) + (1 << 10) + (1 << 11) + (1 << 16) + (1 << 17)):
  // |x|x|o|
  // |x|x|o|
  // |x|x|o|
  case (1 + (1 << 6) + (1 << 10) + (1 << 16)):
  // |o|x|x|
  // |o|x|x|
  // |o|x|x|
  case (1 + (1 << 2) + (1 << 8) + (1 << 12)):
  // |x|x|x|
  // |o|x|o|
  // |o|x|o|
  case (1 + (1 << 8) + (1 << 10) + (1 << 12) + (1 << 16)):
  // |x|x|o|
  // |o|x|o|
  // |o|x|o|
  case (1 + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 12) + (1 << 16)):
  // |o|x|x|
  // |o|x|o|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 8) + (1 << 10) + (1 << 12) + (1 << 16)):
  // |o|x|o|
  // |o|x|o|
  // |o|x|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 12) + (1 << 16)):
  // |o|x|o|
  // |o|x|o|
  // |x|x|x|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 10)):
  // |o|x|o|
  // |o|x|o|
  // |x|x|o|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 16)):
  // |o|x|o|
  // |o|x|o|
  // |o|x|x|
  case (1 + (1 << 2) + (1 << 6) + (1 << 8) + (1 << 10) + (1 << 12)):
    return FieldSpriteDescription(FieldSpriteType::Straight, FieldSpriteOrientation(0.F));
  // Horizontal Straight
  // |-|-|-|
  // |x|x|x|
  // |x|o|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 14) + (1 << 16)):
  // |-|-|-|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |-|-|-|
  // |x|x|x|
  // |o|o|x|
  case (1 + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) + (1 << 12) + (1 << 14)):
  // |x|o|o|
  // |x|x|x|
  // |-|-|-|
  case (1 + (1 << 4) + (1 << 6) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17)):
  // |o|o|o|
  // |x|x|x|
  // |-|-|-|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17)):
  // |o|o|x|
  // |x|x|x|
  // |-|-|-|
  case (1 + (1 << 2) + (1 << 4) + (1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17)):
  // |x|x|x|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 12) + (1 << 14) + (1 << 16)):
  // |x|x|x|
  // |x|x|x|
  // |x|o|o|
  case (1 + (1 << 14) + (1 << 16)):
  // |x|x|x|
  // |x|x|x|
  // |o|o|x|
  case (1 + (1 << 12) + (1 << 14)):
  // |o|o|o|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |o|o|x|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |x|o|o|
  // |x|x|x|
  // |o|o|o|
  case (1 + (1 << 4) + (1 << 6) + (1 << 12) + (1 << 14) + (1 << 16)):
  // |o|o|o|
  // |x|x|x|
  // |x|o|o|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 14) + (1 << 16)):
  // |o|o|o|
  // |x|x|x|
  // |o|o|x|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 12) + (1 << 14)):
  // |o|o|x|
  // |x|x|x|
  // |o|o|x|
  case (1 + (1 << 2) + (1 << 4) + (1 << 12) + (1 << 14)):
  // |x|o|o|
  // |x|x|x|
  // |x|o|o|
  case (1 + (1 << 4) + (1 << 6) + (1 << 14) + (1 << 16)):
  // |o|o|o|
  // |x|x|x|
  // |x|x|x|
  case (1 + (1 << 2) + (1 << 4) + (1 << 6)):
  // |x|o|o|
  // |x|x|x|
  // |x|x|x|
  case (1 + (1 << 4) + (1 << 6)):
  // |o|o|x|
  // |x|x|x|
  // |x|x|x|
  case (1 + (1 << 2) + (1 << 4)):
    return FieldSpriteDescription(FieldSpriteType::Straight, FieldSpriteOrientation(90.F));
  default:
    return FieldSpriteDescription(FieldSpriteType::Undefined, 
                                  FieldSpriteOrientation(0.F));
  }
}

}
}
