#pragma once

#include "IControllerCommand.h"
#include <entity/IEntityState.h>
#include <optional>
#include "entity/IPlayerMovementAxis.h"
#include "state_machine/events/PlayerControlEvent.h"

namespace pacman {
namespace update {
namespace commands {
  
/// <summary>
/// The <see cref="ChangePlayerDirectionCommand" /> sets the <see cref="state::Direction" /> of the
/// player's <see cref="IEntityState" />.
/// </summary>
/// <seealso cref="controller::ICommand" />
class ChangePlayerDirectionCommand final : public controller::api::IControllerCommand {
public:  
  /// <summary>
  /// Construct a new <see cref="ChangePlayerDirectionCommand"/>.
  /// </summary>
  /// <param name="p_axis">Pointer to the relevant <see cref="IPlayerMovmentAxis"/>.</param>
  /// <param name="direction_changed_event"/>The event with which the axis should be changed.</param>
  ChangePlayerDirectionCommand(IPlayerMovementAxis* p_axis,
                               state_machine::PlayerControlEvent direction_changed_event);

  void Execute() final;

private:    
  /// <summary>
  /// A pointer to the relevant axis this command changes.
  /// </summary>
  IPlayerMovementAxis* p_movement_axis;

  /// <summary>
  /// The event with which the axis should be changed.
  /// </summary>
  state_machine::PlayerControlEvent direction_changed_event;
};


/// <summary>
/// Get a new command which changes the direction of the provided 
/// <paramref cref="p_axis"/> to the provided 
/// <paramref cref="direction"/> when executed.
/// </summary>
/// <param name="p_axis"/>A pointer to the axis to be updated.</param>
/// <param name="direction_changed_event"/>The event with which the axis should be changed.</param>
/// <returns>
/// An <see cref="controller::ICommand"/> which changes the direction 
/// of the provided player state.
/// </returns>
std::unique_ptr<controller::api::IControllerCommand> GetChangePlayerDirectionCommand(IPlayerMovementAxis* p_axis,
                                                                                     state_machine::PlayerControlEvent direction_changed_event);

}
}
}

