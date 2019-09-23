#pragma once

#include <memory>
#include <entity/IEntityAxis.h>

namespace pacman {
namespace update {

class IUpdatableEntityAxis {
public:
  static std::unique_ptr<IUpdatableEntityAxis> Construct(state::IEntityAxis* p_axis);

  virtual ~IUpdatableEntityAxis() {}

  virtual float GetPosition() const = 0;
  virtual int GetCurrentIndex() const = 0;
  virtual int GetPreviousIndex() const = 0;

  virtual void Move(float d_pos) = 0;
};

}
}
