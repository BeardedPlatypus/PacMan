#include "pch.h"
#include "entity/IUpdatablePlayerEntity.h"
#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {

std::unique_ptr<IUpdatablePlayerEntity> IUpdatablePlayerEntity::Construct(state::ISpatialState* p_player_state) {

  return std::make_unique<UpdatablePlayerEntity>(p_player_state,
                                                 IUpdatableEntityAxis::Construct(p_player_state->GetXAxis()), 
                                                 IUpdatableEntityAxis::Construct(p_player_state->GetYAxis()),
                                                 IPlayerMovementAxis::Construct(),
                                                 IPlayerMovementAxis::Construct());
}

}
}
