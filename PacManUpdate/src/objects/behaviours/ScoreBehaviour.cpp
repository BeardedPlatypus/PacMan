#include "pch.h"
#include "objects/behaviours/ScoreBehaviour.h"


namespace pacman {
namespace update {
namespace object {

ScoreBehaviour::ScoreBehaviour(unsigned int increment_value,
                               state::score::IScoreBoard* p_score_board) :
    increment_value(increment_value),
    p_score_board(p_score_board) { }


void ScoreBehaviour::Execute(IUpdatablePlayerEntity* _) {
  p_score_board->IncrementScore(this->increment_value);
}

}
}
}