#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "score/IScoreBoard.h"

namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="AbstractScoreBehaviour"/> provides the generic
/// implementation for scoring. Child class should implement the
/// GetScoreIncrement, for the behaviour to work correctly.
/// </summary>
/// <seealso cref="IObjectBehaviour" />
class AbstractScoreBehaviour : public IObjectBehaviour {
public:  
  /// <summary>
  /// Construct a new <see cref="AbstractScoreBehaviour"/>.
  /// </summary>
  /// <param name="p_score_board">A pointer to the <see cref="state::score::IScoreBoard"/> to increment.</param>
  explicit AbstractScoreBehaviour(state::score::IScoreBoard* p_score_board);

  void Execute(IUpdatablePlayerEntity* p_entity) override;

protected:  
  /// <summary>
  /// Gets the score increment.
  /// </summary>
  /// <returns>The score increment</returns>
  virtual unsigned int GetScoreIncrement() const = 0;

private:
  state::score::IScoreBoard* p_score_board;
};

}
}
}
