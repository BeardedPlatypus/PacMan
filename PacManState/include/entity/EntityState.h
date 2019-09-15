#pragma once
#define DllExport __declspec( dllexport )

#include "entity/IEntityState.h"


namespace pacman {
namespace state {

/// <summary>
/// <see cref="EntityState" /> implements <see cref="IEntityState" />.
/// </summary>
/// <seealso cref="IEntityState" />
class EntityState sealed : public IEntityState {
public:  
  /// <summary>
  /// Construct a new <see cref="EntityState"/>.
  /// </summary>
  /// <param name="x"> The world x position. </param>
  /// <param name="y"> The world y position. </param>
  /// <param name="dir"> The <see cref="Direction" />. </param>
  EntityState(float x, float y, Direction dir);

  float GetXPosition() const final;
  void SetXPosition(float new_x) final;

  float GetYPosition() const final;
  void SetYPosition(float new_y) final;

  Direction GetDirection() const final;
  void SetDirection(Direction direction) final;

private:    
  /// <summary>
  /// The x world position of this <see cref="EntityState" />.
  /// </summary>
  float x;

  /// <summary>
  /// The y world position of this <see cref="EntityState" />.
  /// </summary>
  float y;

  /// <summary>
  /// The <see cref="Direction" /> of this <see cref="EntityState" />.
  /// </summary>
  Direction dir;
};

}
}
