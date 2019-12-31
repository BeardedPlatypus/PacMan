#pragma once

#include "manager/ILayerManager.h"
#include "IRenderLayer.h"

#include <memory>
#include <vector>

namespace pacman {
namespace renderer {

class LayerManager final : public ILayerManager {
public:
  explicit LayerManager(std::vector<std::unique_ptr<IRenderLayer>>& render_layers);
  
  void Initialise() final;
  void Update(float d_time) final;
  void Render() const final;

private:
  std::vector<std::unique_ptr<IRenderLayer>> _render_layers = 
    std::vector<std::unique_ptr<IRenderLayer>>();
};

}
}
