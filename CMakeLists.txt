cmake_minimum_required(VERSION 3.16)
project(qtMouseMover LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    qtMouseMover.ui
    qtMouseMover.h
    qtMouseMover.cpp
)


qt_add_executable(qtMouseMover ${PROJECT_SOURCES}
    MouseMover.qrc)

set_target_properties(qtMouseMover
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(qtMouseMover
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
