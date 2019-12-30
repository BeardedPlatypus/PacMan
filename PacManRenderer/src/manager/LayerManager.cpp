#include "pch.h"
#include "manager/LayerManager.h"


namespace pacman {
namespace renderer {

LayerManager::LayerManager(std::vector<std::unique_ptr<IRenderLayer>>& render_layers) {
  for (size_t i = 0; i < render_layers.size(); i++) {
    this->_render_layers.push_back(std::move(render_layers[i]));
  }
}


void LayerManager::Initialise() {
  for (size_t i = 0; i < this->_render_layers.size(); i++) {
    this->_render_layers[i]->Initialise();
  }
}


void LayerManager::Update(float d_time) {
  for (size_t i = 0; i < this->_render_layers.size(); i++) {
    this->_render_layers[i]->Update(d_time);
  }
}


void LayerManager::Render() const {
  for (size_t i = 0; i < this->_render_layers.size(); i++) {
    this->_render_layers[i]->Render();
  }
}


}
}