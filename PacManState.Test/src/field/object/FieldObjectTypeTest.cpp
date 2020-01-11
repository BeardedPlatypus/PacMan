#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "field/object/FieldObjectType.h"

using ::testing::Eq;


namespace pacman {
namespace state {
namespace field {

class IsDefinedData {
public:
  IsDefinedData(FieldObjectType t, bool expected_value) :
      input_type(t),
      expected_value(expected_value) { }

  const FieldObjectType input_type;
  const bool expected_value;
};


class PacManTypeIsDefinedTest : public ::testing::TestWithParam<IsDefinedData> {
public:
  static std::vector<IsDefinedData> GetTestValues() {
    return {
      IsDefinedData(FieldObjectType::Undefined, true),
      IsDefinedData(FieldObjectType::Portal, true),
      IsDefinedData(FieldObjectType::BigDot, true),
      IsDefinedData(FieldObjectType::SmallDot, true),
      IsDefinedData((FieldObjectType)-1, false),
    };
  }
};


TEST_P(PacManTypeIsDefinedTest, ExpectedResults) {
  // Call
  bool result = IsDefined(GetParam().input_type);

  // Assert
  ASSERT_THAT(result, Eq(GetParam().expected_value));
}


INSTANTIATE_TEST_SUITE_P(PacManTypeTest,
                         PacManTypeIsDefinedTest,
                         ::testing::ValuesIn(PacManTypeIsDefinedTest::GetTestValues()));


}
}
}
