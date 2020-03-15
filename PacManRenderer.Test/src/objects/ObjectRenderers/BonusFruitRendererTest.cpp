#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectRenderers/BonusFruitRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"
#include "LevelManagerMock.h"

using ::testing::Return;

namespace pacman {
namespace renderer {
namespace objects {

TEST(BonusFruitRendererTest, Initialise_RequestsCorrectSprites) {
  // Setup
  ViewAPIMock view_api;
  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_cherry,
                                      values::bonus_sprite_file,
                                      0, 0,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);


  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_strawberry,
                                      values::bonus_sprite_file,
                                      1 * values::bonus_tile_size,
                                      0 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_orange,
                                      values::bonus_sprite_file,
                                      2 * values::bonus_tile_size,
                                      0 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_apple,
                                      values::bonus_sprite_file,
                                      3 * values::bonus_tile_size,
                                      0 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_melon,
                                      values::bonus_sprite_file,
                                      0 * values::bonus_tile_size,
                                      1 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_galaxy_boss,
                                   values::bonus_sprite_file,
                                      1 * values::bonus_tile_size,
                                      1 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_bell,
                                      values::bonus_sprite_file,
                                      2 * values::bonus_tile_size,
                                      1 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_bonus_key,
                                      values::bonus_sprite_file,
                                      3 * values::bonus_tile_size,
                                      1 * values::bonus_tile_size,
                                      values::bonus_tile_size,
                                      values::bonus_tile_size)).Times(1);


  LevelManagerMock level_manager;

  auto renderer = BonusFruitRenderer(&view_api, &level_manager);

  // Call | Assert
  renderer.Initialise();
}

class BonusFruitRendererTestData {
public:
  BonusFruitRendererTestData(unsigned int level, const std::string& sprite_label) :
      level(level), expected_sprite_label(sprite_label){ }

  const unsigned int level;
  const std::string& expected_sprite_label;
};

class RenderObjectTest : public ::testing::TestWithParam<BonusFruitRendererTestData> {
public:
  static std::vector<BonusFruitRendererTestData> GetTestData() {
    return {
      BonusFruitRendererTestData(0, values::object_sprite_bonus_cherry),
      BonusFruitRendererTestData(1, values::object_sprite_bonus_strawberry),
      BonusFruitRendererTestData(2, values::object_sprite_bonus_orange),
      BonusFruitRendererTestData(3, values::object_sprite_bonus_apple),
      BonusFruitRendererTestData(4, values::object_sprite_bonus_apple),
      BonusFruitRendererTestData(5, values::object_sprite_bonus_melon),
      BonusFruitRendererTestData(6, values::object_sprite_bonus_melon),
      BonusFruitRendererTestData(7, values::object_sprite_bonus_galaxy_boss),
      BonusFruitRendererTestData(8, values::object_sprite_bonus_galaxy_boss),
      BonusFruitRendererTestData(9, values::object_sprite_bonus_bell),
      BonusFruitRendererTestData(10, values::object_sprite_bonus_bell),
      BonusFruitRendererTestData(11, values::object_sprite_bonus_key),
      BonusFruitRendererTestData(12, values::object_sprite_bonus_key),
      BonusFruitRendererTestData(13, values::object_sprite_bonus_key),
    };
  }
};


TEST_P(RenderObjectTest, RenderObject_RendersViewAPI) {
  // Setup
  const float expected_scale = 3.F;
  const int input_x = 8;
  const int input_y = 2;

  const float render_offset_y = 8.F;

  const float expected_x = (float)(input_x * values::tile_size - 3) * expected_scale;
  const float expected_y = (float)(input_y * values::tile_size - 3) * expected_scale + render_offset_y * expected_scale;

  ViewAPIMock view_api;

  EXPECT_CALL(view_api, 
              RenderSprite(GetParam().expected_sprite_label,
                            expected_x,
                            expected_y,
                            expected_scale * 0.75F, 
                            0.F, 
                            false, 
                            false)).Times(1);

  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetCurrentLevel()).WillByDefault(Return(GetParam().level));

  auto renderer = BonusFruitRenderer(&view_api, &level_manager);

  // Call | Assert
  renderer.RenderObject(input_x, input_y, expected_scale, render_offset_y);
}


INSTANTIATE_TEST_SUITE_P(BonusFruitRendererTest,
                         RenderObjectTest,
                         ::testing::ValuesIn(RenderObjectTest::GetTestData()));

}
}
}
