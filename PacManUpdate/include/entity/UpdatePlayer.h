#pragma once

#include <field/IField.h>

#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {
  void UpdatePlayerDirection(IUpdatablePlayerEntity* p_player_entity,
                             state::field::IField* p_field);


  /// <summary>
  /// Update the <paramref cref="p_player_state" /> given the 
  /// <paramref cref="p_field" /> and the passed time <paramref cref="dt" />.
  /// </summary>
  void UpdatePlayerLocation(IUpdatablePlayerEntity* p_player_entity,
                            state::field::IField* p_field,
                            float dt);

}
}
