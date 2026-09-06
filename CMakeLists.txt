cmake_minimum_required(VERSION 3.21)
project(TuxStore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Concurrent Gui)
find_package(Slint REQUIRED)

add_executable(tuxstore
    src/main.cpp
    src/package.cpp
    src/pacmanmanager.cpp
    src/iconfetcher.cpp
    src/log.cpp
    src/installmanager.cpp
    include/package.h
    include/pacmanmanager.h
    include/iconfetcher.h
    include/log.h
    include/installmanager.h
)

target_include_directories(tuxstore PRIVATE include)

target_link_libraries(tuxstore PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Network
    Qt6::Concurrent
    Slint::Slint
)

slint_target_sources(tuxstore ui/main.slint)