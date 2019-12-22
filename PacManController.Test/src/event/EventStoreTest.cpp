#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <event/IEventStore.h>

#pragma region using_statements
using ::testing::Eq;
using ::testing::Pointee;
#pragma endregion


namespace pacman {
  namespace controller {

    TEST(EventStoreTest, WhenAKeyboardEventIsRetrieved_ItIsCorrect) {
      // Given
      std::unique_ptr<IEventStore> p_event_store = IEventStore::Construct();
      auto key_scancode = keyboard::Scancode::A;
      auto key_event_type = KeyboardEventType::KeyDown;

      // When
      const IKeyboardEvent* p_event = p_event_store->GetKeyboardEvent(key_event_type, key_scancode);

      // Then
      ASSERT_THAT(p_event->GetScancode(), Eq(key_scancode));
      ASSERT_THAT(p_event->GetType(), Eq(key_event_type));
    }


    TEST(EventStoreTest, WhenAKeyboardEventIsRetrievedTwice_ItIsTheSameEvent) {
      // Given
      std::unique_ptr<IEventStore> p_event_store = IEventStore::Construct();
      auto key_scancode = keyboard::Scancode::A;
      auto key_event_type = KeyboardEventType::KeyDown;

      const IKeyboardEvent* p_event_first = p_event_store->GetKeyboardEvent(key_event_type, key_scancode);

      // When
      const IKeyboardEvent* p_event_second = p_event_store->GetKeyboardEvent(key_event_type, key_scancode);

      // Then
      ASSERT_THAT(p_event_second, Eq(p_event_first));
    }


    TEST(EventStoreTest, WhenASystemEventIsRetrieved_ItIsCorrect) {
      // Given
      std::unique_ptr<IEventStore> p_event_store = IEventStore::Construct();
      auto system_event_type = SystemEventType::Quit;

      // When
      const ISystemEvent* p_event = p_event_store->GetSystemEvent(system_event_type);

      // Then
      ASSERT_THAT(p_event->GetType(), Eq(system_event_type));
    }


    TEST(EventStoreTest, WhenASystemEventIsRetrievedTwice_ItIsTheSameEvent) {
      // Given
      std::unique_ptr<IEventStore> p_event_store = IEventStore::Construct();
      auto system_event_type = SystemEventType::Quit;

      const ISystemEvent* p_event_first = p_event_store->GetSystemEvent(system_event_type);

      // When
      const ISystemEvent* p_event_second = p_event_store->GetSystemEvent(system_event_type);

      // Then
      ASSERT_THAT(p_event_second, Eq(p_event_first));
    }

  }
}
