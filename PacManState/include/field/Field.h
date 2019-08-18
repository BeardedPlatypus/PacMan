#pragma once

#include "IField.h"

namespace pacman {
namespace state {
namespace field {
  
/// <summary>
/// <see cref="Field" /> provides a concrete implementation of 
/// <see cref="IField" />.
/// </summary>
/// <seealso cref="IField" />
class Field final : public IField {
public:  
  /// <summary>
  /// Construct a new <see cref="Field"/> with the given <paramref name="tiles" />.
  /// </summary>
  /// <param name="tiles"> The tiles of this new <see cref="Field" />. </param>
  Field(const std::vector<std::vector<TileType>>& tiles);

  inline int GetXDimension() const final { return this->x_dimension; }
  inline int GetYDimension() const final { return this->y_dimension; }

  TileType GetTileType(int x, int y) const final;
  
private:  
  /// <summary>
  /// The x dimension of this <see cref="Field" />
  /// </summary>
  const int x_dimension;

  /// <summary>
  /// The y dimension of this <see cref="Field" />
  /// </summary>
  const int y_dimension;
  
  /// <summary>
  /// A two dimensional array of <see cref="TileType" /> describing this
  /// <see cref="Field" />.
  /// </summary>
  const std::vector<std::vector<TileType>> tiles;
};

}
}
}
