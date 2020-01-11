#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "field/object/IFieldObjectManager.h"

#include "FieldMock.h"

#define _ FieldObjectType::Undefined

using ::testing::Eq;
using ::testing::IsTrue;
using ::testing::IsFalse;

namespace pacman {
namespace state {
namespace field {

std::unique_ptr<IField> ConstructTestField() {
  std::vector<std::vector<TileType>> field_tiles = {
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
  };

  return IField::Construct(field_tiles);
}


std::unique_ptr<IFieldObjectManager> ConstructTestObjectManager(IField* p_field) {
  std::vector<std::vector<FieldObjectType>> field_objs = {
    { _, _, _, },
    { _, FieldObjectType::Portal, _},
    { _, _, _, },
  };

  return IFieldObjectManager::Construct(field_objs, p_field);
}


TEST(FieldObjectManagerTest, GetAllFieldObjects_ReturnsCorrectResults) {
  // Setup
  auto p_field = ConstructTestField();

  std::vector<std::vector<FieldObjectType>> field_objs = {
    { _, _, _, },
    { _, FieldObjectType::Portal, _},
    { _, _, _, },
  };

  // Call
  auto p_field_object_manager = IFieldObjectManager::Construct(field_objs, p_field.get());

  // Assert
  const std::vector<FieldObject> objs = p_field_object_manager->GetAllFieldObjects();
  ASSERT_THAT(objs.size(), Eq(1));

  const FieldObject& portal = objs[0];

  ASSERT_THAT(portal.GetX(), Eq(1));
  ASSERT_THAT(portal.GetY(), Eq(1));
  ASSERT_THAT(portal.GetType(), Eq(FieldObjectType::Portal));
}



TEST(FieldObjectManagerTest, AddFieldObject_AddsCorrectFieldObject) {
  // Setu
  auto p_field = ConstructTestField();
  auto p_field_object_manager = ConstructTestObjectManager(p_field.get());

  FieldObject field_object = FieldObject(0, 2, FieldObjectType::Portal);

  // Call
  p_field_object_manager->AddFieldObject(field_object);

  // Assert
  const std::vector<FieldObject> objs = p_field_object_manager->GetAllFieldObjects();
  ASSERT_THAT(objs.size(), Eq(2));

  const FieldObject& portal = objs[1];

  ASSERT_THAT(portal.GetX(), Eq(0));
  ASSERT_THAT(portal.GetY(), Eq(2));
  ASSERT_THAT(portal.GetType(), Eq(FieldObjectType::Portal));
}


TEST(FieldObjectManagerTest, RemoveFieldObject_RemovesCorrectFieldObject) {
  // Setup
  auto p_field = ConstructTestField();
  auto p_field_object_manager = ConstructTestObjectManager(p_field.get());

  // Call
  p_field_object_manager->RemoveFieldObject(1, 1);

  // Assert
  const std::vector<FieldObject> objs = p_field_object_manager->GetAllFieldObjects();
  ASSERT_THAT(objs.size(), Eq(0));
  ASSERT_THAT(p_field_object_manager->HasObjectAt(1, 1), IsFalse());
}


TEST(FieldObjectManagerTest, RemoveFieldObject_AlreadyEmpty_DoesNotModify) {
  // Setup
  auto p_field = ConstructTestField();
  auto p_field_object_manager = ConstructTestObjectManager(p_field.get());

  // Call
  p_field_object_manager->RemoveFieldObject(0, 0);

  // Assert
  const std::vector<FieldObject> objs = p_field_object_manager->GetAllFieldObjects();
  ASSERT_THAT(objs.size(), Eq(1));
  ASSERT_THAT(p_field_object_manager->HasObjectAt(1, 1), IsTrue());
}


TEST(FieldObjectManagerTest, HasObjectAt_ReturnsCorrectResult) {
  // Setup
  auto p_field = ConstructTestField();
  auto p_field_object_manager = ConstructTestObjectManager(p_field.get());

  // Call
  bool result = p_field_object_manager->HasObjectAt(1, 1);

  // Assert
  ASSERT_THAT(result, IsTrue());
}

}
}
}
