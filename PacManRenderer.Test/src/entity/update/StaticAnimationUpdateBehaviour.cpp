#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/update/StaticAnimationUpdateBehaviour.h"

#include "ViewAPIMock.h"


namespace pacman {
namespace renderer {
namespace entity {
namespace update {

TEST(StaticAnimationUpdateBehaviour, Update_CalledCorrectly) {
  // Setup
  const float dtime = 1.23F;
  const std::string expected_label = "label";

  ViewAPIMock view_api;
  EXPECT_CALL(view_api, UpdateAnimation(expected_label, dtime)).Times(1);

  auto behaviour = StaticAnimationUpdateBehaviour(&view_api, expected_label);

  // Call | Assert
  behaviour.Update(dtime);
}

}
}
}
}
