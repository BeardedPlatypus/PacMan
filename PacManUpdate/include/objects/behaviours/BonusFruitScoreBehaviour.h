#pragma once

#include "objects/behaviours/AbstractScoreBehaviour.h"
#include "level/ILevelManager.h"


namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="BonusFruitBehaviour"/> implements the scoring behaviour
/// of BonusFruit 
/// </summary>
/// <seealso cref="AbstractScoreBehaviour" />
class BonusFruitScoreBehaviour final : public AbstractScoreBehaviour {
public:
  BonusFruitScoreBehaviour(state::score::IScoreBoard* p_score_board,
                           const state::level::ILevelManager* p_level_manager);

protected:
  unsigned int GetScoreIncrement() const final;

  const state::level::ILevelManager* _p_level_manager;
};

}
}
}
