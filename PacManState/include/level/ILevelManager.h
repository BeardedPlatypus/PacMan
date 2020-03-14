#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

namespace pacman {
namespace state {
namespace level {

/// <summary>
/// <see cref="ILevelTracker"/> defines the behaviour to track the current level,
/// the current state of the level.
/// </summary>
class DllExport ILevelManager {
public:  
  /// <summary>
  /// Constructs a new <see cref="ILevelTracker"/>.
  /// </summary>
  /// <returns></returns>
  static std::unique_ptr<ILevelManager> Construct(unsigned int n_dots);
  
  /// <summary>
  /// Gets the current level.
  /// </summary>
  /// <returns>
  /// The current level.
  /// </returns>
  virtual unsigned int GetCurrentLevel() const = 0;
  
  /// <summary>
  /// Increments the current level by one.
  /// </summary>
  /// <post-condition>
  /// | (new this)->GetCurrentLevel()               == this->GetCurrentLevel() + 1;
  /// | (new this)->GetDotsLeftInCurrentLevel()     == this->GetTotalNDots();
  /// | (new this)->GetDotsConsumedInCurrentLevel() == 0;
  /// </post-condition>
  virtual void IncrementCurrentLevel() = 0;
  
  /// <summary>
  /// Gets the total number of dots.
  /// </summary>
  /// <returns>
  /// The total number of dots
  /// </returns>
  virtual unsigned int GetTotalNDots() const = 0;
  
  /// <summary>
  /// Gets the dots left in the current level.
  /// </summary>
  /// <returns>
  /// The dots left in the current level.
  /// </returns>
  virtual unsigned int GetDotsLeftInCurrentLevel() const = 0;
  
  /// <summary>
  /// Gets the dots consumed in the current level.
  /// </summary>
  /// <returns>
  /// The dots consumed in the current level
  /// </returns>
  virtual unsigned int GetDotsConsumedInCurrentLevel() const = 0;
  
  /// <summary>
  /// Increments the dots consumed in current level.
  /// </summary>
  /// <post-condition>
  /// | (new this)->GetDotsConsumedInCurrentLevel() == this->GetDotsConsumedInCurrentLevel() + 1;
  /// | (new this)->GetDotsLeftInCurrentLevel() == this->GetDotsLeftInCurrentLevel() - 1;
  /// </post-condition>
  virtual void IncrementDotsConsumedInCurrentLevel() = 0;
};

}
}
}
