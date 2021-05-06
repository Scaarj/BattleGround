set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE SOURCES *.h *.cpp)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} ${Boost_LIBRARIES})
target_link_libraries(${BINARY}_run Box2D)
