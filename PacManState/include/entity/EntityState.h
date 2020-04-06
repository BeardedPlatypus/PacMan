#pragma once

#include "entity/IEntityState.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="EntityState"/> implements the spatial and behavioural state of 
/// an entity.
/// </summary>
/// <typeparam name="TBehaviouralState">The behavioural state of the <see cref="IEntityState"/>.</typeparam>
template <typename TBehaviouralState>
class EntityState final : public IEntityState<TBehaviouralState> {
public:  
  /// <summary>
  /// Creates a new <see cref="EntityState"/>.
  /// </summary>
  /// <param name="p_spatial_state">A pointer to the <see cref="ISpatialState"/>.</param>
  /// <param name="p_behavioural_state">A pointer to the <see cref="TBehaviouralState"/>.</param>
  EntityState(std::unique_ptr<ISpatialState> p_spatial_state,
              std::unique_ptr<TBehaviouralState> p_behavioural_state) :
      _p_spatial_state(std::move(p_spatial_state)),
      _p_behavioural_state(std::move(p_behavioural_state)) { }

  ISpatialState* GetSpatialState() const final {
    return this->_p_spatial_state.get();

  }
  
  TBehaviouralState* GetBehaviouralState() const final {
    return this->_p_behavioural_state.get();
  }

private:
  std::unique_ptr<ISpatialState> _p_spatial_state;
  std::unique_ptr<TBehaviouralState> _p_behavioural_state;
};

}
}
