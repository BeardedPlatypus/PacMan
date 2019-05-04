#include "stdafx.h"
#include "Rendermanager.h"

#include <SDL_image.h>

#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

RenderManager::RenderManager() {

}

RenderManager::~RenderManager() {
	IMG_Quit();
	SDL_Quit();
}


void RenderManager::init() {
	this->initialiseSDL();
	this->initialiseWindow();
	this->initialiseRenderer();

	// Load texture.
	std::string file_path = "C:/Users/Monthy/Documents/projects/PacMan/src/PacMan/x64/Debug/assets/PacManLogo.png";

	auto tex = this->loadTexture(file_path);
	this->p_entity_texture = 
		std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>>(tex);
}


void RenderManager::render(const state::PlayerState& entity) const {
	SDL_RenderClear(this->p_renderer.get());

	SDL_Rect dst;
	dst.x = SCREEN_WIDTH / 2 - 182;
	dst.y = 2;
	dst.w = 182 * 2;
	dst.h = 48 * 2;

	SDL_RenderCopy(this->p_renderer.get(),
				   this->p_entity_texture.get(),
				   NULL, 
				   &dst);

	SDL_RenderPresent(this->p_renderer.get());
	SDL_Delay(100);
}


void RenderManager::initialiseSDL() {
	int sdl_init_result = SDL_Init(SDL_INIT_VIDEO);

	if (sdl_init_result != 0)
		throw ViewException("SDL_Init(SDL_INIT_VIDEO)",
							SDL_GetError());
}


void RenderManager::initialiseSDLImage() {
	int sdl_image_init_result = IMG_Init(IMG_INIT_PNG);

	if ((sdl_image_init_result & IMG_INIT_PNG) != IMG_INIT_PNG)
		throw ViewException("IMG_INIT(IMG_INIT_PNG)", "");
}


void RenderManager::initialiseWindow() {
	SDL_Window* p_window = SDL_CreateWindow("Monthy's PacMan",
											100,
											100,
											SCREEN_WIDTH,
											SCREEN_HEIGHT,
											SDL_WINDOW_SHOWN);

	if (p_window == nullptr)
		throw ViewException("SDL_CreateWindow",
							SDL_GetError());

	this->p_window = 
		std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>>(p_window);
}


void RenderManager::initialiseRenderer() {
	SDL_Renderer* p_renderer = SDL_CreateRenderer(this->p_window.get(),
												  -1, 
												  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (p_renderer == nullptr)
		throw ViewException("SDL_CreateRenderer",
							SDL_GetError());

	this->p_renderer = 
		std::unique_ptr<SDL_Renderer, SDL_Destructor<SDL_Renderer>>(p_renderer);
}


SDL_Texture* RenderManager::loadTexture(const std::string& file_path) {
	SDL_Texture* p_tex = IMG_LoadTexture(this->p_renderer.get(),
										 file_path.c_str());

	if (p_tex == nullptr)
		throw ViewException("IMG_LoadTexture",
							"");

	return p_tex;
}

}
}