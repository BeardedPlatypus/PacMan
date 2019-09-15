#pragma once

#include "renderer/IRenderer.h"
#include "texture/ITexture.h"
#include "gmock/gmock.h"


class RendererMock : public pacman::view::IRenderer {
public:
	MOCK_METHOD6(RenderCopy, void(SDL_Texture* p_texture,
								                const SDL_Rect* p_texture_clip,
								                const SDL_Rect* p_dest, 
                                float angle,
                                bool flip_horizontally,
                                bool flip_vertically));
	MOCK_METHOD0(RenderPresent, void());
	MOCK_METHOD0(RenderClear, void());

	MOCK_CONST_METHOD1(LoadTexture, 
					   std::unique_ptr<pacman::view::ITexture>(const std::string& file_path));
};
