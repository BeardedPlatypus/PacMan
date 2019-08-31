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

  for (size_t i = 0; i < result.size(); ++i) {
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

  for (size_t i = 0; i < result.size(); ++i) {
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

  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_THAT(result[i], Eq(expected_result[i]));
  }
}


state::field::TileType GetTileType(unsigned int val, unsigned index) {
  if ((val & (1 << (2 * index))) == (1 << (2 * index)))
    return state::field::TileType::Space;
  if ((val & (1 << (2 * index + 1))) == (1 << (2 * index + 1)))
    return state::field::TileType::Gate;
  return state::field::TileType::Solid;
}


struct FieldLayerHelperCenterElementTestValues {
public:
  FieldLayerHelperCenterElementTestValues(state::field::TileType center_tile, unsigned int val) : expectedValue(val) {
    this->tiles =
    { { GetTileType(val, 1), GetTileType(val, 2),           GetTileType(val, 3) },
      { GetTileType(val, 4), center_tile,                   GetTileType(val, 5) },
      { GetTileType(val, 6), GetTileType(val, 7),           GetTileType(val, 8) }
    };

  }

  unsigned int expectedValue;

  std::vector<std::vector<state::field::TileType>> tiles;
};


class FieldLayerHelperCenterElementTest : public ::testing::TestWithParam<FieldLayerHelperCenterElementTestValues> {
public:
  static std::vector<FieldLayerHelperCenterElementTestValues> validInputs() {
    auto result = std::vector<FieldLayerHelperCenterElementTestValues>();
    for (auto i8 = 0; i8 < 3; ++i8) {
      auto val8 = i8 == 2 ? 0 : 1 << (16 + i8);
      for (auto i7 = 0; i7 < 3; ++i7) {
        auto val7 = i7 == 2 ? 0 : 1 << (14 + i7);
        for (auto i6 = 0; i6 < 3; ++i6) {
          auto val6 = i6 == 2 ? 0 : 1 << (12 + i6);
          for (auto i5 = 0; i5 < 3; ++i5) {
            auto val5 = i5 == 2 ? 0 : 1 << (10 + i5);
            for (auto i4 = 0; i4 < 3; ++i4) {
              auto val4 = i4 == 2 ? 0 : 1 << (8 + i4);
              for (auto i3 = 0; i3 < 3; ++i3) {
                auto val3 = i3 == 2 ? 0 : 1 << (6 + i3);
                for (auto i2 = 0; i2 < 3; ++i2) {
                  auto val2 = i2 == 2 ? 0 :  1 << (4 + i2);
                  for (auto i1 = 0; i1 < 3; ++i1) {
                    auto val1 = i1 == 2 ? 0 : 1 << (2 + i1);
                    result.push_back(FieldLayerHelperCenterElementTestValues(state::field::TileType::Solid, 1 + val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8));
                    result.push_back(FieldLayerHelperCenterElementTestValues(state::field::TileType::Gate, 2 + val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8));
                  }
                }
              }
            }
          }
        }
      }
    }

    return result;
  };
};


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
                         ::testing::ValuesIn(FieldLayerHelperCenterElementTest::validInputs()));
}
}
