#include "pch.h"
#include "entity/PlayerMovementAxis.h"

#include <exception>

#include "state_machine/INode.h"


namespace pacman {
namespace update {


PlayerMovementAxis::PlayerMovementAxis() : 
    time_elapsed(0.F) {
  this->InitialiseStateMachine();
}


void PlayerMovementAxis::InitialiseStateMachine() {
  auto p_node_no_presses = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::NoKeyPressed);
  auto p_node_negative_pressed = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::NegativePressed);
  auto p_node_negative_sticky = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::NegativeSticky);
  auto p_node_negative_positive_pressed = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::NegativeThenPositivePressed);
  auto p_node_positive_pressed = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::PositivePressed);
  auto p_node_positive_sticky = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::PositiveSticky);
  auto p_node_positive_negative_pressed = state_machine::INode<state_machine::PlayerControlValue, state_machine::PlayerControlEvent>::Construct(state_machine::PlayerControlValue::PositiveThenNegativePressed);

  p_node_no_presses->AddConnection(p_node_negative_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);
  p_node_no_presses->AddConnection(p_node_positive_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);

  p_node_negative_pressed->AddConnection(p_node_negative_positive_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);
  p_node_negative_pressed->AddConnection(p_node_negative_sticky.get(), state_machine::PlayerControlEvent::NegativeKey);

  p_node_negative_sticky->AddConnection(p_node_no_presses.get(),       state_machine::PlayerControlEvent::TimeOut);
  p_node_negative_sticky->AddConnection(p_node_negative_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);
  p_node_negative_sticky->AddConnection(p_node_positive_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);

  p_node_negative_positive_pressed->AddConnection(p_node_negative_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);
  p_node_negative_positive_pressed->AddConnection(p_node_positive_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);

  p_node_positive_pressed->AddConnection(p_node_positive_negative_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);
  p_node_positive_pressed->AddConnection(p_node_positive_sticky.get(), state_machine::PlayerControlEvent::PositiveKey);

  p_node_positive_sticky->AddConnection(p_node_no_presses.get(),       state_machine::PlayerControlEvent::TimeOut);
  p_node_positive_sticky->AddConnection(p_node_negative_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);
  p_node_positive_sticky->AddConnection(p_node_positive_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);

  p_node_positive_negative_pressed->AddConnection(p_node_negative_pressed.get(), state_machine::PlayerControlEvent::PositiveKey);
  p_node_positive_negative_pressed->AddConnection(p_node_positive_pressed.get(), state_machine::PlayerControlEvent::NegativeKey);


  auto nodes = std::vector<std::unique_ptr<state_machine::INode<state_machine::PlayerControlValue,
                                                                state_machine::PlayerControlEvent>>>();

  nodes.push_back(std::move(p_node_no_presses));
  nodes.push_back(std::move(p_node_negative_pressed));
  nodes.push_back(std::move(p_node_negative_sticky));
  nodes.push_back(std::move(p_node_negative_positive_pressed));
  nodes.push_back(std::move(p_node_positive_pressed));
  nodes.push_back(std::move(p_node_positive_sticky));
  nodes.push_back(std::move(p_node_positive_negative_pressed));

  this->p_state = state_machine::IStateMachine<state_machine::PlayerControlValue, 
                                               state_machine::PlayerControlEvent>::Construct(nodes, 0);
}


void PlayerMovementAxis::Update(float dt) {
  if (this->p_state->GetCurrentValue() == state_machine::PlayerControlValue::NegativeSticky ||
      this->p_state->GetCurrentValue() == state_machine::PlayerControlValue::PositiveSticky) {

    if (this->time_elapsed >= this->sticky_key_time) {
      this->p_state->Move(state_machine::PlayerControlEvent::TimeOut);
      this->time_elapsed = 0.F;
    }
    else {
      this->time_elapsed += dt;
    }
  }
}


AxisDirection PlayerMovementAxis::GetNextDirection() const {
  switch (this->p_state->GetCurrentValue())
  {
  case state_machine::PlayerControlValue::NegativePressed:
  case state_machine::PlayerControlValue::NegativeSticky:
  case state_machine::PlayerControlValue::PositiveThenNegativePressed:
    return AxisDirection::Negative;
  case state_machine::PlayerControlValue::PositivePressed:
  case state_machine::PlayerControlValue::PositiveSticky:
  case state_machine::PlayerControlValue::NegativeThenPositivePressed:
    return AxisDirection::Positive;
  case state_machine::PlayerControlValue::NoKeyPressed:
    return AxisDirection::None;
  default:
    return AxisDirection::None;
  }
}


void PlayerMovementAxis::ChangeState(state_machine::PlayerControlEvent control_event) {
  this->p_state->Move(control_event);
}


}
}
