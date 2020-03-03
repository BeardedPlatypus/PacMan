#pragma once


#include "ui/font/IStringRenderData.h"

namespace pacman {
namespace renderer {
namespace ui {

class StaticStringRenderData final : public IStringRenderData {
public:  
  /// <summary>
  /// Creates a new <see cref="StaticStringRenderData"/>.
  /// </summary>
  /// <param name="string">The static string to render.</param>
  /// <param name="x">The x location to render at.</param>
  /// <param name="y">The y location to render at.</param>
  /// <param name="font_scale">The font scale.</param>
  /// <param name="justification">The justification.</param>
  StaticStringRenderData(const std::string& string,
                         float x, float y, float font_scale, 
                         Justification justification);

  inline const std::string GetString() const { return this->string; }
  inline float GetX() const { return this->x; }
  inline float GetY() const { return this->y; }
  inline float GetFontScale() const { return this->font_scale; }
  inline Justification GetJustification() const { return this->justification; }

private:
  const std::string string;
  float x;
  float y;
  float font_scale;
  Justification justification;
};

}
}
}
