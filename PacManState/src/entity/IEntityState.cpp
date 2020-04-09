#include "stdafx.h"
#include "entity/IEntityState.h"
#include "entity/EntityState.h"

#include "entity/player/IPacManBehaviourState.h"


namespace pacman {
namespace state {

template <typename T>
std::unique_ptr<IEntityState<T>> IEntityState<T>::Construct(std::unique_ptr<ISpatialState> p_spatial_state,
                                                            std::unique_ptr<T> p_behavioural_state) {
  return std::make_unique<EntityState<T>>(std::move(p_spatial_state),
                                          std::move(p_behavioural_state));
}

template class IEntityState<IPacManBehaviourState>;

}
}
