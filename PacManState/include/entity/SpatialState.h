#pragma once
#define DllExport __declspec( dllexport )

#include "entity/ISpatialState.h"
#include "entity/EntityAxis.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="SpatialState" /> implements <see cref="ISpatialState" />.
/// </summary>
/// <seealso cref="ISpatialState" />
class SpatialState sealed : public ISpatialState {
public:  
  /// <summary>
  /// Construct a new <see cref="SpatialState" />.
  /// </summary>
  /// <param name="x">The world x position.</param>
  /// <param name="y">The world y position.</param>
  /// <param name="dir">The <see cref="Direction" />.</param>
  /// <param name="speed">The speed.</param>
  SpatialState(float x, float y, Direction dir, float speed);

  IEntityAxis* GetXAxis() const final;
  IEntityAxis* GetYAxis() const final;

  Direction GetDirection() const final;
  void SetDirection(Direction direction) final;

  float GetSpeed() const final;
  void SetSpeed(float speed) final;

  bool IsMoving() const final;
  void SetIsMoving(bool is_moving) final;

  void Reset() final;
private:      
  /// <summary>
  /// The x axis
  /// </summary>
  EntityAxis _x_axis;  

  /// <summary>
  /// The y axis
  /// </summary>
  EntityAxis _y_axis;

  /// <summary>
  /// The <see cref="Direction" /> of this <see cref="SpatialState" />.
  /// </summary>
  Direction _dir;
  
  /// <summary>
  /// The speed of this <see cref="SpatialState" />.
  /// </summary>
  float _speed;

  bool _is_moving = false;

  const float _initial_pos_x;
  const float _initial_pos_y;
  const Direction _initial_dir;
  const float _initial_speed;
};

}
}
