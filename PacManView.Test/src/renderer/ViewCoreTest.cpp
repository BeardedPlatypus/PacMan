#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "renderer/IViewCore.h"
#include "exceptions/ViewException.h"

#include "DispatcherMock.h"
#include "RendererFactoryMock.h"
#include "RendererMock.h"
#include "ResourceWrapperMock.h"

using ::testing::ByMove;
using ::testing::Eq;
using ::testing::Ref;
using ::testing::Return;

namespace pacman {
namespace view {

TEST(ViewCoreTest, Initialise_CallsCorrectSDLFunctions) {
  // Setup
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();
 
  SDL_Window* window = (SDL_Window*)37;

  auto p_sdl_window_resource = std::make_unique<ResourceWrapperMock<SDL_Window>>();
  EXPECT_CALL(*(p_sdl_window_resource.get()), GetResource())
    .Times(1)
    .WillOnce(Return(window));

  EXPECT_CALL(*(p_renderer.get()), Init(window))
    .Times(1);

  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<DispatcherMock> p_dispatcher = std::make_unique<DispatcherMock>();

  int screen_width = 640;
  int screen_height = 1280;

  EXPECT_CALL((*(p_dispatcher.get())), InitSDL(SDL_INIT_VIDEO))
    .Times(1)
    .WillOnce(Return(0));

  EXPECT_CALL((*(p_dispatcher.get())), InitIMG(IMG_INIT_PNG))
    .Times(1)
    .WillOnce(Return(IMG_INIT_PNG));

  EXPECT_CALL((*(p_dispatcher.get())), CreateSDLWindow(Eq("Monthy's PacMan"), 
                                                       Eq(100), Eq(100),
                                                       Eq(screen_width), Eq(screen_height),
                                                       Eq(SDL_WINDOW_SHOWN)))
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_sdl_window_resource))));

  std::unique_ptr<IViewCore> view_core = IViewCore::Construct(std::move(p_dispatcher),
                                                              renderer_factory);

  // Call
  view_core->Initialise(screen_width, screen_height);
}


TEST(ViewCoreTest, Initialise_FailAtSDL_ThrowsViewException) {
  // Setup
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();
 
  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<DispatcherMock> p_dispatcher = std::make_unique<DispatcherMock>();

  int screen_width = 640;
  int screen_height = 1280;

  EXPECT_CALL((*(p_dispatcher.get())), InitSDL(SDL_INIT_VIDEO))
    .Times(1)
    .WillOnce(Return(5));

  std::unique_ptr<IViewCore> view_core = IViewCore::Construct(std::move(p_dispatcher),
                                                              renderer_factory);

  // Call
  ASSERT_THROW(view_core->Initialise(screen_width, screen_height),
               ViewException);
}


TEST(ViewCoreTest, Initialise_FailAtIMG_ThrowsViewException) {
  // Setup
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();
 
  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<DispatcherMock> p_dispatcher = std::make_unique<DispatcherMock>();

  int screen_width = 640;
  int screen_height = 1280;

  EXPECT_CALL((*(p_dispatcher.get())), InitSDL(SDL_INIT_VIDEO))
    .Times(1)
    .WillOnce(Return(0));

  EXPECT_CALL((*(p_dispatcher.get())), InitIMG(IMG_INIT_PNG))
    .Times(1)
    .WillOnce(Return(0));

  std::unique_ptr<IViewCore> view_core = IViewCore::Construct(std::move(p_dispatcher),
                                                              renderer_factory);

  // Call
  ASSERT_THROW(view_core->Initialise(screen_width, screen_height),
               ViewException);
}


TEST(ViewCoreTest, Initialise_FailAtWindow_ThrowsViewException) {
  // Setup
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();
 
  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<DispatcherMock> p_dispatcher = std::make_unique<DispatcherMock>();

  int screen_width = 640;
  int screen_height = 1280;

  EXPECT_CALL((*(p_dispatcher.get())), InitSDL(SDL_INIT_VIDEO))
    .Times(1)
    .WillOnce(Return(0));

  EXPECT_CALL((*(p_dispatcher.get())), InitIMG(IMG_INIT_PNG))
    .Times(1)
    .WillOnce(Return(IMG_INIT_PNG));

  EXPECT_CALL((*(p_dispatcher.get())), CreateSDLWindow(Eq("Monthy's PacMan"), 
                                                       Eq(100), Eq(100),
                                                       Eq(screen_width), Eq(screen_height),
                                                       Eq(SDL_WINDOW_SHOWN)))
    .Times(1)
    .WillOnce(Return(ByMove(nullptr)));

  std::unique_ptr<IViewCore> view_core = IViewCore::Construct(std::move(p_dispatcher),
                                                              renderer_factory);

  // Call
  ASSERT_THROW(view_core->Initialise(screen_width, screen_height),
               ViewException);
}


TEST(ViewCoreTest, GetRenderer_ReturnsRenderer) {
  // Setup
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();
  const IRenderer& renderer = *(p_renderer.get());
 
  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<DispatcherMock> p_dispatcher = std::make_unique<DispatcherMock>();

  std::unique_ptr<IViewCore> view_core = IViewCore::Construct(std::move(p_dispatcher),
                                                              renderer_factory);

  // Call
  ASSERT_THAT(view_core->GetRenderer(), Ref(renderer));
}


struct ScreenDim {
	ScreenDim(int x, int y) : x(x), y(y) { }

	int x;
	int y;
};

class InitialiseViewCorePatternTest : public ::testing::TestWithParam<ScreenDim> { };


// Given an IViewCore
//   and an invalid ScreenDim
// When initialise is called
// Then an error is thrown
TEST_P(InitialiseViewCorePatternTest, initialise_WithInvalidScreenDimsThrowsException) {
  // Given
  RendererFactoryMock renderer_factory;
  auto p_renderer = std::make_unique<RendererMock>();

  EXPECT_CALL(renderer_factory, CreateRenderer)
    .Times(1)
    .WillOnce(Return(ByMove(std::move(p_renderer))));

  std::unique_ptr<sdl::IDispatcher> p_dispatcher = std::make_unique<DispatcherMock>();
  std::unique_ptr<IViewCore> view_core = 
    IViewCore::Construct(std::move(p_dispatcher), renderer_factory);
  ScreenDim screen_dim = GetParam();

  // When | Then
  ASSERT_THROW(view_core->Initialise(screen_dim.x, screen_dim.y),
               ViewException);
}


INSTANTIATE_TEST_SUITE_P(InitViewCore_InvalidScreenDimThrowException,
						 InitialiseViewCorePatternTest,
						 ::testing::Values(ScreenDim( -1, 100), 
										   ScreenDim(  0, 100),
										   ScreenDim(100,   0),
										   ScreenDim(100,  -1),
										   ScreenDim(  0,   0),
										   ScreenDim( -1,  -1)));
}
}
