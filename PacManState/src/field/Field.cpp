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

}
}
}