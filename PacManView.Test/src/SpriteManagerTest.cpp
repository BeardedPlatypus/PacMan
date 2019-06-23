#include "TextureManagerMock.h"
#include "TextureMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sprite/ISpriteManager.h"
#include "exceptions/ViewException.h"


#pragma region using_statements
using ::testing::StrEq;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::Ref;
using ::testing::_;
using ::testing::AllOf;
using ::testing::Field;
#pragma endregion


namespace pacman {
namespace view {
// Given an ISpriteManager
//   and a path to a texture
//   and a TextureManager without the specified texture
// When initSprite is called with this path
// Then the specified texture is loaded
TEST(SpriteManagerTest, initSprite_withClipping_loadsTextureIfNoneExists) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	const int x = 5;
	const int y = 6;
	const int w = 7;
	const int h = 8;

	EXPECT_CALL(texture_manager, loadTexture(StrEq(path)));
	ON_CALL(texture_manager, getTexture(_))
		.WillByDefault(ReturnRef(texture));

	std::unique_ptr<ISpriteManager> p_sprite_manager =
		ISpriteManager::construct(texture_manager);

	// When
	p_sprite_manager->initSprite(label, path, x, y, w, h);
}


// Given an ISpriteManager
//   and a path to a texture
//   and a TextureManager without the specified texture
// When initSprite is called with this path
// Then the specified texture is loaded
TEST(SpriteManagerTest, initSprite_withoutClipping_loadsTextureIfNoneExists) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	EXPECT_CALL(texture_manager, loadTexture(StrEq(path)));
	ON_CALL(texture_manager, getTexture(_))
		.WillByDefault(ReturnRef(texture));

	std::unique_ptr<ISpriteManager> p_sprite_manager =
		ISpriteManager::construct(texture_manager);

	// When
	p_sprite_manager->initSprite(label, path);
}


// Given an ISpriteManager
//   and a label
//   and a sprite_sheet_path
//   and a clipping square
// When initSprite is called with these arguments
// Then ISpriteManager has a corresponding Sprite
TEST(SpriteManagerTest, initSprite_WithClippingRectangle) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	const int expected_x = 5;
	const int expected_y = 6;
	const int expected_w = 7;
	const int expected_h = 8;

	EXPECT_CALL(texture_manager, getTexture(StrEq(path)))
		.WillOnce(ReturnRef(texture));

	// When
	p_sprite_man->initSprite(label,
							 path,
							 expected_x,
							 expected_y,
							 expected_w,
							 expected_h);

	// Then
	EXPECT_TRUE(p_sprite_man->hasSprite(label));
	
	const Sprite& result = p_sprite_man->getSprite(label);

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
TEST(SpriteManagerTest, initSprite_WithoutClippingRectangle) {
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
		ISpriteManager::construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";


	ON_CALL(texture, GetDimensions())
		.WillByDefault(Return(clip_rect));

	EXPECT_CALL(texture_manager, getTexture(StrEq(path)))
		.WillOnce(ReturnRef(texture));

	// When
	p_sprite_man->initSprite(label,
							 path);

	// Then
	EXPECT_TRUE(p_sprite_man->hasSprite(label));
	
	const Sprite& result = p_sprite_man->getSprite(label);

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
TEST(SpriteManagerTest, initSprite_AlreadyExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;
	TextureMock texture;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	ON_CALL(texture_manager, getTexture(StrEq(path)))
		.WillByDefault(ReturnRef(texture));

	p_sprite_man->initSprite(label,
							 path);

	// When | Then
	ASSERT_THROW(p_sprite_man->initSprite(label, path),
				 ViewException);
}


// Given an ISpriteManager
//   and a label of a non-existing sprite 
// When getSprite is called with this label
// Then an exception is thrown
TEST(SpriteManagerTest, getSprite_NoExistingLabelThrowsException) {
	// Given
	TextureManagerMock texture_manager;

	std::unique_ptr<ISpriteManager> p_sprite_man =
		ISpriteManager::construct(texture_manager);

	const std::string label = "this_is_a_label";
	const std::string path = "this/is/a/path.png";

	// When | Then
	ASSERT_THROW(p_sprite_man->getSprite(label),
				 ViewException);
}

// Given an ISpriteManager
//   and a label
//   and a time per frame
//   and a set of sprites
// When initSpriteAnimation is called
// Then ISpriteManager has the corresponding SpriteAnimation


// Given an ISpriteManager
//   and a label that already exists
//   and a time per frame
//   and a set of sprites
// When initSpriteAnimation is called
// Then an exception is thrown


// Given an ISpriteManager
//   and a label
//   and a time per frame
//   and a set of sprites containing non existent sprites
// When initSpriteAnimation is called
// Then an exception is thrown


// Given an ISpriteManager
//   and a label
//   and a sprite_sheet_path
//   and an invalid dimension
// When initSprite is called with these arguments
// Then an exception is thrown

// TODO: add tests verifying input (strings etc.)

}
}

