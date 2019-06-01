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
#pragma endregion


namespace pacman {
namespace view {

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
