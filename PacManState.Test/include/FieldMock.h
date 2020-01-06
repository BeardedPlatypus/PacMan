#pragma once

#include "field/IField.h"
#include "gmock/gmock.h"


class FieldMock : public pacman::state::field::IField {
public:
  MOCK_METHOD(int, GetXDimension, (), (const));
  MOCK_METHOD(int, GetYDimension, (), (const));

  MOCK_METHOD(pacman::state::field::TileType, GetTileType, (int, int), (const));
  
  MOCK_METHOD(pacman::state::field::FieldIndex, GetFieldIndex, (int, int), (const));
  
  MOCK_METHOD(int, GetXFromFieldIndex, (pacman::state::field::FieldIndex), (const));
  MOCK_METHOD(int, GetYFromFieldIndex, (pacman::state::field::FieldIndex), (const));
};
