#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "score/IScoreBoard.h"

namespace pacman {
namespace update {
namespace object {

class ScoreBehaviour final : public IObjectBehaviour {
public:  
  /// <summary>
  /// Construct a new <see cref="ScoreBehaviour"/>.
  /// </summary>
  /// <param name="increment_value">The increment value.</param>
  /// <param name="p_score_board">A pointer to the <see cref="state::score::IScoreBoard"/> to increment.</param>
  ScoreBehaviour(unsigned int increment_value,
                 state::score::IScoreBoard* p_score_board);

  void Execute(IUpdatablePlayerEntity* p_entity) final;

private:
  const unsigned int increment_value;

  state::score::IScoreBoard* p_score_board;
};

}
}
}
