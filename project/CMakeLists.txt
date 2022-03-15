include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE PROJECT_SOURCES source/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS source/*.h)
set(QT_DEPENDIES
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Widgets
    )
set(QML_FILES qml.qrc)

add_library(${PROJECT_LIBRARY} STATIC ${PROJECT_HEADERS} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_LIBRARY}
    PUBLIC
    ${QT_DEPENDIES}
    ${Boost_LIBRARIES}
    Box2D
    )

add_executable(${PROJECT_NAME}
    main.cpp
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
    ${QML_FILES}
    )

set_target_properties(${PROJECT_LIBRARY}
    PROPERTIES
    COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
    LINK_FLAGS    "-lgcov --coverage"
    )

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_LIBRARY}
    )

#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(${PROJECT_NAME}
#        MANUAL_FINALIZATION
#        main.cpp
#        ${PROJECT_HEADERS}
#        ${PROJECT_SOURCES}
#        ${QML_FILES}
#    )
#else()
#    add_executable(${PROJECT_NAME}
#        main.cpp
#        ${PROJECT_HEADERS}
#        ${PROJECT_SOURCES}
#        ${QML_FILES}
#    )
#endif()

#add_library(${PROJECT_LIBRARY}
#    STATIC
#    ${PROJECT_SOURCES}
#    ${PROJECT_HEADERS}
#    )

#set_target_properties(${PROJECT_LIBRARY}
#    PROPERTIES
#    COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
#    LINK_FLAGS    "-lgcov --coverage")


#target_compile_definitions(${PROJECT_NAME}
#  PUBLIC $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

#target_link_libraries(${PROJECT_LIBRARY}
#  PUBLIC
#  ${QT_DEPENDIES}
#  ${Boost_LIBRARIES}
#  Box2D
#  )
#target_link_libraries(${PROJECT_NAME}
#  PUBLIC
#  ${PROJECT_LIBRARY}
#  )

#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_import_qml_plugins(${PROJECT_NAME})
#    qt_finalize_executable(${PROJECT_NAME})
#endif()
