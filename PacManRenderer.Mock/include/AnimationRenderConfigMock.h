#pragma once

#include "entity/animation/IAnimationRenderConfig.h"
#include <gmock/gmock.h>


class AnimationRenderConfig : public pacman::renderer::entity::animation::IAnimationRenderConfig {
public:
  MOCK_METHOD(std::string, GetLabel, (), (const));
  MOCK_METHOD(void, Initialise, ());
  MOCK_METHOD(void, Update, (float));
  MOCK_METHOD(void, Reset, ());
};
