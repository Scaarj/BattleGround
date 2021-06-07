cmake_minimum_required(VERSION 3.14)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES *.h *.cpp)

add_executable(${PROJECT_TESTS} ${TEST_SOURCES} ${TEST_SOURCES})

target_link_libraries(${PROJECT_TESTS}
    gtest_main
    gmock_main
    ${PROJECT_LIBRARY})

set_target_properties(${PROJECT_TESTS}
    PROPERTIES
    LINK_FLAGS    "-lgcov --coverage"
    )

add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})

