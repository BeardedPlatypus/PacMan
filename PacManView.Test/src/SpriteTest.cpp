#include "RendererMock.h"
#include "TextureMock.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "Sprite.h"


#pragma region using_statements
using ::testing::_;
using ::testing::Ref;
using ::testing::AllOf;
using ::testing::Field;
using ::testing::Matcher;
using ::testing::Return;
#pragma endregion


namespace pacman {
namespace view {

// Given a Texture
// When a Sprite is constructed with this Texture
// Then this Sprite has this Texture
// And the clipping rectangle is equal to the dimensions of the Texture
TEST(SpriteTest, GivenATexture_WhenASpriteIsConstructedWithThisTexture_ThenThisSpriteHasThisTextureAndTheClippingPlaneIsEqualToTheDimensionsOfTheTexture) {
    // Given
	SDL_Rect dim;
	dim.x = 0;
	dim.y = 0;
	dim.w = 200;
	dim.h = 300;

	auto clip_matcher = AllOf(Field(&SDL_Rect::x, dim.x),
	                          Field(&SDL_Rect::y, dim.y),
							  Field(&SDL_Rect::w, dim.w),
							  Field(&SDL_Rect::h, dim.h));

	TextureMock texture;
	ON_CALL(texture, GetDimensions())
		.WillByDefault(Return(dim));

    // When
	Sprite sprite = Sprite(texture);

	// Then
	EXPECT_THAT(sprite.GetTexture(), Ref(texture));
	EXPECT_THAT(sprite.GetClip(), clip_matcher);
}

// Given a Texture
//   And clipping values
// When a Sprite is constructed with this Texture
// Then this Sprite has this Texture
// And the clipping rectangle is equal to the provided clipping values
TEST(SpriteTest, GivenATexture_WhenASpriteIsConstructedWithThisTexture_ThenThisSpriteHasThisTextureAndTheClippingPlaneIsEqualToTheProvidedClippingValues) {
    // Given
	SDL_Rect dim;
	dim.x = 0;
	dim.y = 0;
	dim.w = 200;
	dim.h = 300;

	auto clip_matcher = AllOf(Field(&SDL_Rect::x, dim.x),
	                          Field(&SDL_Rect::y, dim.y),
							  Field(&SDL_Rect::w, dim.w),
							  Field(&SDL_Rect::h, dim.h));

	TextureMock texture;

    // When
	Sprite sprite = Sprite(texture, dim.x, dim.y, dim.w, dim.h);

	// Then
	EXPECT_THAT(sprite.GetTexture(), Ref(texture));
	EXPECT_THAT(sprite.GetClip(), clip_matcher);
}


// Given a Texture
//   and a Sprite using this Texture
//   and renderer 
//   and a location
// When Render is called on this Sprite
// Then the Texture is rendered correctly
TEST(SpriteTest, GivenATextureAndASpriteAndARendererAndALocation_WhenRenderIsCalledOnThisSprite_ThenTheTextureRendersCorrectly) {
	// Given
	RendererMock renderer;
	TextureMock texture;

	SDL_Rect expected_clip;
	expected_clip.x = 10;
	expected_clip.y = 20;
	expected_clip.w = 30;
	expected_clip.h = 40;

	auto clip_matcher = AllOf(Field(&SDL_Rect::x, expected_clip.x),
	                          Field(&SDL_Rect::y, expected_clip.y),
							  Field(&SDL_Rect::w, expected_clip.w),
							  Field(&SDL_Rect::h, expected_clip.h));

	SDL_Rect expected_dst;
	expected_dst.x = 50;
	expected_dst.y = 70;
	expected_dst.w = 45;
	expected_dst.h = 60;

	auto dst_matcher = AllOf(Field(&SDL_Rect::x, expected_dst.x),
	                         Field(&SDL_Rect::y, expected_dst.y),
						     Field(&SDL_Rect::w, expected_dst.w),
						     Field(&SDL_Rect::h, expected_dst.h));

	EXPECT_CALL(texture, 
				Render(Ref(renderer), 
					   clip_matcher, 
					   dst_matcher));

	Sprite sprite = Sprite(texture,
						   expected_clip.x,
						   expected_clip.y,
						   expected_clip.w,
						   expected_clip.h);

	// When
	sprite.Render(renderer, 
				  expected_dst.x, 
				  expected_dst.y,
				  1.5);
}

}
}
