#pragma once
#define DllExport __declspec( dllexport )

#include "entity/IEntityState.h"
#include "entity/EntityAxis.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="EntityState" /> implements <see cref="IEntityState" />.
/// </summary>
/// <seealso cref="IEntityState" />
class EntityState sealed : public IEntityState {
public:  
  /// <summary>
  /// Construct a new <see cref="EntityState" />.
  /// </summary>
  /// <param name="x">The world x position.</param>
  /// <param name="y">The world y position.</param>
  /// <param name="dir">The <see cref="Direction" />.</param>
  /// <param name="speed">The speed.</param>
  EntityState(float x, float y, Direction dir, float speed);

  IEntityAxis* GetXAxis() const final;
  IEntityAxis* GetYAxis() const final;

  Direction GetDirection() const final;
  void SetDirection(Direction direction) final;

  float GetSpeed() const final;
  void SetSpeed(float speed) final;

private:      
  /// <summary>
  /// The x axis
  /// </summary>
  EntityAxis x_axis;  

  /// <summary>
  /// The y axis
  /// </summary>
  EntityAxis y_axis;

  /// <summary>
  /// The <see cref="Direction" /> of this <see cref="EntityState" />.
  /// </summary>
  Direction dir;
  
  /// <summary>
  /// The speed of this <see cref="EntityState" />.
  /// </summary>
  float speed;
};

}
}
