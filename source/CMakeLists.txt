set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES *.h *.cpp)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})
#qt5_use_modules(hello_world Widgets)

add_library(${BINARY}_lib STATIC ${SOURCES} ${Boost_LIBRARIES})
