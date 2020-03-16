#pragma once

#include "renderer/IRenderer.h"
#include "texture/ITexture.h"
#include "gmock/gmock.h"


class RendererMock : public pacman::view::IRenderer {
public:
	MOCK_METHOD(void, Init, (SDL_Window*));

	MOCK_METHOD(void, 
		          RenderCopy, 
		          (SDL_Texture*, const SDL_Rect*, const SDL_Rect*, float, bool, bool));
	MOCK_METHOD(void, RenderPresent, ());
	MOCK_METHOD(void, RenderClear, ());

	MOCK_METHOD(std::unique_ptr<pacman::view::ITexture>, 
		          LoadTexture, 
					    (const std::string& file_path),
		          (const));
};
