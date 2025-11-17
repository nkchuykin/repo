cmake_minimum_required(VERSION 3.18)
project(number_app)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

# set(SOURCES
#     src/app.cpp
#     src/database.cpp
#     src/utils.cpp
#     src/main.cpp
# )

# add_executable(NumberApp ${SOURCES})

add_library(numberlib
    src/app.cpp
    src/database.cpp
    src/utils.cpp
)

add_executable(NumberApp src/main.cpp)
target_link_libraries(NumberApp PRIVATE numberlib)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sum_tests
    tests/test_sum.cpp
    tests/test_greater_than.cpp
    tests/test_app.cpp
)

target_link_libraries(sum_tests
    PRIVATE
        numberlib
        gtest_main
        gmock_main
)

include(GoogleTest)
gtest_discover_tests(sum_tests)
