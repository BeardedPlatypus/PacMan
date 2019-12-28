#pragma once

#include <string>


namespace pacman {
namespace renderer {  
namespace values {
  /// <summary>
  /// The field sprite file 
  /// </summary>
  const std::string field_sprite_file = "./assets/field.png";
  
  /// <summary>
  /// The field sprite: straight 
  /// </summary>
  const std::string field_sprite_straight = "straight";
  
  /// <summary>
  /// The field sprite: corner
  /// </summary>
  const std::string field_sprite_corner = "corner";  

  /// <summary>
  /// The field sprite: end
  /// </summary>
  const std::string field_sprite_end = "end";
  
  /// <summary>
  /// The field sprite: junction
  /// </summary>
  const std::string field_sprite_junction = "junction";
  
  /// <summary>
  /// The field sprite gate: connect
  /// </summary>
  const std::string field_sprite_gate_connect = "gate_connect";
  
  /// <summary>
  /// The field sprite: gate
  /// </summary>
  const std::string field_sprite_gate = "gate";
  
  /// <summary>
  /// The tile size
  /// </summary>
  const int tile_size = 8;
}
}
}
