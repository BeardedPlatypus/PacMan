#pragma once

#include "renderer/IRendererFactory.h"
#include "gmock/gmock.h"


class RendererFactoryMock : public pacman::view::IRendererFactory {
public:
  MOCK_METHOD(std::unique_ptr<pacman::view::IRenderer>, CreateRenderer, (pacman::view::sdl::IDispatcher* p_dispatcher), (const));
};

