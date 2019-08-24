#include "pch.h"
#include "FieldLayerHelper.h"


namespace pacman {
namespace renderer {
  
std::vector<unsigned int> FieldLayerHelper::CalculateFieldVisualisation(const state::field::IField* const p_field) {
  auto x_dim = p_field->GetXDimension();
  auto y_dim = p_field->GetYDimension();

  std::vector<unsigned int> visualisation_field = std::vector<unsigned int>(x_dim * y_dim, 1);

  FieldLayerHelper::AddFieldValuesToVisualisation(visualisation_field, p_field);
  FieldLayerHelper::AddSideValuesToVisualisation(visualisation_field, x_dim, y_dim);
  FieldLayerHelper::AddCornerValuesToVisualisation(visualisation_field, x_dim, y_dim);

  return visualisation_field;
}


void FieldLayerHelper::AddFieldValuesToVisualisation(std::vector<unsigned int> & visualisation_field,
                                                     const state::field::IField* const p_field) {
  auto x_dim = p_field->GetXDimension();
  auto y_dim = p_field->GetYDimension();

  auto cursor = 0;

  std::vector<int> cursor_filter = { -1 * x_dim - 1
                                   , -1 * x_dim
                                   , -1 * x_dim + 1 
                                   , -1
                                   , +1
                                   , x_dim - 1
                                   , x_dim
                                   , x_dim + 1 
                                   };

  std::vector<unsigned int> space_values = std::vector<unsigned int>();
  std::vector<unsigned int> gate_values  = std::vector<unsigned int>();

  for (auto i = 8; i < 0; --i) {
    space_values.push_back(1 << (i * 2));
    gate_values.push_back(1 << ((i * 2) + 1));
  }

  std::vector<unsigned int>* active_values = nullptr;
  for (auto j = 0; j < y_dim; ++j) {
    for (auto i = 0; i < x_dim; ++i) {
      state::field::TileType tile_type = p_field->GetTileType(i, j);

      if (tile_type == state::field::TileType::Space) {
        visualisation_field[cursor] = 0;
        active_values = &space_values;
      }
      else if (tile_type == state::field::TileType::Gate) {
        visualisation_field[cursor] = 2;
        active_values = &gate_values;
      }

      for (auto k = 0; k < 8; ++k) {
        auto field = cursor + cursor_filter[k];

        if (field >= 0 && visualisation_field[field] > 0)
          visualisation_field[field] += active_values->at(k);
      }

      cursor += 1;
    }
  }
}


void FieldLayerHelper::AddCornerValuesToVisualisation(std::vector<unsigned int>& visualisation_field, int x_dim, int y_dim) {
  auto left_border = ((1 << 12) + (1 << 13) +
                      (1 <<  8) + (1 <<  9) +
                      (1 <<  2) + (1 <<  3));
  auto right_border = ((1 << 16) + (1 << 17) +
                       (1 << 10) + (1 << 11) +
                       (1 <<  6) + (1 <<  7));

  for (auto i = 1; i < y_dim - 1; ++i) {
    auto cursor = i * x_dim;
    if (visualisation_field[cursor] > 0)
      visualisation_field[cursor] += left_border;
    if (visualisation_field[cursor + x_dim - 1] > 0)
      visualisation_field[cursor + x_dim - 1] += right_border;
  }

  auto top_border = ((1 <<  6) + (1 <<  7) +
                     (1 <<  4) + (1 <<  5) +
                     (1 <<  2) + (1 <<  3));
  auto bottom_border = ((1 << 16) + (1 << 17) +
                        (1 << 14) + (1 << 15) +
                        (1 << 12) + (1 << 13));

  for (auto i = 1; i < x_dim - 1; ++i) {
    if (visualisation_field[i] > 0)
      visualisation_field[i] += top_border;
    if (visualisation_field[i + ((y_dim - 1) * x_dim)] > 0)
      visualisation_field[i + ((y_dim - 1) * x_dim)] += bottom_border;
  }
}


void FieldLayerHelper::AddSideValuesToVisualisation(std::vector<unsigned int>& visualisation_field, 
                                                    int x_dim, int y_dim) {
  if (visualisation_field[0] > 0)
    visualisation_field[0] += ((1 << 2) + (1 << 3));

  if (visualisation_field[x_dim - 1] > 0)
    visualisation_field[x_dim - 1] += ((1 << 6) + (1 << 7));

  auto bottom_left_corner = (y_dim - 1) * x_dim;
  if (visualisation_field[bottom_left_corner] > 0)
    visualisation_field[bottom_left_corner] += ((1 << 12) + (1 << 13));

  auto bottom_right_corner = (y_dim * x_dim) - 1;
  if (visualisation_field[bottom_right_corner] > 0)
    visualisation_field[bottom_right_corner] += ((1 << 16) + (1 << 17));
}






}
}