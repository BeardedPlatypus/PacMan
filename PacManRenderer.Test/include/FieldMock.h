#pragma once

#include "field/IField.h"
#include "gmock/gmock.h"


class FieldMock : public pacman::state::field::IField {
public:
  MOCK_CONST_METHOD0(GetXDimension, int());
  MOCK_CONST_METHOD0(GetYDimension, int());
  MOCK_CONST_METHOD2(GetTileType, pacman::state::field::TileType(int x, int y));
};
