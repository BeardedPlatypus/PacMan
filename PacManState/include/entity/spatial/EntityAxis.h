#pragma once

#include "entity/spatial/IEntityAxis.h"


namespace pacman {
namespace state {

/// <summary>
/// <see cref="EntityAxis"/> provides a concrete implementation of the 
/// <see cref="IEntityAxis"/> interface.
/// </summary>
/// <seealso cref="IEntityAxis" />
class EntityAxis final : public IEntityAxis {
public:  
  /// <summary>
  /// Construct a new <see cref="EntityAxis" />.
  /// </summary>
  /// <param name="position">The position.</param>
  /// <postcondition>
  /// (new this)->GetPosition() == position;
  /// </postcondition>
  explicit EntityAxis(float position) : position(position) {}

  inline float GetPosition() const final { return this->position;  }
  void SetPosition(float position) final { this->position = position; }
private:  
  /// <summary>
  /// The position of this <see cref="EntityAxis"/>.
  /// </summary>
  float position;
};

}
}
