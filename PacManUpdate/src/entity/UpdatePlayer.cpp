#include "pch.h"
#include "entity/UpdatePlayer.h"
#include "entity/util/PlayerUpdateUtils.h"


namespace pacman {
  namespace update {


void UpdatePlayerLocation(IUpdatablePlayerEntity* p_player_entity,
                          const state::field::IField* p_field,
                          float dt) {
  if (!util::IsActive(p_player_entity)) {
    return;
  }

  float distance_to_move = p_player_entity->GetSpeed() * dt;

  if (util::ShouldUpdateDirectionActiveAxis(p_player_entity)) {
    util::UpdateDirectionActiveAxis(p_player_entity);
    util::UpdateDirection(p_player_entity);
  }
  else if (util::HasOtherDirection(p_player_entity)) {
    float distance_to_previous_center = util::GetDistanceToPreviousCenter(p_player_entity);
    float distance_to_next_center = util::GetDistanceToNextCenter(p_player_entity);

    if (distance_to_previous_center <= 0.025F &&
        util::CanMoveInNextDirectionAtPreviousTileCenter(p_player_entity, p_field)) {

      distance_to_move += distance_to_previous_center;

      util::MoveOnActiveAxis(p_player_entity, 
                             distance_to_previous_center,
                             true);
      p_player_entity->SwapActiveAxis();
      util::UpdateDirection(p_player_entity);
    } 
    else if (distance_to_move > ( distance_to_next_center + 0.025F ) &&
             util::CanMoveInNextDirectionAtNextTileCenter(p_player_entity, p_field)) {

      distance_to_move -= distance_to_next_center;

      util::MoveOnActiveAxis(p_player_entity,
                             distance_to_next_center);
      p_player_entity->SwapActiveAxis();
      util::UpdateDirection(p_player_entity);
    }
  }

  util::ConditiallyMoveDistance(p_player_entity,
                                p_field,
                                distance_to_move);

  // Portal if necessary
  if (p_player_entity->GetXAxis()->GetPosition() > (float)p_field->GetXDimension() - 2.5F &&
      p_player_entity->GetMovingDirection() == state::Direction::Right) {
    p_player_entity->GetXAxis()->Move(-1.F * p_field->GetXDimension() + 3.5F);
  }
  else if (p_player_entity->GetXAxis()->GetPosition() < 2.5F &&
           p_player_entity->GetMovingDirection() == state::Direction::Left) {
    p_player_entity->GetXAxis()->Move(p_field->GetXDimension() - 3.5F);
  }
}

}
}
