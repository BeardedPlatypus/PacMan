#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/RemoveObjectBehaviour.h>

#include "FieldObjectManagerMock.h"
#include "UpdatablePlayerEntityMock.h"
#include "UpdatableEntityAxisMock.h"

using ::testing::Return;

namespace pacman {
namespace update {
namespace object {

TEST(RemoveObjectBehaviourTest, Execute_RemovesFieldObject) {
  // Setup
  const int expected_x = 3;
  const int expected_y = 5;

  UpdatableEntityAxisMock x_axis;
  ON_CALL(x_axis, GetCurrentIndex()).WillByDefault(Return(expected_x));

  UpdatableEntityAxisMock y_axis;
  ON_CALL(y_axis, GetCurrentIndex()).WillByDefault(Return(expected_y));

  UpdatablePlayerEntityMock entity;
  ON_CALL(entity, GetXAxis()).WillByDefault(Return(&x_axis));
  ON_CALL(entity, GetYAxis()).WillByDefault(Return(&y_axis));

  FieldObjectManagerMock object_manager;
  EXPECT_CALL(object_manager, RemoveFieldObject(expected_x, expected_y)).Times(1);

  auto behaviour = RemoveObjectBehaviour(&object_manager);

  // Call | Assert
  behaviour.Execute(&entity);
}

}
}
}
