#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "entity/IUpdatablePlayerEntity.h"
#include "IGameState.h"

#include <unordered_map>

namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="PortalBehaviour"/> defines the behaviour which transports an
/// entity from one location, defined as a FieldIndex, to another.
/// </summary>
/// <seealso cref="IObjectBehaviour" />
class PortalBehaviour : public IObjectBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="PortalBehaviour"/>.
  /// </summary>
  /// <param name="p_field"> 
  /// The field on which this behaviour is created. 
  /// </param>
  /// <param name="mapping">
  /// The portal mapping locations.
  /// </param>
  // <remarks>
  // The mappings are defined one way, as such, if a mapping A -> B
  // exist, and B -> A also needs to exist, it needs to be explicitly
  // defined.
  // </remarks>
  PortalBehaviour(const state::field::IField* p_field,
                  const std::unordered_map<int, int> mapping);
  
  /// <summary>
  /// If a portal exists at (<paramref name="x"/>, <paramref name="y"/>),
  /// then portal <paramref name="p_entity"/> to its corresponding location
  /// else nothing.
  /// </summary>
  /// <param name="p_entity">The <see cref="IUpdatablePlayerEntity" /> on which this behaviour should act.</param>
  /// <param name="x">The x location at which this behaviour is executed.</param>
  /// <param name="y">The y location at which this behaviour is executed.</param>
  void Execute(IUpdatablePlayerEntity* p_entity) override;

private:
  const state::field::IField* _p_field;

  const std::unordered_map<state::field::FieldIndex, state::field::FieldIndex> _portal_mapping;

  void MovePlayerTo(IUpdatablePlayerEntity* p_entity,
                    state::field::FieldIndex new_location);
};

}
}
}
