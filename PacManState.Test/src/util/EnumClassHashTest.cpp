#include <gtest/gtest.h>
#include "util/EnumClassHash.h"

#include <utility>
#include <vector>

namespace pacman {

enum class DummyEnum {
  Zero,
  One,
  Two,
  Three,
  Four,
};


class HashOperatorTest : public ::testing::TestWithParam<std::pair<DummyEnum, size_t>> {
public:
  static std::vector<std::pair<DummyEnum, size_t>> GetTestData() {
    return {
      std::make_pair(DummyEnum::Zero,  0),
      std::make_pair(DummyEnum::One,   1),
      std::make_pair(DummyEnum::Two,   2),
      std::make_pair(DummyEnum::Three, 3),
      std::make_pair(DummyEnum::Four,  4),
    };
  }
};


TEST_P(HashOperatorTest, Execute_ExpectedResults) {
  EnumClassHash hash;

  // Call
  size_t result = hash(GetParam().first);

  EXPECT_EQ(result, GetParam().second);
}


INSTANTIATE_TEST_SUITE_P(EnumClassHashTest,
                         HashOperatorTest,
                         ::testing::ValuesIn(HashOperatorTest::GetTestData()));

}
