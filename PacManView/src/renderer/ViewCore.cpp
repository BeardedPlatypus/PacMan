#include "stdafx.h"
#include "renderer/ViewCore.h"

#include "exceptions/ViewException.h"
#include "SDL2/SDL_image.h"


namespace pacman {
namespace view {

ViewCore::ViewCore(std::unique_ptr<sdl::IDispatcher> p_sdl_dispatcher) :
    p_sdl_dispatcher(std::move(p_sdl_dispatcher)) { 
}


ViewCore::~ViewCore() {
	if (this->_sdl_image_initialised) {
		this->p_sdl_dispatcher->QuitIMG();
	}

	if (this->_sdl_initialised) {
		this->p_sdl_dispatcher->QuitSDL();
	}
}


void ViewCore::Initialise(int screen_width, int screen_height) {
  if (screen_width <= 0 || screen_height <= 0)
    throw ViewException("initialise", "");

  this->InitialiseSDL();
  this->InitialiseSDLImage();
  this->InitialiseWindow(screen_width, screen_height);

  this->_p_renderer->Init(this->_p_window.get());
}


void ViewCore::InitialiseSDL() {
	int sdl_init_result =
		this->p_sdl_dispatcher->InitSDL(SDL_INIT_VIDEO);

	if (sdl_init_result != 0) {
		throw ViewException("SDL_Init(SDL_INIT_VIDEO)",
			                  this->p_sdl_dispatcher->GetError());
	}

	this->_sdl_initialised = true;
}


void ViewCore::InitialiseSDLImage() {
	int sdl_image_init_result = 
		this->p_sdl_dispatcher->InitIMG(IMG_INIT_PNG);

	if ((sdl_image_init_result & IMG_INIT_PNG) != IMG_INIT_PNG) {
		throw ViewException("IMG_INIT(IMG_INIT_PNG)", "");
	}

	this->_sdl_image_initialised = true;
}


void ViewCore::InitialiseWindow(int screenWidth, int screenHeight) {
	SDL_Window* p_window = 
		this->p_sdl_dispatcher->CreateSDLWindow("Monthy's PacMan",
			                                      100,
										                        100,
										                        screenWidth,
										                        screenHeight,
                                            SDL_WINDOW_SHOWN);

	if (p_window == nullptr) {
		throw ViewException("SDL_CreateWindow",
			                  this->p_sdl_dispatcher->GetError());
	}

	this->_p_window = 
		std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>>(p_window);
}

}
}