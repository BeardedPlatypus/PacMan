#include "stdafx.h"
#include "renderer/ViewCore.h"

#include "exceptions/ViewException.h"
#include "SDL2/SDL_image.h"


namespace pacman {
namespace view {

ViewCore::ViewCore() { }


ViewCore::~ViewCore() {
  if (this->_sdl_image_initialised) IMG_Quit();
  if (this->_sdl_initialised) SDL_Quit();
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
	int sdl_init_result = SDL_Init(SDL_INIT_VIDEO);

	if (sdl_init_result != 0) {
		throw ViewException("SDL_Init(SDL_INIT_VIDEO)", SDL_GetError());
	}

	this->_sdl_initialised = true;
}


void ViewCore::InitialiseSDLImage() {
	int sdl_image_init_result = IMG_Init(IMG_INIT_PNG);

	if ((sdl_image_init_result & IMG_INIT_PNG) != IMG_INIT_PNG) {
		throw ViewException("IMG_INIT(IMG_INIT_PNG)", "");
	}

	this->_sdl_image_initialised = true;
}


void ViewCore::InitialiseWindow(int screenWidth, int screenHeight) {
	SDL_Window* p_window = 
		SDL_CreateWindow("Monthy's PacMan",
			               100,
										 100,
										 screenWidth,
										 screenHeight,
                     SDL_WINDOW_SHOWN);

	if (p_window == nullptr) {
		throw ViewException("SDL_CreateWindow", SDL_GetError());
	}

	this->_p_window = 
		std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>>(p_window);
}

}
}