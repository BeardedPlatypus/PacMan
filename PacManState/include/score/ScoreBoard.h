#pragma once

#include "score/IScoreBoard.h"

namespace pacman {
namespace state {
namespace score {

/// <summary>
/// <see cref="ScoreBoard"/> implements the interface with which to store
/// the score, increment it, and reset it.
/// </summary>
class ScoreBoard final : public IScoreBoard {
public:  
  /// <summary>
  /// Create a new <see cref="ScoreBoard"/>.
  /// </summary>
  ScoreBoard() {}

  inline unsigned int GetScore() const final { return this->score; }
  inline void IncrementScore(unsigned int value) final { this->score += value; }
  inline void Reset() final { this->score = 0; }
private:  
  /// <summary>
  /// The current score.
  /// </summary>
  unsigned int score = 0;
};

}
}
}
