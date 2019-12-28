#pragma once
#define DllExport __declspec( dllexport )

#include <vector>

#include "field/IField.h"
#include "field/FieldSpriteDescription.h"


namespace pacman {
namespace renderer {

/// <summary>
/// The <see cref="FieldLayerHelper" /> exposes several methods used to 
/// construct a <see cref="FieldLayer" /> from a <see cref="state::field::IField" />.
/// </summary>
class DllExport FieldLayerHelper {
public:
  /// <summary> 
  /// Calculate a the field visualisation as a list of integers encoding the type of sprite to
  /// use.
  /// </summary>
  /// <param name="p_field"> 
  /// A constant pointer to the field from which the visualisation should be constructed. 
  /// </param>
  /// <returns>
  /// A <see cref="std::vector" /> describing the field and its adjacent tiles encoded as unsigned integers.
  /// </returns>
  static std::vector<unsigned int> CalculateFieldVisualisation(const state::field::IField* const p_field);
 
  /// <summary>
  /// Convert the specified <paramref name="value" /> to the corresponding 
  /// <see cref="FieldSpriteType" /> and its orientation in degrees.
  /// </summary>
  /// <param name="value" /> The value to be converted. </param>
  /// <returns>
  /// The <see cref="FieldSpriteType" /> and orientation in degrees corresponding with the value.
  /// </returns>
  static FieldSpriteDescription FieldValueToSpriteType(unsigned int value);

private:
  /// <summary>
  /// Add the tile values from <paramref cref="field" /> values to <paramref name="visualisation_field" />.
  /// </summary>
  /// <param name="visualisation_field"> The visualisation field. </param>
  /// <param name="field"> The observed field. </param>
  static void AddFieldValuesToVisualisation(std::vector<unsigned int>& visualisation_field,
                                            const state::field::IField* const field);

  /// <summary>
  /// Adds the out of bounds values to the sides of <paramref name="visualisation_field" />.
  /// </summary>
  /// <param name="visualisation_field">The visualisation field.</param>
  /// <param name="x_dim">The x dim.</param>
  /// <param name="y_dim">The y dim.</param>
  static void AddSideValuesToVisualisation(std::vector<unsigned int>& visualisation_field,
                                           int x_dim, int y_dim);

  /// <summary>
  /// Adds the out of bounds values to the corners of <paramref cref="visualisation_field" />.
  /// </summary>
  /// <param name="visualisation_field">The visualisation field.</param>
  /// <param name="x_dim">The x dim.</param>
  /// <param name="y_dim">The y dim.</param>
  static void AddCornerValuesToVisualisation(std::vector<unsigned int>& visualisation_field,
                                             int x_dim, int y_dim);
};

}
}
