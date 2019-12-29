#include "KeyboardEventMock.h"
#include "SystemEventMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <event/EventGeneratorHelper.h>
#include <event/IEventParser.h>
#include <event/IEventStore.h>

#pragma region using_statements
using ::testing::IsTrue;
using ::testing::IsFalse;
using ::testing::NotNull;
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace controller {


struct EGHTVCValues {
  EGHTVCValues(SDL_EventType et, SDL_Scancode sc) : event_type(et), scancode(sc) {}

  SDL_EventType event_type;
  SDL_Scancode scancode;
};


class EventGeneratorHelperTestCanConvert :  public ::testing::TestWithParam<EGHTVCValues> { };


TEST_P(EventGeneratorHelperTestCanConvert, CanConvertSdlEvent_ValidKeyEventWithValidScancode) {
  // Given a SDL_event
  EGHTVCValues val = GetParam();

  SDL_Event sdl_event;
  sdl_event.type = val.event_type;
  sdl_event.key.keysym.scancode = val.scancode;

  // When
  bool result = EventGeneratorHelper::CanConvertSdlEvent(&sdl_event);

  // Then
  ASSERT_THAT(result, IsTrue());
}


INSTANTIATE_TEST_SUITE_P(CanConvertSdlEvent_ValidKeyEventWithValidScancode,
                         EventGeneratorHelperTestCanConvert,
						             ::testing::Values(EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_W), 
                                           EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_W),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_A),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_A),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_S),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_S),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_D),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_D),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_ESCAPE),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_ESCAPE),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_UP),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_UP),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_LEFT),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_LEFT),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_DOWN),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_DOWN),
										                       EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_RIGHT),
										                       EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_RIGHT)));



class EventGeneratorHelperTestCanConvertInvalid :  public ::testing::TestWithParam<EGHTVCValues> { };


TEST_P(EventGeneratorHelperTestCanConvertInvalid, CanConvertSdlEvent_ValidKeyEventWithInvalidScancode) {
  // Given a SDL_event
  EGHTVCValues val = GetParam();

  SDL_Event sdl_event;
  sdl_event.type = val.event_type;
  sdl_event.key.keysym.scancode = val.scancode;

  // When
  bool result = EventGeneratorHelper::CanConvertSdlEvent(&sdl_event);

  // Then
  ASSERT_THAT(result, IsFalse());
}


INSTANTIATE_TEST_SUITE_P(CanConvertSdlEvent_ValidKeyEventWithInvalidScancode,
                         EventGeneratorHelperTestCanConvertInvalid,
                         ::testing::Values(EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_1),
                                           EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_1),
                                           EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_U),
                                           EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_U),
                                           EGHTVCValues(SDL_KEYDOWN, SDL_SCANCODE_R),
                                           EGHTVCValues(SDL_KEYUP,   SDL_SCANCODE_R))); 


TEST(EventGeneratorHelperTest, CanConvertSdlEvent_SDLQuit) {
  // Given a SDL_event
  SDL_Event sdl_event;
  sdl_event.type = SDL_QUIT;

  // When
  bool result = EventGeneratorHelper::CanConvertSdlEvent(&sdl_event);

  // Then
  ASSERT_THAT(result, IsTrue());
}


TEST(EventGeneratorHelperTest, CanConvertSdlEvent_UnsupportedType) {
  // Given a SDL_event
  SDL_Event sdl_event;
  sdl_event.type = SDL_JOYAXISMOTION;

  // When
  bool result = EventGeneratorHelper::CanConvertSdlEvent(&sdl_event);

  // Then
  ASSERT_THAT(result, IsFalse());
}

TEST(EventGeneratorHelperTest, ConvertSdlEvent_QuitEvent) {
  // Given a SDL_event
  SDL_Event sdl_event;
  sdl_event.type = SDL_QUIT;

  auto parser = IEventParser<ISystemEvent>::Construct();
  auto p_store = IEventStore::Construct();

  // When
  IEvent* result = EventGeneratorHelper::ConvertSdlEvent(&sdl_event, p_store.get());
  ISystemEvent* p_event = (*parser)(result);

  // Then
  ASSERT_THAT(p_event, NotNull());
  ASSERT_THAT(p_event->GetType(), Eq(SystemEventType::Quit));
}


struct ConvertValues {
  ConvertValues(SDL_EventType et,
                SDL_Scancode sc,
                KeyboardEventType ket,
                keyboard::Scancode ksc) :
    event_type(et),
    scancode(sc),
    kb_type(ket),
    kb_scancode(ksc)
  {}

  SDL_EventType event_type;
  SDL_Scancode scancode;

  KeyboardEventType kb_type;
  keyboard::Scancode kb_scancode;
};


class EventGeneratorHelperTestConvertKeyboard :  public ::testing::TestWithParam<ConvertValues> { };


TEST_P(EventGeneratorHelperTestConvertKeyboard, ConvertSdlEvent_Keyboard) {
  // Given a SDL_event
  ConvertValues val = GetParam();

  SDL_Event sdl_event;
  sdl_event.type = val.event_type;
  sdl_event.key.keysym.scancode = val.scancode;

  auto parser = IEventParser<IKeyboardEvent>::Construct();
  auto p_store = IEventStore::Construct();

  // When
  IEvent* result = EventGeneratorHelper::ConvertSdlEvent(&sdl_event, p_store.get());
  IKeyboardEvent* p_event = (*parser)(result);

  // Then
  ASSERT_THAT(p_event, NotNull());
  ASSERT_THAT(p_event->GetType(), Eq(val.kb_type));
  ASSERT_THAT(p_event->GetScancode(), Eq(val.kb_scancode));
}


INSTANTIATE_TEST_SUITE_P(ConvertSdlEvent_Keyboard,
                         EventGeneratorHelperTestConvertKeyboard,
						             ::testing::Values(ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_W,      KeyboardEventType::KeyDown, keyboard::Scancode::W), 
                                           ConvertValues(SDL_KEYUP,   SDL_SCANCODE_W,      KeyboardEventType::KeyUp,   keyboard::Scancode::W),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_A,      KeyboardEventType::KeyDown, keyboard::Scancode::A),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_A,      KeyboardEventType::KeyUp,   keyboard::Scancode::A),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_S,      KeyboardEventType::KeyDown, keyboard::Scancode::S),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_S,      KeyboardEventType::KeyUp,   keyboard::Scancode::S),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_D,      KeyboardEventType::KeyDown, keyboard::Scancode::D),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_D,      KeyboardEventType::KeyUp,   keyboard::Scancode::D),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_ESCAPE, KeyboardEventType::KeyDown, keyboard::Scancode::Escape),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_ESCAPE, KeyboardEventType::KeyUp,   keyboard::Scancode::Escape),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_UP,     KeyboardEventType::KeyDown, keyboard::Scancode::ArrowUp),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_UP,     KeyboardEventType::KeyUp,   keyboard::Scancode::ArrowUp),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_LEFT,   KeyboardEventType::KeyDown, keyboard::Scancode::ArrowLeft),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_LEFT,   KeyboardEventType::KeyUp,   keyboard::Scancode::ArrowLeft),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_DOWN,   KeyboardEventType::KeyDown, keyboard::Scancode::ArrowDown),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_DOWN,   KeyboardEventType::KeyUp,   keyboard::Scancode::ArrowDown),
										                       ConvertValues(SDL_KEYDOWN, SDL_SCANCODE_RIGHT,  KeyboardEventType::KeyDown, keyboard::Scancode::ArrowRight),
										                       ConvertValues(SDL_KEYUP,   SDL_SCANCODE_RIGHT,  KeyboardEventType::KeyUp,   keyboard::Scancode::ArrowRight)));


}
}
