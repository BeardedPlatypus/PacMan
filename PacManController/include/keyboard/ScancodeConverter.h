#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>

#include "Scancode.h"


namespace pacman {
namespace controller {
namespace keyboard {
  
/// <summary>
/// <see cref="ScancodeConverter" /> is responsible for mapping 
/// <see cref="SDL_Scancode" />s to <see cref="keyboard::Scancode" />.
/// </summary>
class ScancodeConverter {
public:  
  /// <summary>
  /// Construct a new <see cref="ScancodeConverter"/>.
  /// </summary>
  ScancodeConverter();
    
  /// <summary>
  /// Convert the specified <paramref name="sdl_scancode" /> to 
  /// the corresponding <see cref="Scancode" /> if it is mapped,
  /// else a <see cref="Scancode::UnmappedCode" /> is returned.
  /// </summary>
  /// <param name="sdl_scancode">The SDL scancode.</param>
  /// <returns>
  /// The corresponding <see cref="Scancode" /> if it exists, 
  /// else Scancode::UnmappedCode.
  /// </returns>
  Scancode Convert(SDL_Scancode sdl_scancode) const;

private:  
  /// <summary>
  /// The scancode map of this <see cref="ScancodeConverter" />
  /// </summary>
  std::unordered_map<SDL_Scancode, Scancode> scancode_map = 
    std::unordered_map<SDL_Scancode, Scancode>();
};

}
}
}
