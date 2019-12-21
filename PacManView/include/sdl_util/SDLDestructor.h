#pragma once

#include <SDL2/SDL.h>


namespace pacman {
namespace view {

template <typename T>
struct SDL_Destructor {
	void operator()(T* p) const;
};

template <>
struct SDL_Destructor<SDL_Window> {
	void operator()(SDL_Window* p) const {
		SDL_DestroyWindow(p);
	}
};


template <>
struct SDL_Destructor<SDL_Renderer> {
	void operator()(SDL_Renderer* p) const {
		SDL_DestroyRenderer(p);
	}
};


template <>
struct SDL_Destructor<SDL_Texture> {
	void operator()(SDL_Texture* p) const {
		SDL_DestroyTexture(p);
	}
};

} // view
} // pacman
