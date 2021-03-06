#include "TextureManagerMock.h"
#include "TextureMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sprite/ISpriteManager.h"
#include "exceptions/ViewException.h"
#include "sprite/ClipRect.h"


#pragma region using_statements
using ::testing::StrEq;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::Ref;
using ::testing::_;
using ::testing::AllOf;
using ::testing::Field;
using ::testing::Eq;
#pragma endregion


namespace pacman {
namespace view {
// Given an ISpriteManager
//   and a path to a texture
//   and a TextureManager without the specified texture
// When initSprite is called with this path
// Then the specified texture is loaded
TEST(SpriteManagerTest, InitSprite_WithClipping_LoadsTextureIfNoneExists) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	const int x = 5;
	const int y = 6;
	const int w = 7;
	const int h = 8;

	EXPECT_CALL(texture_manager, LoadTexture(StrEq(path)));
	ON_CALL(texture_manager, GetTexture(_))
		.WillByDefault(ReturnRef(texture));

	std::unique_ptr<ISpriteManager> p_sprite_manager =
		ISpriteManager::Construct(texture_manager);

	// When
	p_sprite_manager->InitSprite(label, path, x, y, w, h);
}


// Given an ISpriteManager
//   and a path to a texture
//   and a TextureManager without the specified texture
// When initSprite is called with this path
// Then the specified texture is loaded
TEST(SpriteManagerTest, InitSprite_WithoutClipping_LoadsTextureIfNoneExists) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	EXPECT_CALL(texture_manager, LoadTexture(StrEq(path)));
	ON_CALL(texture_manager, GetTexture(_))
		.WillByDefault(ReturnRef(texture));

	std::unique_ptr<ISpriteManager> p_sprite_manager =
		ISpriteManager::Construct(texture_manager);

	// When
	p_sprite_manager->InitSprite(label, path);
}


// Given an ISpriteManager
//   and a label
//   and a sprite_sheet_path
//   and a clipping square
// When initSprite is called with these arguments
// Then ISpriteManager has a corresponding Sprite
TEST(SpriteManagerTest, InitSprite_WithClippingRectangle) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	const int expected_x = 5;
	const int expected_y = 6;
	const int expected_w = 7;
	const int expected_h = 8;

	EXPECT_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillOnce(ReturnRef(texture));

	// When
	p_sprite_man->InitSprite(label,
							 path,
							 expected_x,
							 expected_y,
							 expected_w,
							 expected_h);

	// Then
	EXPECT_TRUE(p_sprite_man->HasSprite(label));
	
	const Sprite& result = p_sprite_man->GetSprite(label);

	EXPECT_THAT(result.GetTexture(), Ref(texture));

	auto clip_matcher = AllOf(Field(&SDL_Rect::x, expected_x),
	                          Field(&SDL_Rect::y, expected_y),
							  Field(&SDL_Rect::w, expected_w),
							  Field(&SDL_Rect::h, expected_h));
	EXPECT_THAT(result.GetClip(), clip_matcher);
}


// Given an ISpriteManager
//   and a label
//   and a sprite_sheet_path
// When initSprite is called with these arguments
// Then ISpriteManager has a corresponding Sprite
TEST(SpriteManagerTest, InitSprite_WithoutClippingRectangle) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	const int expected_w = 15;
	const int expected_h = 16;

	SDL_Rect clip_rect;
	clip_rect.x = 0;
	clip_rect.y = 0;
	clip_rect.w = expected_w;
	clip_rect.h = expected_h;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";


	ON_CALL(texture, GetDimensions())
		.WillByDefault(Return(clip_rect));

	EXPECT_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillOnce(ReturnRef(texture));

	// When
	p_sprite_man->InitSprite(label,
							 path);

	// Then
	EXPECT_TRUE(p_sprite_man->HasSprite(label));
	
	const Sprite& result = p_sprite_man->GetSprite(label);

	EXPECT_THAT(result.GetTexture(), Ref(texture));

	auto clip_matcher = AllOf(Field(&SDL_Rect::x, 0),
	                          Field(&SDL_Rect::y, 0),
							  Field(&SDL_Rect::w, expected_w),
							  Field(&SDL_Rect::h, expected_h));
	EXPECT_THAT(result.GetClip(), clip_matcher);
}


// Given an ISpriteManager
//   and a label that already exists
//   and a sprite_sheet_path
// When initSprite is called with these arguments
// Then an exception is thrown
TEST(SpriteManagerTest, InitSprite_AlreadyExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	p_sprite_man->InitSprite(label,
							 path);

	// When | Then
	ASSERT_THROW(p_sprite_man->InitSprite(label, path),
				       ViewException);
}


// Given an ISpriteManager
//   and a label that already exists
//   and a sprite_sheet_path
//   and some valid dimensions
// When initSprite is called with these arguments
// Then an exception is thrown
TEST(SpriteManagerTest, InitSpriteWithDim_AlreadyExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	p_sprite_man->InitSprite(label, path);

	// When | Then
	ASSERT_THROW(p_sprite_man->InitSprite(label, path, 10, 10, 100, 100),
				 ViewException);
}


class InitSpriteDimensionPatternTest : public ::testing::TestWithParam<ClipRect> { };


// Given an ISpriteManager
//   and a label
//   and a sprite_sheet_path
//   and an invalid dimension
// When initSprite is called with these arguments
// Then an exception is thrown
TEST_P(InitSpriteDimensionPatternTest, InitSprite_InvalidDimensionThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	ClipRect dim = GetParam();

	// When | Then
	ASSERT_THROW(p_sprite_man->InitSprite(label, path, dim.x, dim.y, dim.w, dim.h), ViewException);
}


INSTANTIATE_TEST_SUITE_P(InitSpriteWithInvalidDimension,
						 InitSpriteDimensionPatternTest,
						 ::testing::Values(ClipRect(0, 0, -1,  100),
										   ClipRect(0, 0, 100,  -1),
										   ClipRect(0, 0,   0, 100),
										   ClipRect(0, 0, 100,   0),
										   ClipRect(0, 0,  -1,  -1),
										   ClipRect(0, 0,   0,   0)));


// Given an ISpriteManager
//   and a label of a non-existing sprite 
// When getSprite is called with this label
// Then an exception is thrown
TEST(SpriteManagerTest, GetSprite_NoExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";

	// When | Then
	ASSERT_THROW(p_sprite_man->GetSprite(label), ViewException);
}


// Given an ISpriteManager
//   and a label
//   and a time per frame
//   and a set of sprites
// When initSpriteAnimation is called
// Then ISpriteManager has the corresponding SpriteAnimation
TEST(SpriteManagerTest, InitSpriteAnimation) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::vector<std::string> labels = { 
		"this_is_a_label",
		"this_is_a_label_too"
	};

	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	// Set up two sprites we will use.
	for(auto label : labels)
		p_sprite_man->InitSprite(label, path);

	float expected_time_per_frame = 10.F;

	const std::string animation_label = "this_is_an_animation_label";

	// When
	p_sprite_man->InitSpriteAnimation(animation_label, expected_time_per_frame, labels);


	// Then
	EXPECT_TRUE(p_sprite_man->HasSpriteAnimation(animation_label));

	ISpriteAnimation* sprite_anim = p_sprite_man->GetSpriteAnimation(animation_label);
	EXPECT_THAT(sprite_anim->GetTimePerFrame(), Eq(expected_time_per_frame));
	EXPECT_THAT(sprite_anim->GetActiveSprite(), Ref(p_sprite_man->GetSprite(labels[0])));

	sprite_anim->SetInternalTime(1.5F);
	EXPECT_THAT(sprite_anim->GetActiveSprite(), Ref(p_sprite_man->GetSprite(labels[1])));
}


// Given an ISpriteManager
//   and a label that already exists
//   and a time per frame
//   and a set of sprites
// When initSpriteAnimation is called
// Then an exception is thrown
TEST(SpriteManagerTest, InitSpriteAnimation_AlreadyExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::vector<std::string> labels = { 
		"this_is_a_label",
		"this_is_a_label_too"
	};

	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	// Set up two sprites we will use.
	for(auto label : labels)
		p_sprite_man->InitSprite(label, path);

	float expected_time_per_frame = 10.F;
	const std::string animation_label = "this_is_an_animation_label";

	p_sprite_man->InitSpriteAnimation(animation_label, 
									                  expected_time_per_frame, 
									                  labels);
	
	// When | Then
	ASSERT_THROW(p_sprite_man->InitSpriteAnimation(animation_label, 
												                         expected_time_per_frame, 
												                         labels),
				       ViewException);
}


// Given an ISpriteManager
//   and a label
//   and a time per frame
//   and a set of sprites containing non existent sprites
// When initSpriteAnimation is called
// Then an exception is thrown
TEST(SpriteManagerTest, InitSpriteAnimation_SpriteLabelNotExistingThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::vector<std::string> labels = { "this_is_a_label",
											  "this_is_a_label_too"
	};

	float expected_time_per_frame = 10.F;

	const std::string animation_label = "this_is_an_animation_label";

	// When | Then
	ASSERT_THROW(p_sprite_man->InitSpriteAnimation(animation_label, 
												   expected_time_per_frame, 
												   labels),
				 ViewException);
}


// Given an ISpriteManager
//   and a label
//   and an invalid time per frame
//   and a set of sprites
// When initSpriteAnimation is called
// Then an exception is thrown
TEST(SpriteManagerTest, InitSpriteAnimation_InvalidTimePerFrameThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::vector<std::string> labels = { "this_is_a_label",
											  "this_is_a_label_too"
	};

	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, GetTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	// Set up two sprites we will use.
	for(auto label : labels)
		p_sprite_man->InitSprite(label, path);

	const std::string animation_label = "this_is_an_animation_label";

	// When | Then
	ASSERT_THROW(p_sprite_man->InitSpriteAnimation(animation_label, 
												   -10.0,
												   labels),
				 ViewException);
}


// Given an ISpriteManager
//   and a label of a non-existing sprite animation
// When getSpriteAnimation is called with this label
// Then an exception is thrown
TEST(SpriteManagerTest, GetSpriteAnimation_NoExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::Construct(texture_manager);

	const std::string label = "this_is_a_label";

	// When | Then
	ASSERT_THROW(p_sprite_man->GetSpriteAnimation(label),
				 ViewException);
}

}
}
