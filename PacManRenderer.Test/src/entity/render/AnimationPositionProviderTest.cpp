#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/AnimationPositionProvider.h>
#include <EntityAxisMock.h>

#include "CommonSpriteValues.h"

using ::testing::Return;
using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

struct DummyPosition {
public:
  state::IEntityAxis* GetXAxis() const { return p_x_axis; }
  state::IEntityAxis* GetYAxis() const { return p_y_axis; }

  state::IEntityAxis* p_x_axis;
  state::IEntityAxis* p_y_axis;
};


TEST(AnimationLabelPositionProviderTest, GetXPosition_ExpectedResults) {
  // Setup
  const float axis_position = 5.234F;

  EntityAxisMock axis;
  EXPECT_CALL(axis, GetPosition()).WillOnce(Return(axis_position));

  DummyPosition position = DummyPosition();
  position.p_x_axis = &axis;

  auto p_axii_container = std::make_unique<GetAxiiContainer>(position);

  AnimationPositionProvider pos_provider = AnimationPositionProvider(std::move(p_axii_container));

  const float scale = 4.F;

  // Call
  float result = pos_provider.GetXPosition(scale);

  // Assert
  const float expected_value = (axis_position - 0.25F) * (float)values::tile_size * scale;
  EXPECT_THAT(result, Eq(expected_value));
}


TEST(AnimationLabelPositionProviderTest, GetYPosition_ExpectedResults) {
  // Setup
  const float axis_position = 65.234F;

  EntityAxisMock axis;
  EXPECT_CALL(axis, GetPosition()).WillOnce(Return(axis_position));

  DummyPosition position = DummyPosition();
  position.p_y_axis = &axis;

  auto p_axii_container = std::make_unique<GetAxiiContainer>(position);

  AnimationPositionProvider pos_provider = AnimationPositionProvider(std::move(p_axii_container));

  const float scale = 3.F;
  const float render_offset = 10.5F;

  // Call
  float result = pos_provider.GetYPosition(scale, render_offset);

  // Assert
  const float expected_value = (axis_position - 0.25F) * (float)values::tile_size * scale + render_offset * scale;
  EXPECT_THAT(result, Eq(expected_value));
}



}
}
}
}
