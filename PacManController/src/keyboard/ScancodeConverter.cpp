#include "stdafx.h"
#include "keyboard/ScancodeConverter.h"


namespace pacman {
namespace controller {
namespace keyboard {

ScancodeConverter::ScancodeConverter() {
  this->scancode_map[SDL_SCANCODE_W] = Scancode::W;
  this->scancode_map[SDL_SCANCODE_A] = Scancode::A;
  this->scancode_map[SDL_SCANCODE_S] = Scancode::S;
  this->scancode_map[SDL_SCANCODE_D] = Scancode::D;

  this->scancode_map[SDL_SCANCODE_ESCAPE] = Scancode::Escape;

  this->scancode_map[SDL_SCANCODE_UP]    = Scancode::ArrowUp;
  this->scancode_map[SDL_SCANCODE_LEFT]  = Scancode::ArrowLeft;
  this->scancode_map[SDL_SCANCODE_DOWN]  = Scancode::ArrowDown;
  this->scancode_map[SDL_SCANCODE_RIGHT] = Scancode::ArrowRight;
}


Scancode ScancodeConverter::Convert(SDL_Scancode sdl_scancode) const {
  if (this->scancode_map.find(sdl_scancode) == this->scancode_map.end())
    return Scancode::UnmappedCode;

  return this->scancode_map.at(sdl_scancode);
}

}
}
}