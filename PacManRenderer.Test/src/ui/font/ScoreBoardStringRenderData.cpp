#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ui/font/ScoreBoardStringRenderData.h"
#include "score/IScoreBoard.h"


using ::testing::Eq;


namespace pacman {
namespace renderer {
namespace ui {

TEST(ScoreBoardRenderDataTest, Constructor_ExpectedValues) {
  // Setup
  std::unique_ptr<state::score::IScoreBoard> p_score_board =
    state::score::IScoreBoard::Construct();

  std::string expected_string = "0";
  float expected_x = 5.4321F;
  float expected_y = 1.2345F;
  float expected_font_scale = 10.333F;
  Justification expected_justification = Justification::Centre;

  // Call
  auto string_data = ScoreBoardStringRenderData(p_score_board.get(),
                                                expected_x,
                                                expected_y,
                                                expected_font_scale,
                                                expected_justification);

  // Assert
  ASSERT_THAT(string_data.GetString(), Eq(expected_string));
  ASSERT_THAT(string_data.GetX(), Eq(expected_x));
  ASSERT_THAT(string_data.GetY(), Eq(expected_y));
  ASSERT_THAT(string_data.GetFontScale(), Eq(expected_font_scale));
  ASSERT_THAT(string_data.GetJustification(), Eq(expected_justification));
}

TEST(ScoreBoardRenderDataTest, ChangingScoreBoard_ChangesString) {
  // Setup
  std::unique_ptr<state::score::IScoreBoard> p_score_board =
    state::score::IScoreBoard::Construct();

  float expected_x = 5.4321F;
  float expected_y = 1.2345F;
  float expected_font_scale = 10.333F;
  Justification expected_justification = Justification::Centre;

  // Call
  auto string_data = ScoreBoardStringRenderData(p_score_board.get(),
                                                expected_x,
                                                expected_y,
                                                expected_font_scale,
                                                expected_justification);
  ASSERT_THAT(string_data.GetString(), Eq("0"));

  p_score_board->IncrementScore(525);

  ASSERT_THAT(string_data.GetString(), Eq("525"));
}

}
}
}
