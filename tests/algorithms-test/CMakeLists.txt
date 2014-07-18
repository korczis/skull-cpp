cmake_minimum_required(VERSION 2.6)
 
project(algorithms-test)

file(GLOB CPP_FILES **/*.cpp ../../vendor/src/gtest/src/*.cc)

add_definitions(
    -std=c++11
)

include_directories(../../lib/include)

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} algorithms pthread)