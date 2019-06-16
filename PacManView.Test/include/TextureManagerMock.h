#pragma once

#include "texture/ITextureManager.h"
#include "gmock/gmock.h"



class TextureManagerMock : public pacman::view::ITextureManager {
public:
	MOCK_METHOD1(loadTexture,
				 void(const std::string& file_path));
	MOCK_METHOD1(hasTexture, 
				 bool(const std::string& file_path));

	MOCK_CONST_METHOD1(getTexture,
					   const pacman::view::ITexture&(const std::string& file_path));
};
