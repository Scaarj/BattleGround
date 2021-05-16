include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE PROJECT_SOURCES source/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS source/*.h)
set(PROJECT_SOURCES_AND_HEADERS ${PROJECT_SOURCES} ${PROJECT_HEADERS})

set(QML_FILES qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${QML_FILES}
        ${PROJECT_SOURCES_AND_HEADERS}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(${PROJECT_NAME}
            main.cpp
            ${QML_FILES}
            ${PROJECT_SOURCES_AND_HEADERS}
        )
    endif()
endif()

add_library(${PROJECT_LIBRARY}
    STATIC
    ${PROJECT_SOURCES}
    ${Boost_LIBRARIES}
    )

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Gui
  Qt${QT_VERSION_MAJOR}::Qml
  ${Boost_LIBRARIES}
  Box2D
  )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()

