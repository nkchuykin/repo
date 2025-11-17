#pragma once
#include <gmock/gmock.h>
#include "database.h"

class MockDatabase: public IDatabase {
public:
    MOCK_METHOD(void, add, (int value), (override));
    MOCK_METHOD(void, removeAll, (int value), (override));
    MOCK_METHOD(std::vector<int>, getAll, (), (const, override));
};