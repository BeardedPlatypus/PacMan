#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace state {
  
/// <summary>
/// <see cref="IEntityAxis"/> describes a position on an axis of an
/// entity.
/// </summary>
class DllExport IEntityAxis {
public:
  /// <summary>
  /// Get the world position on this <see cref="IEntityAxis"/>.
  /// </summary>
  /// <returns> 
  /// The world position on this <see cref="IEntityAxis"/>
  /// </returns>
  virtual float GetPosition() const = 0;

  /// <summary>
  /// Set the world position on this <see cref="IEntityAxis"/>.
  /// </summary>
  /// <param name="new_x">The new world position.</param>
  // <postcondition> 
  // | (new this)->GetPosition() == <paramref name="position" />
  // </postcondition>
  virtual void SetPosition(float position) = 0;
};

}
}
