#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "FieldLayerHelper.h"

#include "field/IField.h"


using ::testing::Eq;
using ::testing::Return;

namespace pacman {
namespace renderer {

TEST(FieldLayerHelperTest, CalculateFieldValue_SingleSpace) {
  // Given
  std::vector<std::vector<state::field::TileType>> tiles = { {state::field::TileType::Space } };
  std::vector<unsigned int> expected_result = { 0 };
  std::unique_ptr<state::field::IField> p_field = state::field::IField::Construct(tiles);

  // When
  std::vector<unsigned int> result = 
    FieldLayerHelper::CalculateFieldVisualisation(p_field.get());

  // Then
  ASSERT_THAT(result.size(), Eq(expected_result.size()));

  for (auto i = 0; i < result.size(); ++i) {
    ASSERT_THAT(result[i], Eq(expected_result[i]));
  }
}


TEST(FieldLayerHelperTest, CalculateFieldValue_SingleSolid) {
  // Given
  std::vector<std::vector<state::field::TileType>> tiles = { {state::field::TileType::Solid } };
  std::unique_ptr<state::field::IField> p_field = state::field::IField::Construct(tiles);

  unsigned int result_value = 1;

  for (int i = 2; i < 18; i++) {
    result_value += 1 << i;
  }

  std::vector<unsigned int> expected_result = { result_value };

  // When
  std::vector<unsigned int> result = 
    FieldLayerHelper::CalculateFieldVisualisation(p_field.get());

  // Then
  ASSERT_THAT(result.size(), Eq(expected_result.size()));

  for (auto i = 0; i < result.size(); ++i) {
    ASSERT_THAT(result[i], Eq(expected_result[i]));
  }
}


TEST(FieldLayerHelperTest, CalculateFieldValue_SingleGate) {
  // Given
  std::vector<std::vector<state::field::TileType>> tiles = { {state::field::TileType::Gate } };
  std::unique_ptr<state::field::IField> p_field = state::field::IField::Construct(tiles);

  unsigned int result_value = 2;

  for (int i = 2; i < 18; i++) {
    result_value += 1 << i;
  }

  std::vector<unsigned int> expected_result = { result_value };

  // When
  std::vector<unsigned int> result = 
    FieldLayerHelper::CalculateFieldVisualisation(p_field.get());

  // Then
  ASSERT_THAT(result.size(), Eq(expected_result.size()));

  for (auto i = 0; i < result.size(); ++i) {
    ASSERT_THAT(result[i], Eq(expected_result[i]));
  }
}


state::field::TileType GetTileType(unsigned int val, unsigned index) {
  if (val & (1 << (2 * index)))
    return state::field::TileType::Space;
  if (val & (1 << (2 * index + 1)))
    return state::field::TileType::Gate;
  return state::field::TileType::Solid;
}


struct FieldLayerHelperCenterElementTestValues {
public:
  FieldLayerHelperCenterElementTestValues(unsigned int val) : expectedValue(val) {
    this->tiles =
    { { GetTileType(val, 1), GetTileType(val, 2),           GetTileType(val, 3) },
      { GetTileType(val, 4), state::field::TileType::Solid, GetTileType(val, 5) },
      { GetTileType(val, 6), GetTileType(val, 7),           GetTileType(val, 8) }
    };

  }

  unsigned int expectedValue;

  std::vector<std::vector<state::field::TileType>> tiles;
};


class FieldLayerHelperCenterElementTest : public ::testing::TestWithParam<FieldLayerHelperCenterElementTestValues> {};


TEST_P(FieldLayerHelperCenterElementTest, ReturnsCorrectValue) {
  unsigned int expected_value = this->GetParam().expectedValue;
  std::unique_ptr<state::field::IField> p_field = state::field::IField::Construct(this->GetParam().tiles);

  std::vector<unsigned int> result = 
    FieldLayerHelper::CalculateFieldVisualisation(p_field.get());

  // Then
  ASSERT_THAT(result[4], Eq(expected_value));
}


INSTANTIATE_TEST_SUITE_P(FieldLayerHelperValuesTest,
                         FieldLayerHelperCenterElementTest,
                         ::testing::Values(
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6 + 1)) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6    )) + (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) +                  (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                                   (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                                   (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                                    (1 << (8 + 1)) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6 + 1)) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6    )) + (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) +                  (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                                   (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                                   (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                                    (1 << (8    )) + (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6 + 1)) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) + (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                  (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                  (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                   (1 << (6    )) +                  (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4 + 1)) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4 + 1)) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4 + 1)) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) + (1 << (4    )) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) + (1 << (4    )) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                  (1 << (4    )) +                                   (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2 + 1)) +                                                    (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 + (1 << (2    )) +                                                    (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1))),
  FieldLayerHelperCenterElementTestValues(1 +                                                                     (1 << (10 + 1)) + (1 << (12 + 1)) + (1 << (14 + 1)) + (1 << (16 + 1)))
                         ));

}
}
