#include "RendererMock.h"
#include "TextureMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <memory>

#include "texture/ITextureManager.h"

#pragma region using_statements
using ::testing::StrEq;
using ::testing::Return;
using ::testing::ByMove;
using ::testing::Eq;
using ::testing::Ref;
#pragma endregion


namespace pacman {
namespace view {

// loadTexture:
// Given a TextureManager
// When loadTexture is called
// Then the TextureManager has this texture
//  And the TextureManager returns the correct texture
TEST(TextureManagerTest, loadTexture_Single) {
  // Given
  RendererMock renderer;

  const std::string texture_path = "SomeTexturePath.png";
  
  EXPECT_CALL(renderer, LoadTexture(StrEq(texture_path)))
	  .WillOnce(Return(ByMove(std::make_unique<TextureMock>())));

  std::unique_ptr<ITextureManager> p_tex_man =
	  ITextureManager::construct(renderer);

  ASSERT_THAT(p_tex_man->hasTexture(texture_path), Eq(false));

  // When
  p_tex_man->loadTexture(texture_path);

  // Then
  EXPECT_THAT(p_tex_man->hasTexture(texture_path), Eq(true));
  EXPECT_THAT(p_tex_man->hasTexture("SomeUnloadedPath.png"), Eq(false));
}

// Given a TextureManager
// When loadTexture is called multiple times with different paths
// Then the TextureManager contains each of these textures
// And returns the correct textures
TEST(TextureManagerTest, loadTexture_Multiple) {
  // Given
  RendererMock renderer;

  const std::string texture_path1 = "SomeTexturePath1.png";
  const std::string texture_path2 = "SomeTexturePath2.png";
  const std::string texture_path3 = "SomeTexturePath3.png";
  
  EXPECT_CALL(renderer, LoadTexture(StrEq(texture_path1)))
	  .WillOnce(Return(ByMove(std::make_unique<TextureMock>())));
  EXPECT_CALL(renderer, LoadTexture(StrEq(texture_path2)))
	  .WillOnce(Return(ByMove(std::make_unique<TextureMock>())));
  EXPECT_CALL(renderer, LoadTexture(StrEq(texture_path3)))
	  .WillOnce(Return(ByMove(std::make_unique<TextureMock>())));

  std::unique_ptr<ITextureManager> p_tex_man =
	  ITextureManager::construct(renderer);

  ASSERT_THAT(p_tex_man->hasTexture(texture_path1), Eq(false));
  ASSERT_THAT(p_tex_man->hasTexture(texture_path2), Eq(false));
  ASSERT_THAT(p_tex_man->hasTexture(texture_path3), Eq(false));

  // When
  p_tex_man->loadTexture(texture_path1);
  p_tex_man->loadTexture(texture_path2);
  p_tex_man->loadTexture(texture_path3);

  // Then
  EXPECT_THAT(p_tex_man->hasTexture(texture_path1), Eq(true));
  EXPECT_THAT(p_tex_man->hasTexture(texture_path2), Eq(true));
  EXPECT_THAT(p_tex_man->hasTexture(texture_path3), Eq(true));
  EXPECT_THAT(p_tex_man->hasTexture("SomeUnloadedPath.png"), Eq(false));
}

// Given a TextureManager
// When loadTexture is called multiple times with the same path
// Then the TextureManager will only load the texture once
// And returns the correct texture
TEST(TextureManagerTest, loadTexture_SameTextureMultiple) {
  // Given
  RendererMock renderer;

  const std::string texture_path = "SomeTexturePath.png";
  
  EXPECT_CALL(renderer, LoadTexture(StrEq(texture_path)))
	  .WillOnce(Return(ByMove(std::make_unique<TextureMock>())));

  std::unique_ptr<ITextureManager> p_tex_man =
	  ITextureManager::construct(renderer);

  ASSERT_THAT(p_tex_man->hasTexture(texture_path), Eq(false));

  // When
  p_tex_man->loadTexture(texture_path);
  p_tex_man->loadTexture(texture_path);
  p_tex_man->loadTexture(texture_path);

  // Then
  EXPECT_THAT(p_tex_man->hasTexture(texture_path), Eq(true));
  EXPECT_THAT(p_tex_man->hasTexture("SomeUnloadedPath.png"), Eq(false));
}

}
}
