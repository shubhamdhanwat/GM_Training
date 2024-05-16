cmake_minimum_required(VERSION 3.10)
project(G_Test)

# Include Google Test
include(GoogleTest)

# Add your source files
add_executable(${PROJECT_NAME} G_Test.cpp)

# Add Google Test
add_subdirectory(gtest)

# Link against Google Test
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Automatically discover tests and make them available to CTest
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})


