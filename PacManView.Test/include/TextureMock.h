#pragma once

#include "texture/ITexture.h"
#include "gmock/gmock.h"


class TextureMock : public pacman::view::ITexture {
public:
	MOCK_METHOD(SDL_Rect, GetDimensions, (), (const));
	MOCK_METHOD(void, 
              Render, 
              (pacman::view::IRenderer&, SDL_Rect&, SDL_Rect&, float, bool, bool ), 
              (const));
};