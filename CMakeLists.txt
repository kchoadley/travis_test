# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests hello_world_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread fruit)
