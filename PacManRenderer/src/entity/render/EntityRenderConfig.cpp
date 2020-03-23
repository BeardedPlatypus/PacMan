#include "pch.h"
#include "entity/render/EntityRenderConfig.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

EntityRenderConfig::EntityRenderConfig(std::shared_ptr<IValueProvider<std::string>> label_provider,
                                       std::shared_ptr<IAnimationPositionProvider> position_provider,
                                       std::shared_ptr<IValueProvider<float>> scale_provider,
                                       std::shared_ptr<IValueProvider<float>> rotation_provider,
                                       std::shared_ptr<IValueProvider<bool>> flip_horizontally_provider,
                                       std::shared_ptr<IValueProvider<bool>> flip_vertically_provider) : 
    _label_provider(label_provider),
    _position_provider(position_provider),
    _scale_provider(scale_provider),
    _rotation_provider(rotation_provider),
    _flip_horizontally_provider(flip_horizontally_provider),
    _flip_vertically_provider(flip_vertically_provider) { }

}
}
}
}
