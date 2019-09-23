#pragma once

#include "entity/IEntityAxis.h"


namespace pacman {
namespace state {

class EntityAxis final : public IEntityAxis {
public:  
  /// <summary>
  /// Construct a new <see cref="EntityAxis" />.
  /// </summary>
  /// <param name="position">The position.</param>
  /// <postcondition>
  /// (new this)->GetPosition() == position;
  /// </postcondition>
  EntityAxis(float position) : position(position) {}

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
