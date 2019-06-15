#include "TextureMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sprite/SpriteAnimation.h"


#pragma region using_statements
using ::testing::Matcher;
using ::testing::FloatEq;
using ::testing::Eq;
using ::testing::Ref;
using ::testing::Not;
#pragma endregion

namespace pacman {
namespace view {
// - Constructor:
// Given a set of sprites
//   and a time per frame
// When a SpriteAnimation is constructed with these
// Then the correct frames per second is returned
//  and the correct number of frames is returned
//  and the correct current time is returned
TEST(Unit_SpriteAnimationTest, ctor) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;

  // When
  auto animation = SpriteAnimation(time_per_frame, sprites);

  // Then
  const int expected_n_frames = sprites.size();
  EXPECT_THAT(animation.getNFrames(), Eq(expected_n_frames));

  const float expected_fps = 1.F / time_per_frame;
  EXPECT_THAT(animation.getFramesPerSecond(), FloatEq(expected_fps));

  const float expected_cur_time = 0.F;
  EXPECT_THAT(animation.getInternalTime(), FloatEq(expected_cur_time));
}


// - setInternalTime
// Given a SpriteAnimation
//   and a new time value smaller than the number of frames
// When setInternalTime is called
// Then getInternalTime returns this new value
TEST(Unit_SpriteAnimationTest, setInternalTime_SmallerThanRange) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);

  ASSERT_THAT(animation.getInternalTime(), FloatEq(0.F));

  const float new_time = 2.3F;

  // When
  animation.setInternalTime(new_time);

  // Then
  EXPECT_THAT(animation.getInternalTime(), FloatEq(new_time));
}


// Given a SpriteAnimation
//   and a new time value greater than the number of frames
// When setInternalTime is called
// Then getInternalTime modulus the number of frames is returned
TEST(Unit_SpriteAnimationTest, setInternalTime_GreaterThanRange) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);

  ASSERT_THAT(animation.getInternalTime(), FloatEq(0.0));

  const float new_time = 2.5F;
  const float new_time_large = time_per_frame * 10 + new_time;

  // When
  animation.setInternalTime(new_time_large);

  // Then
  EXPECT_THAT(animation.getInternalTime(), FloatEq(new_time));
}


// - setExactTime
// Given a SpriteAnimation
//   and a new time value smaller than the number of frames
// When setExcatTime is called
// Then getExactTime returns this new value
TEST(Unit_SpriteAnimationTest, setExactTime) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);

  ASSERT_THAT(animation.getExactTime(), FloatEq(0.0));

  const float new_time = 12.3F;

  // When
  animation.setExactTime(new_time);

  // Then
  EXPECT_THAT(animation.getExactTime(), FloatEq(new_time));
}

// - updateTime:
// Given a SpriteAnimation
//   and a dTime
// When updateTime is called
// Then the new time is equal to the old time plus dTime
TEST(Unit_SpriteAnimationTest, updateTime) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);

  const float start_time = 15.F;
  animation.setExactTime(start_time);
  ASSERT_THAT(animation.getExactTime(), FloatEq(start_time));

  const float update_time = 5.F;

  // When
  animation.updateTime(update_time);

  // Then
  EXPECT_THAT(animation.getExactTime(), FloatEq(start_time + update_time));
}


// - resetTime:
// Given a SpriteAnimation
// When resetTime is called
// Then getExactTime returns 0
TEST(Unit_SpriteAnimationTest, resetTime) {
  // Given
  TextureMock texture;
  auto sprite = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite,
	                                                          sprite };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);

  const float start_time = 15.F;
  animation.setExactTime(start_time);
  ASSERT_THAT(animation.getExactTime(), FloatEq(start_time));

  // When
  animation.resetTime();

  // Then
  EXPECT_THAT(animation.getExactTime(), FloatEq(0.F));
}

// - getActiveSprite:
// Given a SpriteAnimation with a set of sprite
// When this SpriteAnimation is set to certain time
//  And getActiveSprite is called 
// Then the correct sprite is returned
TEST(Unit_SpriteAnimationTest, getActiveSprite) {
  TextureMock texture;
  auto sprite1 = Sprite(texture, 0, 0, 10, 10);
  auto sprite2 = Sprite(texture, 0, 0, 10, 10);
  auto sprite3 = Sprite(texture, 0, 0, 10, 10);
  auto sprite4 = Sprite(texture, 0, 0, 10, 10);
  auto sprite5 = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite1,
	                                                          sprite2,
	                                                          sprite3,
	                                                          sprite4,
	                                                          sprite5 };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);


  // When
  const int i = 0;
  const float new_time = 5.0F + 10.F * i;
  animation.setExactTime(new_time);
  ASSERT_THAT(animation.getExactTime(), FloatEq(new_time));

  const Sprite& result = animation.getActiveSprite();

  // Then
  EXPECT_THAT(result, Ref(sprites.at(i)));
}


// - deepClone:
// Given A SpriteAnimation with a set of sprite
// When this SpriteAnimation is deep cloned
// Then a new deep copy of this SpriteAnimation is created.
TEST(Unit_SpriteAnimationTest, deepClone) {
  TextureMock texture;
  auto sprite1 = Sprite(texture, 0, 0, 10, 10);
  auto sprite2 = Sprite(texture, 0, 0, 10, 10);
  auto sprite3 = Sprite(texture, 0, 0, 10, 10);
  auto sprite4 = Sprite(texture, 0, 0, 10, 10);
  auto sprite5 = Sprite(texture, 0, 0, 10, 10);

  std::vector<std::reference_wrapper<const Sprite>> sprites { sprite1,
	                                                          sprite2,
	                                                          sprite3,
	                                                          sprite4,
	                                                          sprite5 };

  const float time_per_frame = 10.F;
  auto animation = SpriteAnimation(time_per_frame, sprites);


  // When
  SpriteAnimation result = animation.DeepClone();

  // Then
  EXPECT_THAT(result, Not(Ref(animation)));

  const float new_result_time = 20.F;
  result.setExactTime(new_result_time);

  EXPECT_THAT(result.getExactTime(), FloatEq(new_result_time));
  EXPECT_THAT(animation.getExactTime(), FloatEq(0.F));
}


} // View
} // PacMan
