#pragma once

#include <entity/IEntityState.h>
#include <field/IField.h>


namespace pacman {
namespace update {

  /// <summary>
  /// Update the <paramref cref="p_player_state" /> given the 
  /// <paramref cref="p_field" /> and the passed time <paramref cref="dt" />.
  /// </summary>
  void UpdatePlayer(state::IEntityState* p_player_state,
                    state::field::IField* p_field,
                    float dt);

}
}
