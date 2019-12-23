#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "field/IField.h"

#include <random>


#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace state {
namespace field {

struct FieldTestValues {
  FieldTestValues(int x_dim, int y_dim) :
      tiles(std::vector<std::vector<TileType>>()) {
    TileType types[] = { TileType::Gate,
                         TileType::Solid,
                         TileType::Space };

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 2);
    auto type_selector = std::bind(distribution, generator);

    for (size_t j = 0; j < y_dim; j++)
    {
      std::vector<TileType> x_row = std::vector<TileType>();

      for (size_t i = 0; i < x_dim; i++)
      {
        x_row.push_back(types[type_selector()]);
      }

      this->tiles.push_back(x_row);
    }
  }

  std::vector<std::vector<TileType>> tiles;
};


class FieldTest : public ::testing::TestWithParam<FieldTestValues> {};


TEST_P(FieldTest, GetXDimension_ReturnsExpectedValue) {
  // Given
  std::vector<std::vector<TileType>> tiles = GetParam().tiles;

  std::unique_ptr<IField> p_field = IField::Construct(tiles);

  // When
  int result = p_field->GetXDimension();

  // Then
  ASSERT_THAT(result, Eq(tiles[0].size()));
}


TEST_P(FieldTest, GetYDimension_ReturnsExpectedValue) {
  // Given
  std::vector<std::vector<TileType>> tiles = GetParam().tiles;

  std::unique_ptr<IField> p_field = IField::Construct(tiles);

  // When
  int result = p_field->GetYDimension();

  // Then
  ASSERT_THAT(result, Eq(tiles.size()));
}


TEST_P(FieldTest, GetTileType_ReturnsExpectedValue) {
  // Given
  std::vector<std::vector<TileType>> tiles = GetParam().tiles;

  std::unique_ptr<IField> p_field = IField::Construct(tiles);

  for (size_t y = 0; y < p_field->GetYDimension(); y++) {
    for (size_t x = 0; x < p_field->GetXDimension(); x++) {
      EXPECT_THAT(p_field->GetTileType(x, y), Eq(tiles[y][x]));
    }
  }
}


INSTANTIATE_TEST_SUITE_P(FieldTestValuesTest,
                         FieldTest, 
                         ::testing::Values(FieldTestValues(1, 1),
                                           FieldTestValues(1, 3),
                                           FieldTestValues(3, 1),
                                           FieldTestValues(3, 3),
                                           FieldTestValues(10, 10)));


}
}
}
