#pragma once

#include "objects/behaviours/AbstractScoreBehaviour.h"


namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="SmallDotScoreBehaviour"/> implements the scoring behaviour
/// of small dots.
/// </summary>
/// <seealso cref="AbstractScoreBehaviour" />
class SmallDotScoreBehaviour final : public AbstractScoreBehaviour {
public:
  using AbstractScoreBehaviour::AbstractScoreBehaviour;

protected:
  unsigned int GetScoreIncrement() const final { return 10; }
};

}
}
}
