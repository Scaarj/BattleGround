cmake_minimum_required(VERSION 3.17)

project(BattleGround LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source/)

add_subdirectory(source)
add_subdirectory(test)
