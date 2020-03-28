#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/update/ActiveInverseAnimationUpdateBehaviour.h"

#include "ViewAPIMock.h"
#include "ValueProviderMock.h"

using ::testing::Return;

namespace pacman {
namespace renderer {
namespace entity {
namespace update {

TEST(ActiveInverseAnimationUpdateBehaviourTest, Update_IsActive_CalledCorrectly) {
  // Setup
  const float dtime = 1.23F;
  const std::string expected_label = "label";

  std::shared_ptr<ValueProviderMock<std::string>> p_value_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  ON_CALL(*p_value_provider, GetValue()).WillByDefault(Return(expected_label));

  ViewAPIMock view_api;
  EXPECT_CALL(view_api, UpdateAnimation(expected_label, dtime)).Times(1);

  auto behaviour = ActiveInverseAnimationUpdateBehaviour(&view_api, expected_label, p_value_provider);

  // Call | Assert
  behaviour.Update(dtime);
}


TEST(ActiveInverseAnimationUpdateBehaviourTest, Update_IsNotActive_CalledCorrectly) {
  // Setup
  const float dtime = 1.23F;
  const std::string expected_label = "label";
  const std::string other_label = "other_label";

  std::shared_ptr<ValueProviderMock<std::string>> p_value_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  ON_CALL(*p_value_provider, GetValue()).WillByDefault(Return(other_label));

  ViewAPIMock view_api;
  EXPECT_CALL(view_api, UpdateAnimation(expected_label, -1.0 * dtime)).Times(1);

  auto behaviour = ActiveInverseAnimationUpdateBehaviour(&view_api, expected_label, p_value_provider);

  // Call | Assert
  behaviour.Update(dtime);
}

}
}
}
}
