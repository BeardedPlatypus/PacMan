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

}
}
