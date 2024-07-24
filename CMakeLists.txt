cmake_minimum_required(VERSION 3.5)

project(hello VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(hello MANUAL_FINALIZATION main.cpp
        counter.h counter.cpp
    )
else()
    if(ANDROID)
        add_library(hello SHARED main.cpp)
    else()
        add_executable(hello main.cpp)
    endif()
endif()

target_link_libraries(hello PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS hello
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(hello PROPERTIES MACOSX_BUNDLE TRUE)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(hello)
endif()
