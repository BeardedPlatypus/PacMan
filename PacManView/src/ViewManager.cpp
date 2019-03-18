#include "pch.h"
#include "ViewManager.h"

#include <iostream>
#include <SDL.h>

namespace pacman {
namespace view {

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int ViewManager::run() {
    std::cout << "Starting PacMan application.\n"; 
	
	// The window we'll be rendering to
    SDL_Window* window = nullptr;
    
    // The surface contained by the window
    SDL_Surface* screen_surface = nullptr;
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create window
	window = SDL_CreateWindow("PacMan", 
							  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
							  SCREEN_WIDTH, SCREEN_HEIGHT, 
							  SDL_WINDOW_SHOWN);

	if( window == nullptr ) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
    }

	// Create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 
												-1, 
												SDL_RENDERER_ACCELERATED | 
												SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}



	// Get Window surface
	screen_surface = SDL_GetWindowSurface(window);

	// Fill render with white
	SDL_FillRect(screen_surface, 
				 nullptr, 
				 SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));

	// Update the surface
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);

	// Clean up the window
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}


}
}