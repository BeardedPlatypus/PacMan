#pragma once

#include "texture/ITexture.h"
#include "gmock/gmock.h"


class TextureMock : public pacman::view::ITexture {
public:
	MOCK_CONST_METHOD0(GetDimensions, SDL_Rect());
	MOCK_CONST_METHOD6(Render, void(pacman::view::IRenderer& renderer,
									                SDL_Rect& clip,
									                SDL_Rect& dst, 
                                  float angle,
                                  bool flip_horizontally,
                                  bool flip_vertically));
};