#include <gtest/gtest.h>

#include "ui/font/StringRenderer.h"
#include "GlyphRendererMock.h"
#include "ui/UISpriteValues.h"

#include <vector>

namespace pacman {
namespace renderer {

TEST(StringRendererTest, Initialise_CallsInitialiseGLyphRenderer) {
  // Setup
  auto p_glyph_renderer_mock = std::make_unique<GlyphRendererMock>();
  EXPECT_CALL(*p_glyph_renderer_mock, Initialise()).Times(1);

  auto string_renderer = ui::StringRenderer(std::move(p_glyph_renderer_mock));

  // Call | Assert
  string_renderer.Initialise();
}


class GlyphRenderElement {
public:
  GlyphRenderElement(char glyph, float x) noexcept : glyph(glyph), x(x) { }

  const char glyph;
  const float x;
};


class StringRenderData {
public:
  StringRenderData(const std::string& input_string,
                   float scale,
                   float x_pos,
                   float y_pos,
                   float x_offset,
                   ui::Justification justification,
                   const std::vector<GlyphRenderElement>& glyphs) noexcept :
      input_string(input_string),
      scale(scale),
      x_pos(x_pos),
      y_pos(y_pos),
      x_offset(x_offset),
      justification(justification),
      glyphs(glyphs) { }

  const std::string input_string;
  const float scale;
  const float x_pos;
  const float y_pos;
  const float x_offset;
  const ui::Justification justification;
  const std::vector<GlyphRenderElement> glyphs;
};


std::vector<GlyphRenderElement> GetGlyphs(const std::string& string, 
                                          float offset,
                                          float scale) {
  auto result = std::vector<GlyphRenderElement>();
  for (size_t i = 0; i < string.length(); i++) {
    char c = string.at(i);

    if (c == ' ') continue;

    result.emplace_back(c, offset + i * values::glyph_size * scale);
  }

  return result;
}


inline std::vector<StringRenderData> GetStringRenderData() {
  return {
    // Justification::FlushLeft
    StringRenderData("test", 2.F, 5.2F, 3.1F, 
                     0.F, ui::Justification::FlushLeft, 
                     GetGlyphs("test", 5.2F, 2.F)),
    StringRenderData("test test", 2.F, 5.2F, 3.1F, 
                     0.F, ui::Justification::FlushLeft, 
                     GetGlyphs("test test", 5.2F, 2.F)),
    StringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 
                     3.2F, 6.4F, 1.3F, 0.F, ui::Justification::FlushLeft, 
                     GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 6.4F, 3.2F)),
    StringRenderData("a     b", 2.F, 5.2F, 3.1F, 
                     0.F, ui::Justification::FlushLeft, 
                     GetGlyphs("a     b", 5.2F, 2.F)),
    // Justification::Centre
    StringRenderData("test", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 4.F / 2.F, ui::Justification::Centre, 
                     GetGlyphs("test", 5.2F, 2.F)),
    StringRenderData("test test", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 9.F / 2.F, ui::Justification::Centre, 
                     GetGlyphs("test test", 5.2F, 2.F)),
    StringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 
                     3.2F, 6.4F, 1.3F, 
                     values::glyph_size * 3.2F * 36.F / 2.F, ui::Justification::Centre, 
                     GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 6.4F, 3.2F)),
    StringRenderData("a     b", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 7.F / 2.F, ui::Justification::Centre, 
                     GetGlyphs("a     b", 5.2F, 2.F)),
    // Justification::FlushRight
    StringRenderData("test", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 4.F, ui::Justification::FlushRight, 
                     GetGlyphs("test", 5.2F, 2.F)),
    StringRenderData("test test", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 9.F, ui::Justification::FlushRight, 
                     GetGlyphs("test test", 5.2F, 2.F)),
    StringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 
                     3.2F, 6.4F, 1.3F, 
                     values::glyph_size * 3.2F * 36.F, ui::Justification::FlushRight, 
                     GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 6.4F, 3.2F)),
    StringRenderData("a     b", 2.F, 5.2F, 3.1F, 
                     values::glyph_size * 2.F * 7.F, ui::Justification::FlushRight, 
                     GetGlyphs("a     b", 5.2F, 2.F)),
  };
}


class RenderStringTest : public ::testing::TestWithParam<StringRenderData> {};


TEST_P(RenderStringTest, ExpectedResults) {
  // Setup
  auto p_glyph_renderer_mock = std::make_unique<GlyphRendererMock>();

  for (GlyphRenderElement elem : GetParam().glyphs) {
    EXPECT_CALL(*p_glyph_renderer_mock, RenderGlyph(elem.glyph,
                                                    elem.x - GetParam().x_offset,
                                                    GetParam().y_pos,
                                                    GetParam().scale))
      .Times(1);
  }

  auto string_renderer = ui::StringRenderer(std::move(p_glyph_renderer_mock));

  // Call
  string_renderer.RenderString(GetParam().input_string,
                               GetParam().x_pos, 
                               GetParam().y_pos, 
                               GetParam().scale,
                               GetParam().justification);
}

INSTANTIATE_TEST_SUITE_P(StringRendererTest,
                         RenderStringTest,
                         ::testing::ValuesIn(GetStringRenderData()));

}
}