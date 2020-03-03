#include "pch.h"
#include "ui/font/StaticStringRenderData.h"


namespace pacman {
namespace renderer {
namespace ui {

StaticStringRenderData::StaticStringRenderData(const std::string& string, 
                                               float x, float y, float font_scale,
                                               Justification justification) :
    string(string),
    x(x),
    y(y),
    font_scale(font_scale),
    justification(justification) { }

}
}
}
