#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <vector>

#include "TileType.h"


namespace pacman {
namespace state {
namespace field {
  
/// <summary>
/// The <see cref="IField" /> describes the field of this PacMan game.
/// </summary>
class DllExport IField {
public:    
  /// <summary>
  /// Construct a new <see cref="IField" /> with the provided 
  /// <paramref name="tiles" />.
  /// </summary>
  /// <param name="tiles"> The tiles of the new <see cref="IField" />. </param>
  /// <returns> A pointer to the newly created <see cref="IField" />. </returns>
  static std::unique_ptr<IField> Construct(const std::vector<std::vector<TileType>>& tiles);

  virtual ~IField() {}

  /// <summary>
  /// Gets the x dimension of this <see cref="IField" />.
  /// </summary>
  /// <returns> The x dimension of this <see cref="IField" />. </returns>
  virtual int GetXDimension() const = 0;

  /// <summary>
  /// Gets the y dimension of this <see cref="IField" />.
  /// </summary>
  /// <returns> The y dimension of this <see cref="IField" />. </returns>
  virtual int GetYDimension() const = 0;
  
  /// <summary>
  /// Get the type of the tile at the specified 
  /// (<paramref name="x" />, <paramref name="y" />) location.
  /// </summary>
  /// <param name="x"> The x location. </param>
  /// <param name="y"> The y location .</param>
  /// <returns>
  /// The type of the tile at the specified 
  /// (<paramref name="x" />, <paramref name="y" />) location.
  /// </returns>
  /// <remarks>
  /// If a value outside of the dimensions of this <see cref="IField" /> is
  /// queried <see cref="TileType::Solid" /> will be returned. 
  /// </remarks>
  virtual TileType GetTileType(int x, int y) const = 0;
};

}
}
}
