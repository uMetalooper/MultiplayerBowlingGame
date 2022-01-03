cmake_minimum_required(VERSION 3.4)

project(MultiplayerBowlingGameLibs)

add_library(ScoreManager STATIC ScoreManager.cpp ../include/mbowl/ScoreManager.h)
target_include_directories(ScoreManager PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mylib>
$<INSTALL_INTERFACE:include/mylib>)