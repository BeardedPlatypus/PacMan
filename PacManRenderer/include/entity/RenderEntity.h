#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "entity/IRenderEntity.h"
#include "entity/IEntityStateRenderer.h"
#include "entity/render/IValueProvider.h"
#include "util/EnumClassHash.h"


namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="RenderEntity{TState}"/> defines a render entity that has TState
/// as an internal state. For each state a <see cref="IEntityStateRender"/> should be
/// defined. <see cref="RenderEntity"/> ensures that the correct state is rendered given
/// a <see cref="IValueProvider{TState}"/>.
/// </summary>
template <typename TState>
class RenderEntity final : public IRenderEntity {
public:  
  /// <summary>
  /// Creates a new <see cref="RenderEntity"/>.
  /// </summary>
  /// <param name="p_renderers">The renderers used to render.</param>
  /// <param name="p_active_state_provider">The active state provider.</param>
  RenderEntity(std::unique_ptr<std::unordered_map<TState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers,
               std::unique_ptr<render::IValueProvider<TState>> p_active_state_provider) :
    _p_renderers(std::move(p_renderers)), 
    _p_active_state_provider(std::move(p_active_state_provider)) { }

  void Initialise() final {
    for (auto& val : *_p_renderers)
      val.second->Initialise();
  }

  void Update(float dtime) final {

    TState current_state = this->_p_active_state_provider->GetValue();

    if (current_state != this->_prev_state) {
      this->_p_renderers->at(current_state)->Reset();
      this->_prev_state = current_state;
    }
  
    this->_p_renderers->at(current_state)->Update(dtime);
  }

  void Render(float scale,
              float render_offset_y) const final {
    this->_p_renderers->at(this->_p_active_state_provider->GetValue())->Render(scale, render_offset_y);
  }

private:
  std::unique_ptr<std::unordered_map<TState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> _p_renderers;
  std::unique_ptr<render::IValueProvider<TState>> _p_active_state_provider;
  TState _prev_state;
};

}
}
}
