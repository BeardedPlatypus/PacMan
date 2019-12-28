#include "CommandMock.h"
#include "KeyboardEventMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "keyboard/IKBCommandManager.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace controller {
namespace keyboard {

/// <summary>
/// Given a IKeyboardEvent
///	  and keyboard::ICommandManager without this event registered
/// When HasEvent is called with this event
/// Then <c>false<c> is returned.
/// </summary>
TEST(KeyboardCommandManagerTest, HasEvent_WithoutEventRegistered) {
  // Given
  KeyboardEventMock event_mock;
  std::unique_ptr<ICommandManager> p_manager = ICommandManager::Construct();

  ASSERT_THAT(p_manager->HasEvent(&event_mock), Eq(false));
}


/// <summary>
/// Given a IKeyboardEvent
///   and a ICommand
///	When keyboard::ICommandManager with this event and command registered
/// Then HasEvent returns <c>true<c>.
///  And GetCommand with this event returns command
/// </summary>
TEST(KeyboardCommandManagerTest, RegisterCommand) {
  // Given
  KeyboardEventMock event_mock;
  std::unique_ptr<ICommand> p_command = std::make_unique<CommandMock>();
  ICommand* p_command_reference = p_command.get();

  std::unique_ptr<ICommandManager> p_manager = ICommandManager::Construct();
  ASSERT_THAT(p_manager->HasEvent(&event_mock), Eq(false));

  // When
  p_manager->RegisterCommand(std::move(p_command), &event_mock);

  // Then
  EXPECT_THAT(p_manager->HasEvent(&event_mock), Eq(true));
  EXPECT_THAT(p_manager->GetCommand(&event_mock), Eq(p_command_reference));
}


/// <summary>
/// Given a IKeyboardEvent
///   and a ICommand
///	  and keyboard::ICommandManager with this event and command registered
/// When DeregisterCommand is called with this event
/// Then HasEvent returns false
/// </summary>
TEST(KeyboardCommandManagerTest, DeregisterCommand_WithCommandRegistered) {
  // Given
  KeyboardEventMock event_mock;
  std::unique_ptr<ICommand> p_command = std::make_unique<CommandMock>();
  ICommand* p_command_reference = p_command.get();

  std::unique_ptr<ICommandManager> p_manager = ICommandManager::Construct();
  p_manager->RegisterCommand(std::move(p_command), &event_mock);
  ASSERT_THAT(p_manager->HasEvent(&event_mock), Eq(true));
  ASSERT_THAT(p_manager->GetCommand(&event_mock), Eq(p_command_reference));

  // When
  p_manager->DeregisterCommand(&event_mock);

  // Then
  EXPECT_THAT(p_manager->HasEvent(&event_mock), Eq(false));
}


/// <summary>
/// Given a IKeyboardEvent
///	  and keyboard::ICommandManager without this event registered
/// When DeregisterCommand is called with this event
/// Then no exception is thrown
///  And HasEvent returns false
/// </summary>
TEST(KeyboardCommandManagerTest, DeregisterCommand_WithoutCommandRegistered) {
  // Given
  KeyboardEventMock event_mock;
  std::unique_ptr<ICommandManager> p_manager = ICommandManager::Construct();

  // When | Then
  ASSERT_NO_THROW(p_manager->DeregisterCommand(&event_mock));
  EXPECT_THAT(p_manager->HasEvent(&event_mock), Eq(false));
}

}
}
}
