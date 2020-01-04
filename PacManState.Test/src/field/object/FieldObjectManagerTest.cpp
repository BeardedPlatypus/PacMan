#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "field/object/IFieldObjectManager.h"

#define _ (FieldObjectType)-1

using ::testing::Eq;
using ::testing::IsTrue;
using ::testing::IsFalse;

namespace pacman {
namespace state {
namespace field {

TEST(FieldObjectManagerTest, GetAllFieldObjects_ReturnsCorrectResults) {
  // Setup
  std::vector<std::vector<TileType>> field_tiles = {
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
  };

  auto p_field = IField::Construct(field_tiles);

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
  // Setup
  std::vector<std::vector<TileType>> field_tiles = {
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
  };

  auto p_field = IField::Construct(field_tiles);

  std::vector<std::vector<FieldObjectType>> field_objs = {
    { _, _, _, },
    { _, FieldObjectType::Portal, _},
    { _, _, _, },
  };
  auto p_field_object_manager = IFieldObjectManager::Construct(field_objs, p_field.get());

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
  // Setup
  std::vector<std::vector<TileType>> field_tiles = {
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
  };

  auto p_field = IField::Construct(field_tiles);

  std::vector<std::vector<FieldObjectType>> field_objs = {
    { _, _, _, },
    { _, FieldObjectType::Portal, _},
    { _, _, _, },
  };
  auto p_field_object_manager = IFieldObjectManager::Construct(field_objs, p_field.get());

  // Call
  p_field_object_manager->RemoveFieldObject(1, 1);

  // Assert
  const std::vector<FieldObject> objs = p_field_object_manager->GetAllFieldObjects();
  ASSERT_THAT(objs.size(), Eq(0));
  ASSERT_THAT(p_field_object_manager->HasObjectAt(1, 1), IsFalse());
}


TEST(FieldObjectManagerTest, HasObjectAt_ReturnsCorrectResult) {
  // Setup
  // Setup
  std::vector<std::vector<TileType>> field_tiles = {
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
    { TileType::Space, TileType::Space, TileType::Space, },
  };

  auto p_field = IField::Construct(field_tiles);

  std::vector<std::vector<FieldObjectType>> field_objs = {
    { _, _, _, },
    { _, FieldObjectType::Portal, _},
    { _, _, _, },
  };

  auto p_field_object_manager = IFieldObjectManager::Construct(field_objs, p_field.get());

  // Call
  bool result = p_field_object_manager->HasObjectAt(1, 1);

  // Assert
  ASSERT_THAT(result, IsTrue());
}

}
}
}
