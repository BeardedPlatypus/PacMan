#pragma once

#include "objects/behaviours/AbstractScoreBehaviour.h"


namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="BigDotScoreBehaviour"/> implements the scoring behaviour
/// of big dots.
/// </summary>
/// <seealso cref="AbstractScoreBehaviour" />
class BigDotScoreBehaviour final : public AbstractScoreBehaviour {
public:
  using AbstractScoreBehaviour::AbstractScoreBehaviour;

protected:
  unsigned int GetScoreIncrement() const final { return 50; }
};

}
}
}
