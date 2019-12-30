#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "renderer/Renderer.h"
#include "DispatcherMock.h"
#include "ResourceWrapperMock.h"

#include "exceptions/ViewException.h"
#include "texture/ITexture.h"

using ::testing::Return;
using ::testing::ByMove;
using ::testing::NotNull;

namespace pacman {
namespace view {

  TEST(RendererTest, Init_CallsCorrectCreation) {
  // Setup
  DispatcherMock dispatcher;

  SDL_Window* p_sdl_window = (SDL_Window*)37;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  auto renderer = Renderer(&dispatcher);

  // Call
  renderer.Init(p_sdl_window);
}


TEST(RendererTest, Init_CreationFailed_ThrowsViewException) {
  // Setup
  DispatcherMock dispatcher;

  SDL_Window* p_sdl_window = (SDL_Window*)37;
  
  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(nullptr)));

  auto renderer = Renderer(&dispatcher);

  // Call
  ASSERT_THROW(renderer.Init(p_sdl_window),
               ViewException);
}


class FlipOptions {
public:
  FlipOptions(bool flip_horizontally,
              bool flip_vertically,
              int expected_flip) :
      flip_horizontally(flip_horizontally),
      flip_vertically(flip_vertically),
      expected_flip((SDL_RendererFlip)expected_flip) { }

  const bool flip_horizontally;
  const bool flip_vertically;
  const SDL_RendererFlip expected_flip;
};


class RenderCopyTest : public ::testing::TestWithParam<FlipOptions> { };


TEST_P(RenderCopyTest, RenderCopy_CallsDispatcherCorrectly) {
  // Setup
  DispatcherMock dispatcher;
  SDL_Window* p_sdl_window = (SDL_Window*)37;
  SDL_Renderer* p_sdl_renderer = (SDL_Renderer*)41;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(*(p_sdl_renderer_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(p_sdl_renderer));

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  SDL_Texture* p_texture = (SDL_Texture*)43;
  SDL_Rect rect_src;
  SDL_Rect rect_dst;

  float angle = 5.0F;

  EXPECT_CALL(dispatcher, RenderCopyEx(p_sdl_renderer,
                                       p_texture,
                                       &rect_src,
                                       &rect_dst,
                                       angle,
                                       NULL,
                                       GetParam().expected_flip))
    .Times(1);

  auto renderer = Renderer(&dispatcher);
  renderer.Init(p_sdl_window);

  // Call
  renderer.RenderCopy(p_texture,
                      &rect_src, &rect_dst,
                      angle,
                      GetParam().flip_horizontally,
                      GetParam().flip_vertically);
}


INSTANTIATE_TEST_SUITE_P(RendererTest_RenderCopy,
                         RenderCopyTest,
                         ::testing::Values(FlipOptions(false, false, SDL_FLIP_NONE),
                                           FlipOptions(true,  false, SDL_FLIP_HORIZONTAL),
                                           FlipOptions(false, true,  SDL_FLIP_VERTICAL),
                                           FlipOptions(true,  true,  SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)));


TEST(RendererTest, RenderPresent_CallsDispatcherCorrectly) {
  // Setup
  DispatcherMock dispatcher;
  SDL_Window* p_sdl_window = (SDL_Window*)37;
  SDL_Renderer* p_sdl_renderer = (SDL_Renderer*)41;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(*(p_sdl_renderer_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(p_sdl_renderer));

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  EXPECT_CALL(dispatcher, RenderPresent(p_sdl_renderer))
    .Times(1);

  auto renderer = Renderer(&dispatcher);
  renderer.Init(p_sdl_window);

  // Call
  renderer.RenderPresent();
}


TEST(RendererTest, RenderClear_CallsDispatcherCorrectly) {
  // Setup
  DispatcherMock dispatcher;
  SDL_Window* p_sdl_window = (SDL_Window*)37;
  SDL_Renderer* p_sdl_renderer = (SDL_Renderer*)41;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(*(p_sdl_renderer_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(p_sdl_renderer));

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  EXPECT_CALL(dispatcher, RenderClear(p_sdl_renderer))
    .Times(1);

  auto renderer = Renderer(&dispatcher);
  renderer.Init(p_sdl_window);

  // Call
  renderer.RenderClear();
}


TEST(RendererTest, LoadTexture_CallsDispatcherCorrectly) {
  // Setup
  DispatcherMock dispatcher;
  SDL_Window* p_sdl_window = (SDL_Window*)37;
  SDL_Renderer* p_sdl_renderer = (SDL_Renderer*)41;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(*(p_sdl_renderer_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(p_sdl_renderer));

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  std::string file_path = "this/is/a/path.png";

  auto p_sdl_texture_resource = std::make_unique<ResourceWrapperMock<SDL_Texture>>();
  EXPECT_CALL(dispatcher, LoadTexture(p_sdl_renderer, file_path))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_texture_resource))));

  auto renderer = Renderer(&dispatcher);
  renderer.Init(p_sdl_window);

  // Call
  std::unique_ptr<ITexture> p_result = renderer.LoadTexture(file_path);

  ASSERT_THAT(p_result.get(), NotNull());
}


TEST(RendererTest, LoadTexture_TextureFailed_ThrowsViewException) {
  // Setup
  DispatcherMock dispatcher;
  SDL_Window* p_sdl_window = (SDL_Window*)37;
  SDL_Renderer* p_sdl_renderer = (SDL_Renderer*)41;
  
  auto p_sdl_renderer_resource = std::make_unique<ResourceWrapperMock<SDL_Renderer>>();

  EXPECT_CALL(*(p_sdl_renderer_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(p_sdl_renderer));

  EXPECT_CALL(dispatcher, CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_renderer_resource))));

  std::string file_path = "this/is/a/path.png";

  EXPECT_CALL(dispatcher, LoadTexture(p_sdl_renderer, file_path))
    .Times(1)
    .WillOnce(Return(ByMove(nullptr)));

  auto renderer = Renderer(&dispatcher);
  renderer.Init(p_sdl_window);

  ASSERT_THROW(renderer.LoadTexture(file_path),
               ViewException);
}

}
}
