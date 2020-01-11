#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "field/object/IFieldObjectManager.h"

using ::testing::Eq;

namespace pacman {
namespace state {
namespace field {

TEST(FieldObjectTest, Constructor_SetsCorrectValues) {
  // Setup
  const int expected_x = 5;
  const int expected_y = 8;
  const FieldObjectType expected_type = FieldObjectType::Portal;

  // Call
  auto field_object = FieldObject(expected_x,
                                  expected_y,
                                  expected_type);

  // Assert
  ASSERT_THAT(field_object.GetX(), Eq(expected_x));
  ASSERT_THAT(field_object.GetY(), Eq(expected_y));
  ASSERT_THAT(field_object.GetType(), Eq(expected_type));
}

}
}
}
