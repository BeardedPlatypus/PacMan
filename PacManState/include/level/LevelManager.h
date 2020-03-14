#pragma once

#include "level/ILevelManager.h"


namespace pacman {
namespace state {
namespace level {

/// <summary>
/// <see cref="LevelTracker" /> implements the behaviour to track the current level,
/// the current state of the level.
/// </summary>
/// <seealso cref="ILevelManager" />
class LevelManager final : public ILevelManager {
public:  
  /// <summary>
  /// Creates a new <see cref="LevelManager"/>.
  /// </summary>
  /// <param name="n_dots">The number of dots within the field.</param>
  explicit LevelManager(unsigned int n_dots);

  unsigned int GetCurrentLevel() const final;
  void IncrementCurrentLevel() final;
  unsigned int GetTotalNDots() const final;
  unsigned int GetDotsLeftInCurrentLevel() const final;
  unsigned int GetDotsConsumedInCurrentLevel() const final;
  void IncrementDotsConsumedInCurrentLevel() final;
private:
  unsigned int _current_level = 0;
  const unsigned int _total_n_dots;
  unsigned int _consumed_dots = 0;
};

}
}
}
