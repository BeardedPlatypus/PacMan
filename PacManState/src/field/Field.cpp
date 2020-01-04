#include "stdafx.h"
#include "field/Field.h"


namespace pacman {
namespace state {
namespace field {

Field::Field(const std::vector<std::vector<TileType>>& tiles) :
  x_dimension(tiles[0].size()),
  y_dimension(tiles.size()),
  tiles(std::vector<std::vector<TileType>>(tiles))
{
}


TileType Field::GetTileType(int x, int y) const {
  return this->tiles[y][x];
}


inline FieldIndex Field::GetFieldIndex(int x, int y) const {
  return y * this->GetXDimension() + x;
}


inline int Field::GetXFromFieldIndex(FieldIndex index) const {
  return index % this->GetXDimension();
}


inline int Field::GetYFromFieldIndex(FieldIndex index) const {
  return index / this->GetXDimension();
}

}
}
}