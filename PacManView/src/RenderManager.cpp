#include "stdafx.h"
#include "RenderManager.h"

#include <SDL2/SDL_image.h>

#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

RenderManager::RenderManager() {

}

RenderManager::~RenderManager() {
	delete this->p_anim1;
	delete this->p_anim2;
	delete this->p_anim3;
	delete this->p_anim4;
	IMG_Quit();
	SDL_Quit();
}


void RenderManager::init() {
	this->initialiseSDL();
	this->initialiseWindow();
	this->initialiseRenderer();

	this->p_texture_manager = std::make_unique<TextureManager>(*(this->p_renderer.get()));
	this->p_sprite_manager = std::make_unique<SpriteManager>(*(this->p_texture_manager.get()));

	std::string file_path = "./assets/characters.png";
	this->p_sprite_manager->initSprite("test1", file_path,  0, 32, 16, 16);
	this->p_sprite_manager->initSprite("test2", file_path, 16, 32, 16, 16);

	this->p_sprite_manager->initSprite("test3", file_path,  0, 48, 16, 16);
	this->p_sprite_manager->initSprite("test4", file_path, 16, 48, 16, 16);

	this->p_sprite_manager->initSprite("test5", file_path,  0, 64, 16, 16);
	this->p_sprite_manager->initSprite("test6", file_path, 16, 64, 16, 16);

	this->p_sprite_manager->initSprite("test7", file_path,  0, 80, 16, 16);
	this->p_sprite_manager->initSprite("test8", file_path, 16, 80, 16, 16);

	this->p_sprite_manager->initSprite("p1", file_path,  0, 0, 16, 16);
	this->p_sprite_manager->initSprite("p2", file_path, 16, 0, 16, 16);
	this->p_sprite_manager->initSprite("p3", file_path, 32, 0, 16, 16);

	auto sprites1 = std::vector<std::string>();
	sprites1.push_back("test1");
	sprites1.push_back("test2");

    this->p_anim1 = this->p_sprite_manager->constructSpriteAnimation(0.3F, sprites1);

	auto sprites2 = std::vector<std::string>();
	sprites2.push_back("test3");
	sprites2.push_back("test4");

    this->p_anim2 = this->p_sprite_manager->constructSpriteAnimation(0.3F, sprites2);

	auto sprites3 = std::vector<std::string>();
	sprites3.push_back("test5");
	sprites3.push_back("test6");

    this->p_anim3 = this->p_sprite_manager->constructSpriteAnimation(0.3F, sprites3);

	auto sprites4 = std::vector<std::string>();
	sprites4.push_back("test7");
	sprites4.push_back("test8");

    this->p_anim4 = this->p_sprite_manager->constructSpriteAnimation(0.3F, sprites4);

	auto sprites5 = std::vector<std::string>();
	sprites5.push_back("p1");
	sprites5.push_back("p2");
	sprites5.push_back("p3");
	sprites5.push_back("p2");

    this->p_anim5 = this->p_sprite_manager->constructSpriteAnimation(0.15F, sprites5);
}


void RenderManager::render(float dtime) const {
	SDL_RenderClear(this->p_renderer.get());

	SDL_Rect dst;
	dst.x = SCREEN_WIDTH / 2 - 182;
	dst.y = 2;
	dst.w = 182 * 2;
	dst.h = 48 * 2;

	int x = SCREEN_WIDTH / 2 - 16;
	int y = 48 * 2 + 4;

	//const Sprite& sprite = p_sprite_manager->getSprite("test");
	//sprite.Render(*(this->p_renderer.get()), x, y, 4.0);
	this->p_anim1->update(dtime);
	this->p_anim1->getActiveSprite().Render(*(this->p_renderer.get()),
										   x, y, 4.0);
	this->p_anim2->update(dtime);
	this->p_anim2->getActiveSprite().Render(*(this->p_renderer.get()),
										   x - 16.F * 4, y, 4.0);
	this->p_anim3->update(dtime);
	this->p_anim3->getActiveSprite().Render(*(this->p_renderer.get()),
										   x - 32.F * 4, y, 4.0);
	this->p_anim4->update(dtime);
	this->p_anim4->getActiveSprite().Render(*(this->p_renderer.get()),
										   x - 48.F * 4, y, 4.0);
	
	this->p_anim5->update(dtime);
	this->p_anim5->getActiveSprite().Render(*(this->p_renderer.get()),
										   x + 32.F * 4, y, 4.0);

	SDL_RenderPresent(this->p_renderer.get());
	//SDL_Delay(100);
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


}
}