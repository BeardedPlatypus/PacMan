#pragma once

#include "field/object/IFieldObjectManager.h"
#include "gmock/gmock.h"


class FieldObjectManagerMock : public pacman::state::field::IFieldObjectManager {
public:
  MOCK_METHOD(pacman::state::field::FieldObjectType, GetObjectType, (pacman::state::field::FieldIndex), (const));
  MOCK_METHOD(pacman::state::field::FieldObjectType, GetObjectType, (int, int), (const));
  MOCK_METHOD(void, AddFieldObject, (const pacman::state::field::FieldObject&));
  MOCK_METHOD(void, RemoveFieldObject, (pacman::state::field::FieldIndex));
  MOCK_METHOD(void, RemoveFieldObject, (int, int));
  MOCK_METHOD(bool, HasObjectAt, (pacman::state::field::FieldIndex), (const));
  MOCK_METHOD(bool, HasObjectAt, (int, int), (const));
  MOCK_METHOD((const std::vector<pacman::state::field::FieldObject>&), GetAllFieldObjects, ());
};
