#pragma once

#include <memory>
#include <entity/IEntityAxis.h>

namespace pacman {
namespace update {
  
/// <summary>
/// <see cref="IUpdatableEntityAxis"/> wraps the
/// <see cref="state::IEntityAxis"/> and defines an additional
/// current and previous index, as well as a move method.
/// </summary>
class IUpdatableEntityAxis {
public:  
  /// <summary>
  /// Construct a new <see cref="IUpdatableEntityAxis"/> with the given
  /// <paramref name="p_axis"/>.
  /// </summary>
  /// <param name="p_axis">The <see cref="state::IEntityAxis"/> being wrapped.</param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the constructed 
  /// <see cref="IUpdatableEntityAxis"/>.
  /// </returns>
  static std::unique_ptr<IUpdatableEntityAxis> Construct(state::IEntityAxis* p_axis);

  virtual ~IUpdatableEntityAxis() {}
  
  /// <summary>
  /// Get the position on this <see cref="IUpdatableEntityAxis"/>.
  /// </summary>
  /// <returns>
  /// The position on this <see cref="IUpdatableEntityAxis"/>.
  /// </returns>
  virtual float GetPosition() const = 0;
  
  /// <summary>
  /// Get the current index of the tile that the position on this 
  /// <see cref="IUpdatableEntityAxis"/> corresponds with.
  /// </summary>
  /// <returns>The current index of the tile.</returns>
  virtual int GetCurrentIndex() const = 0;
  
  /// <summary>
  /// Get the the index of this <see cref="IUpdatableEntityAxis"/> before the 
  /// last <see cref="Move"/> call.
  /// </summary>
  /// <returns>
  /// The index of this <see cref="IUpdatableEntityAxis"/> before the last
  /// <see cref="Move"/> call.
  /// </returns>
  virtual int GetPreviousIndex() const = 0;
  
  /// <summary>
  /// Move the position of this <see cref="IUpdatableEntityAxis" /> by
  /// the specific <paramref name="d_pos" />.
  /// </summary>
  /// <param name="d_pos">The d position.</param>
  /// <postcondition>
  /// | (new this)->GetPosition() == this->GetPosition() + d_Pos;
  /// </postcondition>
  virtual void Move(float d_pos) = 0;
};

}
}