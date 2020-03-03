#include "pch.h"
#include "ui/font/ScoreBoardStringRenderData.h"


namespace pacman {
namespace renderer {
namespace ui {

ScoreBoardStringRenderData::ScoreBoardStringRenderData(const state::score::IScoreBoard* p_score_board, 
                                                       float x, float y, float font_scale,
                                                       Justification justification) :
    p_score_board(p_score_board),
    x(x),
    y(y),
    font_scale(font_scale),
    justification(justification) { }

}
}
}
