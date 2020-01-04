#pragma once

#include <field/IField.h>

#include "entity/UpdatablePlayerEntity.h"
#include "objects/BehaviourManager.h"


namespace pacman {
namespace update {
  /// <summary>
  /// Update the location and orientation of the 
  /// <paramref name="p_player_entity"/>, given the <paramref name="p_field"/>
  /// and time passed <paramref name="dt"/>.
  /// </summary>
  /// <param name="p_player_entity"/>
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be updated.
  /// </param>
  /// <param name="p_field"/>
  /// A pointer to the <see cref="IField"/> that the 
  /// <paramref name="p_player_entity"/> exists in.
  /// </param>
  /// <param name="dt"/> The time that has passed since the last update. </param>
  /// <precondition>
  /// | p_player_entity != null_ptr
  /// | p_field != null_ptr
  /// | dt >= 0.F
  /// </precondition>
  void UpdatePlayerLocation(IUpdatablePlayerEntity* p_player_entity,
                            const state::field::IField* p_field,
                            object::BehaviourManager* p_behaviour_manager,
                            float dt);

}
}
