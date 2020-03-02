#include "stdafx.h"
#include "score/IScoreBoard.h"
#include "score/ScoreBoard.h"

namespace pacman {
namespace state {
namespace score {

std::unique_ptr<IScoreBoard> IScoreBoard::Construct() {
  return std::make_unique<ScoreBoard>();
}

}
}
}
