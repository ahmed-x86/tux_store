cmake_minimum_required(VERSION 3.16)
project(TuxStore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network Svg Concurrent)

qt_standard_project_setup()

add_executable(tuxstore
    src/main.cpp
    src/package.cpp
    src/pacmanmanager.cpp
    src/iconfetcher.cpp
    src/mainwindow.cpp
    src/appcard.cpp
    src/detailsview.cpp
    src/theme.cpp
    src/log.cpp
    include/package.h
    include/pacmanmanager.h
    include/iconfetcher.h
    include/mainwindow.h
    include/appcard.h
    include/detailsview.h
    include/theme.h
    include/log.h
)

target_include_directories(tuxstore PRIVATE include)

target_link_libraries(tuxstore PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
    Qt6::Svg
    Qt6::Concurrent
)
