#pragma once
#define DllExport __declspec( dllexport )

#include "entity/ISpatialState.h"

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
