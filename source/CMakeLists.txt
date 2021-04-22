cmake_minimum_required(VERSION 3.14)
project(BattleGround LANGUAGES CXX)

file(GLOB_RECURSE SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(BattleGround ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${SOURCE} ${HEADER})

add_compile_definitions(BattleGround)
