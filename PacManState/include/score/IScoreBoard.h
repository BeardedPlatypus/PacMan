#pragma once

namespace pacman {
namespace state {
namespace score {

/// <summary>
/// <see cref="IScoreBoard"/> defines the interface with which to store the
/// score, increment it and reset it.
/// </summary>
class IScoreBoard {
public:  
  /// <summary>
  /// Gets the score.
  /// </summary>
  /// <returns>The current score.</returns>
  virtual unsigned int GetScore() const = 0;
  
  /// <summary>
  /// Increments the score by the specified <paramref cref="value"/>.
  /// </summary>
  /// <param name="value">The value.</param>
  /// <post-condition>
  /// | (new this)->GetValue() == this->GetValue() + value;
  /// </post-condition>
  virtual void IncrementScore(unsigned int value) = 0;
  
  /// <summary>
  /// Resets the score on this <see cref="IScoreBoard"/>.
  /// </summary>
  /// <post-condition>
  /// | (new this)->GetValue() == 0;
  /// </post-condition>
  virtual void Reset() = 0;
};

}
}
}
