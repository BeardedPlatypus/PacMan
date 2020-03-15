#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/AddBonusFruitBehaviour.h>
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


class AddFruitTestSuccessfull : public ::testing::TestWithParam<unsigned int> {
public:
  static std::vector<unsigned int> GetTestData() { 
    return { 70, 170 };
  }
};


TEST_P(AddFruitTestSuccessfull, Execute_AddsFruit) {
  // Setup
  const int x_fruit_pos = 5;
  const int y_fruit_pos = 12;

  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetDotsConsumedInCurrentLevel())
    .WillByDefault(Return(GetParam()));

  FieldObjectManagerMock field_object_manager;
  ON_CALL(field_object_manager, GetObjectType(x_fruit_pos, y_fruit_pos))
    .WillByDefault(Return(state::field::FieldObjectType::Undefined));
  EXPECT_CALL(field_object_manager, 
              AddFieldObject(AllOf(Property(&state::field::FieldObject::GetType, 
                                            state::field::FieldObjectType::BonusFruit), 
                                   Property(&state::field::FieldObject::GetX, 
                                            x_fruit_pos),
                                   Property(&state::field::FieldObject::GetY, 
                                            y_fruit_pos)))).Times(1);

  AddBonusFruitBehaviour behaviour = AddBonusFruitBehaviour(&level_manager, 
                                                            &field_object_manager,
                                                            x_fruit_pos, y_fruit_pos);
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);
}


INSTANTIATE_TEST_SUITE_P(AddBonusFruitBehaviourTest,
                         AddFruitTestSuccessfull,
                         ::testing::ValuesIn(AddFruitTestSuccessfull::GetTestData()));


class AddBonusFruitBehaviourData {
public:
  AddBonusFruitBehaviourData(unsigned int dots_consumed, 
                             state::field::FieldObjectType field_object_type) :
      dots_consumed(dots_consumed),
      field_object_type(field_object_type) { }

  const unsigned int dots_consumed;
  const state::field::FieldObjectType field_object_type;
};


class AddFruitTestFalse: public ::testing::TestWithParam<AddBonusFruitBehaviourData> {
public:
  static std::vector<AddBonusFruitBehaviourData> GetTestData() { 
    return { 
      AddBonusFruitBehaviourData(10, state::field::FieldObjectType::Undefined),
      AddBonusFruitBehaviourData(70, state::field::FieldObjectType::BonusFruit),
      AddBonusFruitBehaviourData(170, state::field::FieldObjectType::BonusFruit),
    };
  }
};


TEST_P(AddFruitTestFalse, Execute_DoesNotAddFruit) {
  // Setup
  const int x_fruit_pos = 5;
  const int y_fruit_pos = 12;

  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetDotsConsumedInCurrentLevel())
    .WillByDefault(Return(GetParam().dots_consumed));

  FieldObjectManagerMock field_object_manager;
  ON_CALL(field_object_manager, GetObjectType(x_fruit_pos, y_fruit_pos))
    .WillByDefault(Return(GetParam().field_object_type));
  
  EXPECT_CALL(field_object_manager, AddFieldObject(_)).Times(0);

  AddBonusFruitBehaviour behaviour = AddBonusFruitBehaviour(&level_manager, 
                                                            &field_object_manager,
                                                            x_fruit_pos, y_fruit_pos);
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);
}

INSTANTIATE_TEST_SUITE_P(AddBonusFruitBehaviourTest,
                         AddFruitTestFalse,
                         ::testing::ValuesIn(AddFruitTestFalse::GetTestData()));

}
}
}
