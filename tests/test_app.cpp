#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "app.h"
#include "mock_database.h"

using ::testing::Return;
using ::testing::NiceMock;

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "app.h"
#include "mock_database.h"

using ::testing::NiceMock;
using ::testing::Return;

class AppTest : public ::testing::Test {
protected:
    NiceMock<MockDatabase> mockDb;
    App app{&mockDb};

    std::stringstream inputBuffer;
    std::stringstream outputBuffer;

    std::streambuf* oldCinBuf = nullptr;
    std::streambuf* oldCoutBuf = nullptr;

    void SetUp() override {
        oldCoutBuf = std::cout.rdbuf(outputBuffer.rdbuf());
        oldCinBuf = std::cin.rdbuf(inputBuffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(oldCoutBuf);
        std::cin.rdbuf(oldCinBuf);
    }

    void provideInput(const std::string& text) {
        inputBuffer.str(text);
        inputBuffer.clear();
    }

    std::string getOutput() const {
        return outputBuffer.str();
    }
};

TEST_F(AppTest, SumNumbersOutputsCorrectText) {
    EXPECT_CALL(mockDb, getAll())
        .WillOnce(Return(std::vector<int>{1, 2, 3}));

    app.sumNumbers();

    EXPECT_EQ(getOutput(), "Sum = 6\n");
}

TEST_F(AppTest, AddNumberReadsInputAndCallsDB) {
    EXPECT_CALL(mockDb, add(42)).Times(1);

    provideInput("42\n");

    app.addNumber();

    EXPECT_NE(getOutput().find("Input number: "), std::string::npos);
}
