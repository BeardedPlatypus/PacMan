#pragma once
#include <IViewAPI.h>


namespace pacman {
namespace renderer {
namespace objects {

/// <summary>
/// <see cref="IObjectRenderer"/> provides the interface to render a specific
/// object with a provided <see cref="view::IViewAPI"/> at a specified location.
/// </summary>
class IObjectRenderer {
public:  
  /// <summary>
  /// Render the corresponding object of this <see cref="IObjectRenderer"/>.
  /// </summary>
  /// <param name="p_view_api"> The a pointer to the <see cref="IViewAPI"/>.</param>
  /// <param name="x"> The x tile index to render at. </param>
  /// <param name="y"> The y tile index to render at. </param>
  /// <param name="scale"> The scale to render with. </param>
  virtual void RenderObject(view::IViewAPI* p_view_api, int x, int y, float scale) const = 0;
};

}
}
}
