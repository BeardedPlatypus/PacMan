#include <gtest/gtest.h>

#include <entity/IPlayerMovementAxis.h>


namespace pacman {
namespace update {

TEST(PlayerMovementAxisTest, Constructor_ExpectedValues) {
  // Call
  auto p_axis = IPlayerMovementAxis::Construct();

  // Assert
  EXPECT_EQ(p_axis->GetNextDirection(), AxisDirection::None);
}


struct PlayerMovementAxisStateMachineTestValues {
  PlayerMovementAxisStateMachineTestValues(std::vector<state_machine::PlayerControlEvent> events,
                                           AxisDirection expected_value) :
      events(events),
      expected_value(expected_value) 
  {  }

  std::vector<state_machine::PlayerControlEvent> events;
  AxisDirection expected_value;
};


class PlayerMovementAxisStateMachineTest : public ::testing::TestWithParam<PlayerMovementAxisStateMachineTestValues> {
public:
  static std::vector<PlayerMovementAxisStateMachineTestValues> GetTestValues() {
    auto result = std::vector<PlayerMovementAxisStateMachineTestValues>();

    std::vector<state_machine::PlayerControlEvent> valuesPositive = { state_machine::PlayerControlEvent::PositiveKeyPress };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositive, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveSticky = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveSticky, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegative = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegative, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativeNegative = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativeNegative, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativePositive = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativePositive, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegative = { state_machine::PlayerControlEvent::NegativeKeyPress };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegative, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegativeSticky = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativeSticky, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositive = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositive, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositiveNegative = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositiveNegative, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositivePositive = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositivePositive, AxisDirection::Negative));

    return result;
  }
};


TEST_P(PlayerMovementAxisStateMachineTest, ReturnsCorrectDirection) {
  // Setup
  auto p_axis = IPlayerMovementAxis::Construct();

  AxisDirection expected_value = GetParam().expected_value;
  std::vector<state_machine::PlayerControlEvent> events = GetParam().events;

  // Call
  for (state_machine::PlayerControlEvent control_event : events) {
    p_axis->ChangeState(control_event);
    p_axis->Update(0.F);
  }

  // Assert
  EXPECT_EQ(p_axis->GetNextDirection(), expected_value);
}


INSTANTIATE_TEST_SUITE_P(PlayerMovementAxisTest,
                         PlayerMovementAxisStateMachineTest,
                         ::testing::ValuesIn(PlayerMovementAxisStateMachineTest::GetTestValues()));


// Unregistered key presses should not change the state.
class PlayerMovementAxisStateMachineUnregisteredKeyPressTest : public ::testing::TestWithParam<PlayerMovementAxisStateMachineTestValues> {
public:
  static std::vector<PlayerMovementAxisStateMachineTestValues> GetTestValues() {
    auto result = std::vector<PlayerMovementAxisStateMachineTestValues>();

    // Positive -> Positive Press 
    std::vector<state_machine::PlayerControlEvent> valuesPositivePositivePress = { 
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositivePositivePress, AxisDirection::Positive));

    // Positive -> Negative Release
    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativeRelease = { 
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativeRelease, AxisDirection::Positive));

    // PositiveSticky -> Positive Release
    std::vector<state_machine::PlayerControlEvent> valuesPositiveStickyPositiveRelease = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease,
      state_machine::PlayerControlEvent::PositiveKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveStickyPositiveRelease, AxisDirection::Positive));

    // PositiveSticky -> Negative Release
    std::vector<state_machine::PlayerControlEvent> valuesPositiveStickyNegativeRelease = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease,
      state_machine::PlayerControlEvent::NegativeKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveStickyNegativeRelease, AxisDirection::Positive));

    // Positive Negative -> Negative Key Press
    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativeNegativePress = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativeNegativePress, AxisDirection::Negative));

    // Positive Negative -> Positive Key Press
    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativePositivePress = {
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativePositivePress, AxisDirection::Negative));

    // Negative -> Negative Press
    std::vector<state_machine::PlayerControlEvent> valuesNegativeNegativePress = { 
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativeNegativePress, AxisDirection::Negative));

    // Negative -> Positive Release
    std::vector<state_machine::PlayerControlEvent> valuesNegativePositiveRelease = { 
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyRelease,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositiveRelease, AxisDirection::Negative));

    // Negative Sticky -> Negative Release
    std::vector<state_machine::PlayerControlEvent> valuesNegativeStickyNegativeRelease = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease,
      state_machine::PlayerControlEvent::NegativeKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativeStickyNegativeRelease, AxisDirection::Negative));

    // Negative Sticky -> Positive Release
    std::vector<state_machine::PlayerControlEvent> valuesNegativeStickyPositiveRelease = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyRelease,
      state_machine::PlayerControlEvent::PositiveKeyRelease
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativeStickyPositiveRelease, AxisDirection::Negative));

    // Negative Positive -> Positive Press
    std::vector<state_machine::PlayerControlEvent> valuesNegativePositivePositivePress = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositivePositivePress, AxisDirection::Positive));

    // Negative Positive -> Negative Press
    std::vector<state_machine::PlayerControlEvent> valuesNegativePositiveNegativePress = {
      state_machine::PlayerControlEvent::NegativeKeyPress,
      state_machine::PlayerControlEvent::PositiveKeyPress,
      state_machine::PlayerControlEvent::NegativeKeyPress,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositiveNegativePress, AxisDirection::Positive));

    return result;
  }
};


INSTANTIATE_TEST_SUITE_P(PlayerMovementAxisTest,
                         PlayerMovementAxisStateMachineUnregisteredKeyPressTest,
                         ::testing::ValuesIn(PlayerMovementAxisStateMachineUnregisteredKeyPressTest::GetTestValues()));



class PlayerMovementAxisTimeOutTest : public ::testing::TestWithParam<std::vector<state_machine::PlayerControlEvent>> {
public:
  static std::vector<std::vector<state_machine::PlayerControlEvent>> GetTestValues() {
    std::vector<std::vector<state_machine::PlayerControlEvent>> result = {
      { state_machine::PlayerControlEvent::NegativeKeyPress, state_machine::PlayerControlEvent::NegativeKeyRelease },
      { state_machine::PlayerControlEvent::PositiveKeyPress, state_machine::PlayerControlEvent::PositiveKeyRelease },
    };

    return result;
  }
};


TEST_P(PlayerMovementAxisTimeOutTest, UpdateCorrectlyTimesOut) {
  // Setup
  auto p_axis = IPlayerMovementAxis::Construct();
  std::vector<state_machine::PlayerControlEvent> events = GetParam();

  // bring the axis in a timed out state;
  for (auto e : events) {
    p_axis->ChangeState(e);
    p_axis->Update(0.F);
  }


  // Call
  p_axis->Update(100.F);

  // Assert
  EXPECT_EQ(p_axis->GetNextDirection(), AxisDirection::None);
}

INSTANTIATE_TEST_SUITE_P(PlayerMovementAxisTest,
                         PlayerMovementAxisTimeOutTest,
                         ::testing::ValuesIn(PlayerMovementAxisTimeOutTest::GetTestValues()));


}
}