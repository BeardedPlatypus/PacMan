#pragma once

#include "texture/ITextureManager.h"
#include "gmock/gmock.h"



class TextureManagerMock : public pacman::view::ITextureManager {
public:
	MOCK_METHOD(void, LoadTexture, (const std::string& file_path));
	MOCK_METHOD(bool, HasTexture, (const std::string& file_path), (const));

	MOCK_METHOD(const pacman::view::ITexture&, 
		          GetTexture,
			        (const std::string& file_path),
		          (const));
};
