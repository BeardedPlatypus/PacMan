#include "RendererMock.h"
#include "DispatcherMock.h"
#include "ResourceWrapperMock.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "texture/Texture.h"


using ::testing::Return;
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Eq;

namespace pacman {
namespace view {

TEST(TextureTest, GetDimensions_ReturnsExpectedResults) {
  // Setup
  auto p_resource_wrapper = std::make_unique<ResourceWrapperMock<SDL_Texture>>();
  SDL_Texture* sdl_tex = nullptr;

  const int expected_w = 10;
  const int expected_h = 12;

  EXPECT_CALL(*(p_resource_wrapper.get()), GetResource()).Times(1).WillOnce(Return(sdl_tex));

  DispatcherMock dispatcher;  

  EXPECT_CALL(dispatcher, QueryTexture(sdl_tex, NULL, NULL, _, _)).WillOnce(DoAll(SetArgPointee<3>(expected_w), 
                                                                                  SetArgPointee<4>(expected_h)));

  auto texture = Texture(std::move(p_resource_wrapper), &dispatcher);

  // Call
  SDL_Rect result = texture.GetDimensions();

  // Assert
  ASSERT_THAT(result.x, Eq(0));
  ASSERT_THAT(result.y, Eq(0));
  ASSERT_THAT(result.w, Eq(expected_w));
  ASSERT_THAT(result.h, Eq(expected_h));
}

TEST(TextureTest, Render_ReturnsExpectedResults) {
  // Setup
  RendererMock renderer;

  SDL_Rect clip;
  SDL_Rect src;

  const float angle = 12.3F;
  const bool flip_horizontally = true;
  const bool flip_vertically = true;

  auto p_resource_wrapper = std::make_unique<ResourceWrapperMock<SDL_Texture>>();
  SDL_Texture* sdl_tex = nullptr;

  EXPECT_CALL(*(p_resource_wrapper.get()), GetResource()).Times(1).WillOnce(Return(sdl_tex));

  DispatcherMock dispatcher;  

  EXPECT_CALL(renderer, RenderCopy(sdl_tex, 
                                   &clip, 
                                   &src, 
                                   angle, 
                                   flip_horizontally, 
                                   flip_vertically)).Times(1);
  
  auto texture = Texture(std::move(p_resource_wrapper), &dispatcher);

  // Call
  texture.Render(renderer, clip, src, angle, flip_horizontally, flip_vertically);
}



}
}
