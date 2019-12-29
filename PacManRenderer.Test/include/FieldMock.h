#pragma once

#include "field/IField.h"
#include "gmock/gmock.h"


class FieldMock : public pacman::state::field::IField {
public:
  MOCK_METHOD(int, GetXDimension, (), (const));
  MOCK_METHOD(int, GetYDimension, (), (const));
  MOCK_METHOD(pacman::state::field::TileType, GetTileType, (int x, int y), (const));
};
