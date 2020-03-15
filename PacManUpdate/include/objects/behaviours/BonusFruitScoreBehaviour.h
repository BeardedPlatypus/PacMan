#pragma once

#include "objects/behaviours/AbstractScoreBehaviour.h"


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
  using AbstractScoreBehaviour::AbstractScoreBehaviour;

protected:
  unsigned int GetScoreIncrement() const final { return 100; }
};

}
}
}
