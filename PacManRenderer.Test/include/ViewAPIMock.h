#pragma once

#include "IViewAPI.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>


class ViewAPI : public pacman::view::IViewAPI {
public:
  MOCK_METHOD(void, Initialise, (int, int));
  MOCK_METHOD(void, RequestSprite, ((const std::string&),
                                    (const std::string&),
                                    int, int, int, int));
  MOCK_METHOD(void, RequestSprite, ((const std::string&),
                                    (const std::string&)));
  MOCK_METHOD(void, RequestSpriteAnimation, ((const std::string&),
                                             float,
                                             (const std::vector<std::string>&)));
  MOCK_METHOD(float, GetAnimationTime, ((const std::string&)));
  MOCK_METHOD(void, UpdateAnimation, ((const std::string&), float));
  MOCK_METHOD(void, SetAnimationToTime, ((const std::string&), float));
  MOCK_METHOD(void, ResetAnimationTime, ((const std::string&)));
  MOCK_METHOD(void, InitialiseRender, ());
  MOCK_METHOD(void, RenderSprite, ((const std::string&),
                                   float,
                                   float,
                                   float,
                                   float,
                                   bool,
                                   bool));
  MOCK_METHOD(void, RenderSpriteAnimation, ((const std::string&),
                                            float,
                                            float,
                                            float,
                                            float,
                                            bool,
                                            bool));
  MOCK_METHOD(void, FinaliseRender, ());
};

