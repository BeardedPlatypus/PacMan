#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/WinRoundBehaviour.h>
#include "UpdatablePlayerEntityMock.h"
#include "LevelManagerMock.h"
#include "FieldObjectManagerMock.h"

using ::testing::Eq;
using ::testing::Return;
using ::testing::AllOf;
using ::testing::Property;
using ::testing::_;


namespace pacman {
namespace update {
namespace object {


TEST(WinRoundBehaviourTest, Execute_NoDotsLeft_ResetsField) {
  // Setup
  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetDotsLeftInCurrentLevel()).WillByDefault(Return(0));
  EXPECT_CALL(level_manager, IncrementCurrentLevel()).Times(1);

  FieldObjectManagerMock field_object_manager;
  EXPECT_CALL(field_object_manager, ResetFieldObjects()).Times(1);

  WinRoundBehaviour behaviour = WinRoundBehaviour(&level_manager,
                                                  &field_object_manager);

  UpdatablePlayerEntityMock entity;
  EXPECT_CALL(entity, Reset()).Times(1);

  // Call | Assert
  behaviour.Execute(&entity);
}


TEST(WinRoundBehaviourTest, Execute_DotsLeft_DoesNotResetField) {
  // Setup
  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetDotsLeftInCurrentLevel()).WillByDefault(Return(53));
  EXPECT_CALL(level_manager, IncrementCurrentLevel()).Times(0);

  FieldObjectManagerMock field_object_manager;
  EXPECT_CALL(field_object_manager, ResetFieldObjects()).Times(0);

  WinRoundBehaviour behaviour = WinRoundBehaviour(&level_manager,
                                                  &field_object_manager);

  UpdatablePlayerEntityMock entity;
  EXPECT_CALL(entity, Reset()).Times(0);

  // Call | Assert
  behaviour.Execute(&entity);
}

}
}
}
