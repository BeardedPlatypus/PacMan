#include "pch.h"
#include "field/FieldLayerHelper.h"


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

  std::vector<unsigned int> space_values = std::vector<unsigned int>();
  std::vector<unsigned int> gate_values = std::vector<unsigned int>();
  std::vector<unsigned int> out_of_bounds_values  = std::vector<unsigned int>();

  for (auto i = 1; i < 5; ++i) {
    space_values.push_back(1 << (i * 2));
    gate_values.push_back(1 << ((i * 2) + 1));
    out_of_bounds_values.push_back((1 << (i * 2)) + (1 << ((i * 2) + 1)));
  }

  space_values.push_back(-1);
  gate_values.push_back(-1);
  out_of_bounds_values.push_back(-1);

  for (auto i = 5; i < 9; ++i) {
    space_values.push_back(1 << (i * 2));
    gate_values.push_back(1 << ((i * 2) + 1));
    out_of_bounds_values.push_back((1 << (i * 2)) + (1 << ((i * 2) + 1)));
  }

  std::vector<unsigned int>* active_values = nullptr;
  for (auto j = 0; j < y_dim; ++j) {
    for (auto i = 0; i < x_dim; ++i) {
      state::field::TileType tile_type = p_field->GetTileType(i, j);

      switch (tile_type)
      {
      case pacman::state::field::TileType::Space:
        visualisation_field[i + j * x_dim] = 0;
        active_values = &space_values;
        break;
      case pacman::state::field::TileType::Solid:
        continue;
      case pacman::state::field::TileType::Gate:
        visualisation_field[i + j * x_dim] += 1;
        active_values = &gate_values;
        break;
      case pacman::state::field::TileType::OutOfBounds:
        visualisation_field[i + j * x_dim] = 0;
        active_values = &out_of_bounds_values;
        break;
      default:
        continue;
      }

      for (auto kj = 0; kj < 3; kj++) {
        auto rel_j = j - kj + 1;
        if (rel_j < 0 || rel_j >= y_dim) continue;

        for (auto ki = 0; ki < 3; ki++) {
          if (ki == 1 && kj == 1) continue;
          
          auto rel_i = i - ki + 1;
          if (rel_i < 0 || rel_i >= x_dim) continue;

          auto field = rel_j * x_dim + rel_i;

          if (visualisation_field[field] > 0)
            visualisation_field[field] += active_values->at(ki + kj * 3);
        }
      }
    }
  }
}


void FieldLayerHelper::AddSideValuesToVisualisation(std::vector<unsigned int>& visualisation_field, int x_dim, int y_dim) {
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


void FieldLayerHelper::AddCornerValuesToVisualisation(std::vector<unsigned int>& visualisation_field, 
                                                    int x_dim, int y_dim) {
  auto top_left_corner = 0;
  if (visualisation_field[top_left_corner] > 0)
    visualisation_field[top_left_corner] += ((1 <<  2) + (1 <<  3) +
                                             (1 <<  8) + (1 <<  9) +
                                             (1 <<  4) + (1 <<  5) + 
                                             (1 <<  6) + (1 <<  7) +
                                             (1 << 12) + (1 << 13));

  auto top_right_corner = x_dim - 1;
  if (visualisation_field[x_dim - 1] > 0)
    visualisation_field[x_dim - 1] += ((1 <<  6) + (1 <<  7) +
                                       (1 <<  4) + (1 <<  5) +
                                       (1 <<  2) + (1 <<  3) +
                                       (1 << 10) + (1 << 11) + 
                                       (1 << 16) + (1 << 17));

  auto bottom_left_corner = (y_dim - 1) * x_dim;
  if (visualisation_field[bottom_left_corner] > 0)
    visualisation_field[bottom_left_corner] += ((1 << 12) + (1 << 13) + 
                                                (1 <<  8) + (1 <<  9) +
                                                (1 <<  2) + (1 <<  3) +
                                                (1 << 14) + (1 << 15) +
                                                (1 << 16) + (1 << 17));

  auto bottom_right_corner = (y_dim * x_dim) - 1;
  if (visualisation_field[bottom_right_corner] > 0)
    visualisation_field[bottom_right_corner] += ((1 << 16) + (1 << 17) +
                                                 (1 << 14) + (1 << 15) +
                                                 (1 << 10) + (1 << 11) +
                                                 (1 << 12) + (1 << 13) +
                                                 (1 <<  6) + (1 <<  7));
  
  // Correction for playing fields with only one dimension:
  // Since this should be a rare occurrence, we fix our values
  // if it happens, rather than fix it as it happens.
  // Top-left corner is equal to Top-right corner and
  // Bottom-left corner is equal to Bottom-right corner
  if (x_dim == 1) {
    if (visualisation_field[top_left_corner] > 0)
      visualisation_field[top_left_corner] -= ((1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7));
    if (visualisation_field[bottom_left_corner] > 0)
      visualisation_field[bottom_left_corner] -= ((1 << 12) + (1 << 13) + (1 << 14) + (1 << 15) + (1 << 16) + (1 << 17));
  }

  // Top-left corner is equal to Bottom-left corner and
  // Top-right corner is equal to Bottom-right corner
  if (y_dim == 1) {
    if (visualisation_field[top_left_corner] > 0)
      visualisation_field[top_left_corner] -= ((1 << 2) + (1 << 3) + (1 << 8) + (1 << 9) + (1 << 12) + (1 << 13));
    if (visualisation_field[top_right_corner] > 0)
      visualisation_field[top_right_corner] -= ((1 << 10) + (1 << 11) + (1 << 6) + (1 << 7) + (1 << 16) + (1 << 17));
  }
}

}
}