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
using ::testing::Ne;
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  // Then
  const int expected_n_frames = sprites.size();
  EXPECT_THAT(p_animation->GetNFrames(), Eq(expected_n_frames));

  const float expected_fps = 1.F / time_per_frame;
  EXPECT_THAT(p_animation->GetFramesPerSecond(), FloatEq(expected_fps));

  const float expected_cur_time = 0.F;
  EXPECT_THAT(p_animation->GetInternalTime(), FloatEq(expected_cur_time));
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  ASSERT_THAT(p_animation->GetInternalTime(), FloatEq(0.F));

  const float new_time = 2.3F;

  // When
  p_animation->SetInternalTime(new_time);

  // Then
  EXPECT_THAT(p_animation->GetInternalTime(), FloatEq(new_time));
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  ASSERT_THAT(p_animation->GetInternalTime(), FloatEq(0.0));

  const float new_time = 2.5F;
  const float new_time_large = time_per_frame * 10 + new_time;

  // When
  p_animation->SetInternalTime(new_time_large);

  // Then
  EXPECT_THAT(p_animation->GetInternalTime(), FloatEq(new_time));
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  ASSERT_THAT(p_animation->GetExactTime(), FloatEq(0.0));

  const float new_time = 12.3F;

  // When
  p_animation->SetExactTime(new_time);

  // Then
  EXPECT_THAT(p_animation->GetExactTime(), FloatEq(new_time));
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  const float start_time = 15.F;
  p_animation->SetExactTime(start_time);
  ASSERT_THAT(p_animation->GetExactTime(), FloatEq(start_time));

  const float update_time = 5.F;

  // When
  p_animation->UpdateTime(update_time);

  // Then
  EXPECT_THAT(p_animation->GetExactTime(), FloatEq(start_time + update_time));
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
  auto p_animation = ISpriteAnimation::Construct(time_per_frame, sprites);

  const float start_time = 15.F;
  p_animation->SetExactTime(start_time);
  ASSERT_THAT(p_animation->GetExactTime(), FloatEq(start_time));

  // When
  p_animation->ResetTime();

  // Then
  EXPECT_THAT(p_animation->GetExactTime(), FloatEq(0.F));
}


std::vector<std::reference_wrapper<const Sprite>> GetSprites() {
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
  return sprites;
}


// - getActiveSprite:
// Given a SpriteAnimation with a set of sprite
// When this SpriteAnimation is set to certain time
//  And getActiveSprite is called 
// Then the correct sprite is returned
TEST(Unit_SpriteAnimationTest, getActiveSprite) {
  // Given
  std::vector<std::reference_wrapper<const Sprite>> sprites = GetSprites();
  auto p_animation = ISpriteAnimation::Construct(10.F, sprites);

  // When
  const int i = 0;
  const float new_time = 5.0F + 10.F * i;
  p_animation->SetExactTime(new_time);
  ASSERT_THAT(p_animation->GetExactTime(), FloatEq(new_time));

  const Sprite& result = p_animation->GetActiveSprite();

  // Then
  EXPECT_THAT(result, Ref(sprites.at(i)));
}


// - deepClone:
// Given A SpriteAnimation with a set of sprite
// When this SpriteAnimation is deep cloned
// Then a new deep copy of this SpriteAnimation is created.
TEST(Unit_SpriteAnimationTest, deepClone) {
  // Given
  std::vector<std::reference_wrapper<const Sprite>> sprites = GetSprites();
  auto p_animation = ISpriteAnimation::Construct(10.F, sprites);

  // When
  std::unique_ptr<ISpriteAnimation> result = p_animation->DeepClone();

  // Then
  EXPECT_THAT(result.get(), Ne(p_animation.get()));

  const float new_result_time = 20.F;
  result->SetExactTime(new_result_time);

  EXPECT_THAT(result->GetExactTime(), FloatEq(new_result_time));
  EXPECT_THAT(p_animation->GetExactTime(), FloatEq(0.F));
}


} // View
} // PacMan
