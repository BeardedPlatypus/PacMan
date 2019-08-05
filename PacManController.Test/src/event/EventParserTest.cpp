#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <event/IEventParser.h>
#include <event/IMouseEvent.h>
#include <event/IKeyboardEvent.h>
#include <event/ISystemEvent.h>

#include <map>

#pragma region using_statements
using ::testing::Eq;
using ::testing::IsNull;
#pragma endregion

namespace pacman {
namespace controller {

template<typename T1, typename T2>
struct EventParserTestTypes {
  typedef typename T1 ParserType;
  typedef typename T2 EventType;
};


template<typename T>
class EventParserTestCorrect : public ::testing::Test {
public:
  std::unique_ptr<IEventParser<typename T::ParserType>> p_event_parser = 
    IEventParser<typename T::ParserType>::construct();
  std::unique_ptr<typename T::EventType> p_event = std::make_unique<typename T::EventType>();
};


using EventParserCorrectTypes = ::testing::Types<EventParserTestTypes<IMouseEvent, IMouseEvent>, 
                                                 EventParserTestTypes<IKeyboardEvent, IKeyboardEvent>, 
                                                 EventParserTestTypes<ISystemEvent, ISystemEvent>>;

TYPED_TEST_SUITE(EventParserTestCorrect, EventParserCorrectTypes);


TYPED_TEST(EventParserTestCorrect, Operator_ReturnsCorrectPointer) {
  IEvent* input_value = this->p_event.get();

  auto result = (*this->p_event_parser)(input_value);

  ASSERT_THAT(result, Eq(this->p_event.get()));
}


template<typename T>
class EventParserTestIncorrect : public ::testing::Test {
public:
  std::unique_ptr<IEventParser<typename T::ParserType>> p_event_parser = 
    IEventParser<typename T::ParserType>::construct();
  std::unique_ptr<typename T::EventType> p_event = std::make_unique<typename T::EventType>();
};


using EventParserIncorrectTypes = ::testing::Types<EventParserTestTypes<IMouseEvent, IKeyboardEvent>, 
                                                   EventParserTestTypes<IMouseEvent, ISystemEvent>, 
                                                   EventParserTestTypes<IKeyboardEvent, IMouseEvent>, 
                                                   EventParserTestTypes<IKeyboardEvent, ISystemEvent>, 
                                                   EventParserTestTypes<ISystemEvent, IMouseEvent>,
                                                   EventParserTestTypes<ISystemEvent, IKeyboardEvent>>;

TYPED_TEST_SUITE(EventParserTestIncorrect, EventParserIncorrectTypes);

TYPED_TEST(EventParserTestIncorrect, Operator_ReturnsCorrectPointer) {
  IEvent* input_value = this->p_event.get();

  auto result = (*this->p_event_parser)(input_value);

  ASSERT_THAT(result, IsNull());
}


}
}