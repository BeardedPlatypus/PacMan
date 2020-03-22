#pragma once

#include <unordered_map>

#include "entity/render/IAnimationLabelProvider.h"
#include "entity/render/GetDirectionContainer.h"

#include "util/EnumClassHash.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="DirectionBasedAnimationLabelProvider"/> provides the current active animation label
/// by querying the current direction and using the provided mapping to determine an active label.
/// If no label can be found in the provided mapping the default label will be obtained.
/// </summary>
/// <seealso cref="IAnimationLabelProvider" />
class DirectionBasedAnimationLabelProvider final : public IAnimationLabelProvider {
public:  
  /// <summary>
  /// Creates new <see cref="DirectionBasedAnimationLabelProvider"/>.
  /// </summary>
  /// <param name="_p_direction_container">A pointer to the observed <see cref="GetDirectionContainer"/>.</param>
  /// <param name="default_label">The default label.</param>
  /// <param name="p_mapping">The mapping of direction to labels.</param>
  DirectionBasedAnimationLabelProvider(std::unique_ptr<GetDirectionContainer> p_direction_container,
                                       const std::string& default_label,
                                       std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> p_mapping);

  const std::string& GetActiveAnimationLabel() const final;

private:
  std::unique_ptr<GetDirectionContainer> _p_direction_container;
  std::string _default_label;
  std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> _p_mapping;
};

}
}
}
}
