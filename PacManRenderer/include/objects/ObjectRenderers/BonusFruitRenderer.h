#pragma once
#include "objects/ObjectRenderers/IObjectRenderer.h"
#include <level/ILevelManager.h>


namespace pacman {
namespace renderer {
namespace objects {

/// <summary>
/// <see cref="BonusFruitRenderer"/> implements <see cref="IObjectRenderer"/> for
/// the rendering of the bonus.
/// </summary>
/// <seealso cref="IObjectRenderer" />
class BonusFruitRenderer final : public IObjectRenderer {
public:
  /// <summary>
  /// Create a new <see cref="BonusFruitRenderer" />.
  /// </summary>
  /// <param name="p_view_api">A pointer to the <see cref="view::IViewAPI" />.</param>
  /// <param name="p_level_manager">A pointer to the <see cref="state::level::ILevelManager" />.</param>
  explicit BonusFruitRenderer(view::IViewAPI* p_view_api,
                              const state::level::ILevelManager* p_level_manager);

  void Initialise() final;

  void RenderObject(int x, int y, float scale, float render_offset_y) const final;

private:
  const std::string& GetBonusFruitSprite() const;
  float CalculateLocation(int val, float scale) const;

  view::IViewAPI* _p_view_api;
  const state::level::ILevelManager* _p_level_manager;
};

}
}
}
