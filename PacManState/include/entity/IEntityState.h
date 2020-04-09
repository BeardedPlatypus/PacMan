#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include "entity/spatial/ISpatialState.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="IEntityState"/> describes the spatial and behavioural state of 
/// an entity.
/// </summary>
/// <typeparam name="TBehaviouralState">The behavioural state of the <see cref="IEntityState"/>.</typeparam>
template <typename TBehaviouralState>
class DllExport IEntityState {
public:    
  /// <summary>
  /// Constructs a new <see cref="IEntityState{TBehaviourialState}"/>.
  /// </summary>
  /// <param name="p_spatial_state">A pointer to the <see cref="ISpatialState"/>.</param>
  /// <param name="p_behavioural_state">A pointer to the <see cref="TBehaviouralState"/>.</param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the new 
  /// <see cref="IEntityState{TBehaviouralState}"/>.
  /// </returns>
  static std::unique_ptr<IEntityState<TBehaviouralState>> Construct(std::unique_ptr<ISpatialState> p_spatial_state,
                                                                    std::unique_ptr<TBehaviouralState> p_behavioural_state);

  /// <summary>
  /// Gets the <see cref="ISpatialState"/> of this <see cref="IEntityState"/>.
  /// </summary>
  /// <returns>
  /// A pointer to the <see cref="ISpatialState"/> of this <see cref="IEntityState"/>.
  /// </returns>
  virtual ISpatialState* GetSpatialState() const = 0;
  
  /// <summary>
  /// Gets the <typeparamref cref="TBehaviouralState"/> of this <see cref="IEntityState"/>.
  /// </summary>
  /// <returns>
  /// The <typeparamref cref="TBehaviouralState"/>.
  /// </returns>
  virtual TBehaviouralState* GetBehaviouralState() const = 0;
};

}
}
