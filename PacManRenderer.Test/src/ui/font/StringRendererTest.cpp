#include <gtest/gtest.h>

#include "ui/font/StringRenderer.h"
#include "GlyphRendererMock.h"
#include "ui/UISpriteValues.h"
#include "ui/font/StaticStringRenderData.h"

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


class StringRenderTestData {
public:
  StringRenderTestData(const ui::StaticStringRenderData& string_data,
                       float scale,
                       float x_offset,
                       const std::vector<GlyphRenderElement>& glyphs) noexcept :
      string_data(string_data),
      scale(scale),
      x_offset(x_offset),
      glyphs(glyphs) { }

  const ui::StaticStringRenderData string_data;
  const float scale;
  const float x_offset;
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

inline std::vector<StringRenderTestData> GetStringRenderTestData() {
  return {
    // Justification::FlushLeft
    StringRenderTestData(ui::StaticStringRenderData("test", 2.F, 5.2F, 0.75F, ui::Justification::FlushLeft), 
                         3.1F, 
                         0.F, 
                         GetGlyphs("test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("test test", 2.F, 5.2F, 0.75F, ui::Justification::FlushLeft), 
                         3.1F, 
                         0.F, 
                         GetGlyphs("test test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 6.4F, 0.75F, ui::Justification::FlushLeft), 
                         1.3F, 
                         0.F, 
                         GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 1.3F * 0.75)),
    StringRenderTestData(ui::StaticStringRenderData("a     b", 2.F, 5.2F, 0.75F, ui::Justification::FlushLeft), 
                         3.1F,
                         0.F, 
                         GetGlyphs("a     b", 2.F, 3.1F * 0.75F)),
    // Justification::Centre
    StringRenderTestData(ui::StaticStringRenderData("test", 2.F, 5.2F, 0.75F, ui::Justification::Centre), 
                         3.1F, 
                         values::glyph_size * 4.F * 0.75F * 3.1F / 2.F, 
                         GetGlyphs("test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("test test", 2.F, 5.2F, 0.75F, ui::Justification::Centre), 
                         3.1F, 
                         values::glyph_size * 9.F * 0.75F * 3.1F / 2.F, 
                         GetGlyphs("test test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 6.4F, 0.75F, ui::Justification::Centre), 
                         1.3F, 
                         values::glyph_size * 36.F * 0.75F * 1.3F / 2.F, 
                         GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 1.3F * 0.75)),
    StringRenderTestData(ui::StaticStringRenderData("a     b", 2.F, 5.2F, 0.75F, ui::Justification::Centre), 
                         4.F, 
                         values::glyph_size * 7.F * 0.75F * 4.F / 2.F, 
                         GetGlyphs("a     b", 2.F, 4.F * 0.75F)),
    // Justification::FlushRight
    StringRenderTestData(ui::StaticStringRenderData("test", 2.F, 5.2F, 0.75F, ui::Justification::FlushRight), 
                         3.1F, 
                         values::glyph_size * 4.F * 0.75F * 3.1F, 
                         GetGlyphs("test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("test test", 2.F, 5.2F, 0.75F, ui::Justification::FlushRight), 
                         3.1F, 
                         values::glyph_size * 9.F * 0.75F * 3.1F, 
                         GetGlyphs("test test", 2.F, 3.1F * 0.75F)),
    StringRenderTestData(ui::StaticStringRenderData("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 6.4F, 0.75F, ui::Justification::FlushRight), 
                         1.3F, 
                         values::glyph_size * 36.F * 0.75F * 1.3F, 
                         GetGlyphs("abcdefghijklmnopqrstuvwxyz0123456789", 3.2F, 1.3F * 0.75)),
    StringRenderTestData(ui::StaticStringRenderData("a     b", 2.F, 5.2F, 0.75F, ui::Justification::FlushRight), 
                         4.F, 
                         values::glyph_size * 7.F * 0.75F * 4.F, 
                         GetGlyphs("a     b", 2.F, 4.F * 0.75F)),
  };
}


class RenderStringTest : public ::testing::TestWithParam<StringRenderTestData> {};


TEST_P(RenderStringTest, ExpectedResults) {
  // Setup
  auto p_glyph_renderer_mock = std::make_unique<GlyphRendererMock>();

  for (GlyphRenderElement elem : GetParam().glyphs) {
    EXPECT_CALL(*p_glyph_renderer_mock, RenderGlyph(elem.glyph,
                                                    elem.x - GetParam().x_offset,
                                                    GetParam().string_data.GetY(),
                                                    GetParam().scale * GetParam().string_data.GetFontScale()))
      .Times(1);
  }

  auto string_renderer = ui::StringRenderer(std::move(p_glyph_renderer_mock));

  // Call
  string_renderer.RenderString(GetParam().string_data,
                               GetParam().scale);
}

INSTANTIATE_TEST_SUITE_P(StringRendererTest,
                         RenderStringTest,
                         ::testing::ValuesIn(GetStringRenderTestData()));

}
}