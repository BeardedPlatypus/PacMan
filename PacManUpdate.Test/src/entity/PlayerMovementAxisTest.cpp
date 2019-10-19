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

    std::vector<state_machine::PlayerControlEvent> valuesPositive = { state_machine::PlayerControlEvent::PositiveKey };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositive, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveSticky = {
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::PositiveKey
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveSticky, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegative = {
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::NegativeKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegative, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativeNegative = {
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::NegativeKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativeNegative, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesPositiveNegativePositive = {
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::PositiveKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesPositiveNegativePositive, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegative = { state_machine::PlayerControlEvent::NegativeKey };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegative, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegativeSticky = {
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::NegativeKey
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativeSticky, AxisDirection::Negative));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositive = {
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::PositiveKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositive, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositiveNegative = {
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::NegativeKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositiveNegative, AxisDirection::Positive));

    std::vector<state_machine::PlayerControlEvent> valuesNegativePositivePositive = {
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::PositiveKey,
      state_machine::PlayerControlEvent::PositiveKey,
    };
    result.push_back(PlayerMovementAxisStateMachineTestValues(valuesNegativePositivePositive, AxisDirection::Negative));

    return result;
  }
};


TEST_P(PlayerMovementAxisStateMachineTest, ReturnsCorrectDirection) {
  // Setup
  auto p_axis = IPlayerMovementAxis::Construct();

  AxisDirection expected_value = this->GetParam().expected_value;
  std::vector<state_machine::PlayerControlEvent> events = this->GetParam().events;

  // Call
  for (state_machine::PlayerControlEvent control_event : events) {
    p_axis->ChangeState(control_event);
  }

  // Assert
  EXPECT_EQ(p_axis->GetNextDirection(), expected_value);
}


INSTANTIATE_TEST_SUITE_P(PlayerMovementAxisTest,
                         PlayerMovementAxisStateMachineTest,
                         ::testing::ValuesIn(PlayerMovementAxisStateMachineTest::GetTestValues()));



class PlayerMovementAxisTimeOutTest : public ::testing::TestWithParam<state_machine::PlayerControlEvent> {
public:
  static std::vector<state_machine::PlayerControlEvent> GetTestValues() {
    std::vector<state_machine::PlayerControlEvent> result = {
      state_machine::PlayerControlEvent::NegativeKey,
      state_machine::PlayerControlEvent::PositiveKey,
    };

    return result;
  }
};


TEST_P(PlayerMovementAxisTimeOutTest, UpdateCorrectlyTimesOut) {
  // Setup
  auto p_axis = IPlayerMovementAxis::Construct();
  state_machine::PlayerControlEvent event_type = this->GetParam();

  // bring the axis in a timed out state;
  p_axis->ChangeState(event_type);
  p_axis->ChangeState(event_type);

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