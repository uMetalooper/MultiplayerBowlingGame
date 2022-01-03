cmake_minimum_required(VERSION 3.0.0)
project(MultiplayerBowlingGame VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MultiplayerBowlingGame main.cpp)

add_library(ScoreManager STATIC src/ScoreManager.cpp include/mbowl/ScoreManager.h)
target_include_directories(ScoreManager PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mbowl>
    $<INSTALL_INTERFACE:include/mbowl>)

add_executable(ScoreManagerTest tests/ScoreManagerTest.cpp)
target_include_directories(ScoreManagerTest PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mbowl>
    $<INSTALL_INTERFACE:include/mbowl>)
target_link_libraries(ScoreManagerTest ScoreManager)