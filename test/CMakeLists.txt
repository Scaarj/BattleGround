include (FetchContent)
include_directories(${CMAKE_CURRENT_LIST_DIR})

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES *.h *.cpp)

add_executable(${PROJECT_TESTS} ${TEST_SOURCES} ${TEST_SOURCES})
add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})

target_compile_definitions(${PROJECT_NAME}
  PUBLIC $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_TESTS} PUBLIC
    gtest_main
    gmock
    ${PROJECT_LIBRARY}
    )
