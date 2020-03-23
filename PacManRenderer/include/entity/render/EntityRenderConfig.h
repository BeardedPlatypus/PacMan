#pragma once

#include <memory>
#include <string>

#include "entity/render/IValueProvider.h"
#include "entity/render/IAnimationPositionProvider.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="EntityRenderConfig"/> provides a container for the different 
/// providers required to render an entity.
/// </summary>
class EntityRenderConfig {
public:  
  /// <summary>
  /// Creates a new <see cref="EntityRenderConfig"/>.
  /// </summary>
  /// <param name="label_provider">The label provider.</param>
  /// <param name="position_provider">The position provider.</param>
  /// <param name="scale_provider">The scale provider.</param>
  /// <param name="rotation_provider">The rotation provider.</param>
  /// <param name="flip_horizontally_provider">The flip horizontally provider.</param>
  /// <param name="flip_vertically_provider">The flip vertically provider.</param>
  EntityRenderConfig(std::shared_ptr<IValueProvider<std::string>> label_provider,
                     std::shared_ptr<IAnimationPositionProvider> position_provider,
                     std::shared_ptr<IValueProvider<float>> scale_provider,
                     std::shared_ptr<IValueProvider<float>> rotation_provider,
                     std::shared_ptr<IValueProvider<bool>> flip_horizontally_provider,
                     std::shared_ptr<IValueProvider<bool>> flip_vertically_provider);
  
  /// <summary>
  /// Gets the label provider.
  /// </summary>
  /// <returns> The label provider. </returns>
  inline IValueProvider<std::string>* GetLabelProvider() const { return this->_label_provider.get(); }
  
  /// <summary>
  /// Gets the position provider.
  /// </summary>
  /// <returns>The position provider.</returns>
  inline IAnimationPositionProvider* GetPositionProvider() const { return this->_position_provider.get(); }
  
  /// <summary>
  /// Gets the scale provider.
  /// </summary>
  /// <returns>The scale provider.</returns>
  inline IValueProvider<float>* GetScaleProvider() const { return this->_scale_provider.get(); }
  
  /// <summary>
  /// Gets the rotation provider.
  /// </summary>
  /// <returns>The rotation provider.</returns>
  inline IValueProvider<float>* GetRotationProvider() const { return this->_rotation_provider.get(); }
  
  /// <summary>
  /// Gets the flip horizontally provider.
  /// </summary>
  /// <returns>The flip horizontally provider.</returns>
  inline IValueProvider<bool>* GetFlipHorizontallyProvider() const { return this->_flip_horizontally_provider.get(); }
  
  /// <summary>
  /// Gets the flip vertically provider.
  /// </summary>
  /// <returns>The flip vertically provider.</returns>
  inline IValueProvider<bool>* GetFlipVerticallyProvider() const { return this->_flip_vertically_provider.get(); }

private:
  std::shared_ptr<IValueProvider<std::string>> _label_provider;
  std::shared_ptr<IAnimationPositionProvider> _position_provider;
  std::shared_ptr<IValueProvider<float>> _scale_provider;
  std::shared_ptr<IValueProvider<float>> _rotation_provider;
  std::shared_ptr<IValueProvider<bool>> _flip_horizontally_provider;
  std::shared_ptr<IValueProvider<bool>> _flip_vertically_provider;
};

}
}
}
}
