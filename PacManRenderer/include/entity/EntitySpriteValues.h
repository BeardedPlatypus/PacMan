#pragma once

#include <string>


namespace pacman {
namespace renderer {
namespace values {
  /// <summary>
  /// The entity sprite file
  /// </summary>
  const std::string entity_sprite_file = "./assets/characters.png";
  
  /// <summary>
  /// The pacman default sprite label.
  /// </summary>
  const std::string pacman_default = "pacman_default";
  
  /// <summary>
  /// The pacman moving anim 0
  /// </summary>
  const std::string pacman_moving_anim_0 = "pacman_moving_anim_0";
  
  /// <summary>
  /// The pacman moving anim 1
  /// </summary>
  const std::string pacman_moving_anim_1 = "pacman_moving_anim_1";
  
  /// <summary>
  /// The pacman moving animation label.
  /// </summary>
  const std::string pacman_moving_anim = "pacman_moving_anim";

  /// <summary>
  /// The pacman moving animation label.
  /// </summary>
  const std::string pacman_moving_anim_back = "pacman_moving_anim_back";
  
  /// <summary>
  /// The pacman dying animation label.
  /// </summary>
  const std::string pacman_dying_anim = "pacman_dying_anim";
  
  /// <summary>
  /// The ghost dead horizontal sprite label.
  /// </summary>
  const std::string ghost_dead_horizontal = "ghost_dead_horizontal";
  
  /// <summary>
  /// The ghost dead vertical sprite label.
  /// </summary>
  const std::string ghost_dead_vertical = "ghost_dead_vertical";
  
  /// <summary>
  /// The ghost scared animation label.
  /// </summary>
  const std::string ghost_scared_anim = "ghost_scared_anim";
  
  /// <summary>
  /// Ghost moving horizontal animation label.
  /// </summary>
  const std::string ghost_moving_horizontal_anim = "moving_horizontal_anim";  

  /// <summary>
  /// Ghost moving up animation label.
  /// </summary>
  const std::string ghost_moving_up_anim = "moving_up_anim";
  
  /// <summary>
  /// Ghost moving down animation label.
  /// </summary>
  const std::string ghost_moving_down_anim = "moving_down_anim";
    
  /// <summary>
  /// The entity tile size.
  /// </summary>
  const int entity_tile_size = 16;
}
}
}
