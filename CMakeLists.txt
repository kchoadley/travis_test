# borrowed from tutorial at https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

# Get the exercise name from the current directory
get_filename_component(exercise ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

# Name the project after the exercise
project(${exercise} CXX)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Enable C++11 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

# Get a source filename from the exercise name by replacing -'s with _'s
string(REPLACE "-" "_" file ${exercise})

# Implementation could be only a header
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    set(exercise_cpp ${file}.cpp)
else()
    set(exercise_cpp "")
endif()

# Build executable from sources and headers
add_executable(${exercise} ${file}_test.cpp ${exercise_cpp} ${file}.h)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests hello_world_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Tell MSVC not to warn us about unchecked iterators in debug builds
if(${MSVC})
    set_target_properties(${exercise} PROPERTIES
        COMPILE_DEFINITIONS_DEBUG _SCL_SECURE_NO_WARNINGS)
endif()

# Run the tests on every build
add_custom_command(TARGET ${exercise} POST_BUILD COMMAND ${exercise})
