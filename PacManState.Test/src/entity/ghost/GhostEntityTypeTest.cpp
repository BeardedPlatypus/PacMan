#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/ghost/GhostEntityType.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion


namespace pacman {
namespace state {

class GhostTypeBasedTest : public ::testing::TestWithParam<std::pair<GhostEntityType, std::string>> {
public:
  static std::vector<std::pair<GhostEntityType, std::string>> GetTestData() {
    return {
      std::make_pair(GhostEntityType::Blinky, std::string("blinky")),
      std::make_pair(GhostEntityType::Pinky, std::string("pinky")),
      std::make_pair(GhostEntityType::Inky, std::string("inky")),
      std::make_pair(GhostEntityType::Clyde, std::string("clyde")),
      std::make_pair((GhostEntityType) 999, std::string("none")),
    };
  }
};


TEST_P(GhostTypeBasedTest, GetName_ExpectedResults) {
  EXPECT_THAT(GetGhostName(GetParam().first), Eq(GetParam().second));
}


INSTANTIATE_TEST_SUITE_P(GhostEntityTypeTest,
                         GhostTypeBasedTest,
                         ::testing::ValuesIn(GhostTypeBasedTest::GetTestData()));

}
}
