cmake_minimum_required(VERSION 3.4)

project(MultiplayerBowlingGameTest)

add_executable(ScoreManagerTest ScoreManagerTest.cpp)
target_link_libraries(ScoreManagerTest mbowl)
add_test(ScoreManager ScoreManagerTest)