#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "renderer/IViewCore.h"
#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

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
  std::unique_ptr<IViewCore> view_core = IViewCore::Construct();
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
