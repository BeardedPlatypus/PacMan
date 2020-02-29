#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ui/font/GlyphRenderer.h"
#include "ViewAPIMock.h"
#include "ui/UISpriteValues.h"

using ::testing::Eq;


namespace pacman {
namespace renderer {

class GlyphData {
public:
  GlyphData(char glyph, int x, int y) : glyph(glyph), x(x), y(y) { }

  const char glyph;
  const int x;
  const int y;
};

inline std::vector<GlyphData> GetGlyphData() {
  return {
    GlyphData('0', 0, 0),
    GlyphData('1', 1, 0),
    GlyphData('2', 2, 0),
    GlyphData('3', 3, 0),
    GlyphData('4', 4, 0),
    GlyphData('5', 5, 0),
    GlyphData('6', 6, 0),
    GlyphData('7', 7, 0),
    GlyphData('8', 0, 1),
    GlyphData('9', 1, 1),
    GlyphData('-', 2, 1),
    GlyphData('/', 3, 1),
    GlyphData('a', 4, 1),
    GlyphData('b', 5, 1),
    GlyphData('c', 6, 1),
    GlyphData('d', 7, 1),
    GlyphData('e', 0, 2),
    GlyphData('f', 1, 2),
    GlyphData('g', 2, 2),
    GlyphData('h', 3, 2),
    GlyphData('i', 4, 2),
    GlyphData('j', 5, 2),
    GlyphData('k', 6, 2),
    GlyphData('l', 7, 2),
    GlyphData('m', 0, 3),
    GlyphData('n', 1, 3),
    GlyphData('o', 2, 3),
    GlyphData('p', 3, 3),
    GlyphData('q', 4, 3),
    GlyphData('r', 5, 3),
    GlyphData('s', 6, 3),
    GlyphData('t', 7, 3),
    GlyphData('u', 0, 4),
    GlyphData('v', 1, 4),
    GlyphData('w', 2, 4),
    GlyphData('x', 3, 4),
    GlyphData('y', 4, 4),
    GlyphData('z', 5, 4),
    GlyphData('.', 6, 4),
    GlyphData('>', 7, 4),
  };
}

TEST(GlyphRendererTest, Initialise_ExpectedResults) {
  // Setup
  ViewAPIMock view_api;

  for (const GlyphData& data : GetGlyphData()) {
    std::string glyph_s = "glyph_";
    glyph_s.append(1, data.glyph);
    EXPECT_CALL(view_api, RequestSprite(glyph_s,
                                        values::font_file,
                                        data.x * values::glyph_size,
                                        data.y * values::glyph_size,
                                        values::glyph_size,
                                        values::glyph_size)).Times(1);
  }

  auto glyph_renderer = ui::GlyphRenderer(&view_api);

  // Call
  glyph_renderer.Initialise();
}

class RenderSpriteTest : public ::testing::TestWithParam<GlyphData> {};

TEST_P(RenderSpriteTest, ExpectedResults) {
  // Setup
  const float expected_x = 1.F;
  const float expected_y = 2.F;
  const float expected_scale = 3.F;

  ViewAPIMock view_api;
  std::string glyph_s = "glyph_";
  glyph_s.append(1, GetParam().glyph);
  EXPECT_CALL(view_api, RenderSprite(glyph_s,
                                     expected_x, 
                                     expected_y, 
                                     expected_scale, 
                                     false, false, 0.F)).Times(1);
  
  auto glyph_renderer = ui::GlyphRenderer(&view_api);
  glyph_renderer.Initialise();

  // Call
  glyph_renderer.RenderGlyph(GetParam().glyph, expected_x, expected_y, expected_scale);
}


INSTANTIATE_TEST_SUITE_P(GlyphRendererTest,
                         RenderSpriteTest,
                         ::testing::ValuesIn(GetGlyphData()));

}
}
