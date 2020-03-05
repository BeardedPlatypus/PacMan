#include "pch.h"
#include "objects/behaviours/AbstractScoreBehaviour.h"


namespace pacman {
namespace update {
namespace object {

AbstractScoreBehaviour::AbstractScoreBehaviour(state::score::IScoreBoard* p_score_board) :
    p_score_board(p_score_board) { }


void AbstractScoreBehaviour::Execute(IUpdatablePlayerEntity* _) {
  this->p_score_board->IncrementScore(this->GetScoreIncrement());
}

}
}
}