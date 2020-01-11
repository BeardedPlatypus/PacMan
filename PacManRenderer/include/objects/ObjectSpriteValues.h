#pragma once

#include <string>


namespace pacman {
namespace renderer {
namespace values {

  /// <summary>
  /// The object sprite file.
  /// </summary>
  const std::string dots_sprite_file = "./assets/dots.png";
  
  /// <summary>
  /// The object sprite: small dot
  /// </summary>
  const std::string object_sprite_small_dot = "small_dot";
  
  /// <summary>
  /// The small dot offset
  /// </summary>
  const int small_dot_offset = 2;
  
  /// <summary>
  /// The small dot tile size
  /// </summary>
  const int small_dot_tile_size = 2;
  
  /// <summary>
  /// The object sprite: big dot
  /// </summary>
  const std::string object_sprite_big_dot = "big_dot";
  
  /// <summary>
  /// The big dot tile size
  /// </summary>
  const int big_dot_tile_size = 8;
}
}
}
