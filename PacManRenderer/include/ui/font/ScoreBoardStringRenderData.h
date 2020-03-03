#pragma once

#include <score/IScoreBoard.h>

#include "ui/font/IStringRenderData.h"

namespace pacman {
namespace renderer {
namespace ui {

class ScoreBoardStringRenderData final : public IStringRenderData {
public:  
  /// <summary>
  /// Creates a new <see cref="ScoreBoardStringRenderData"/>.
  /// </summary>
  /// <param name="p_score_board">A pointer to the observed <see cref="state::score::IScoreBoard"/>.</param>
  /// <param name="x">The x location to render at.</param>
  /// <param name="y">The y location to render at.</param>
  /// <param name="font_scale">The font scale.</param>
  /// <param name="justification">The justification.</param>
  ScoreBoardStringRenderData(const state::score::IScoreBoard* p_score_board,
                             float x, float y, float font_scale,
                             Justification justification);

  inline const std::string GetString() const { return std::to_string(this->p_score_board->GetScore()); }
  inline float GetX() const { return this->x; }
  inline float GetY() const { return this->y; }
  inline float GetFontScale() const { return this->font_scale; }
  inline Justification GetJustification() const { return this->justification; }

private:
  const state::score::IScoreBoard* p_score_board;
  float x;
  float y;
  float font_scale;
  Justification justification;
};

}
}
}
