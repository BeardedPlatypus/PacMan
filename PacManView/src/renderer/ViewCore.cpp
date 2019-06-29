#include "stdafx.h"
#include "renderer/ViewCore.h"

#include "exceptions/ViewException.h"
#include "SDL2/SDL_image.h"


namespace pacman {
namespace view {

ViewCore::ViewCore() { 
  this->p_renderer = std::make_unique<Renderer>();
}

ViewCore::~ViewCore() {
  if (this->sdl_image_initialised) IMG_Quit();
  if (this->sdl_initialised) SDL_Quit();
}

void ViewCore::initialise(int screen_width, int screen_height) {
  if (screen_width <= 0 || screen_height <= 0)
    throw ViewException("initialise", "");

  this->initialiseSDL();
  this->initialiseSDLImage();
  this->initialiseWindow(screen_width, screen_height);

  this->p_renderer->Init(this->p_window.get());
}


void ViewCore::initialiseSDL() {
	int sdl_init_result = SDL_Init(SDL_INIT_VIDEO);

	if (sdl_init_result != 0)
		throw ViewException("SDL_Init(SDL_INIT_VIDEO)",
							SDL_GetError());

	sdl_initialised = true;
}


void ViewCore::initialiseSDLImage() {
	int sdl_image_init_result = IMG_Init(IMG_INIT_PNG);

	if ((sdl_image_init_result & IMG_INIT_PNG) != IMG_INIT_PNG)
		throw ViewException("IMG_INIT(IMG_INIT_PNG)", "");

	sdl_image_initialised = true;
}


void ViewCore::initialiseWindow(int screenWidth, int screenHeight) {
	SDL_Window* p_window = SDL_CreateWindow("Monthy's PacMan",
											100,
											100,
											screenWidth,
											screenHeight,
											SDL_WINDOW_SHOWN);

	if (p_window == nullptr)
		throw ViewException("SDL_CreateWindow",
							SDL_GetError());

	this->p_window = 
		std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>>(p_window);
}

}
}