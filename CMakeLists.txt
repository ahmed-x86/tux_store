cmake_minimum_required(VERSION 3.21)
project(TuxStore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network Concurrent Gui)
find_package(Slint REQUIRED)

# ── thumbnail.so — icon / thumbnail resolution library ──────────────────────
# Must be added before the main executable so CMake knows the target when
# target_link_libraries(tuxstore … thumbnail) is evaluated below.
add_subdirectory(libs/thumbnail)
add_subdirectory(libs/searchengine)

# ── Main executable ──────────────────────────────────────────────────────────
# iconfetcher.cpp/.h are now compiled exclusively inside libs/thumbnail;
# they are intentionally omitted here.
add_executable(tuxstore
    src/main.cpp
    src/package.cpp
    src/log.cpp
    src/installmanager.cpp
    include/package.h
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
    thumbnail          # libthumbnail.so — icon/thumbnail resolution
    searchengine       # libsearchengine.so — package search/query
)

# Place the main binary in the same software/ directory as libthumbnail.so so
# the runtime linker resolves the library via $ORIGIN without any extra setup.
set_target_properties(tuxstore PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/software"
    # $ORIGIN tells the dynamic linker to look in the same directory as
    # the executable first — picks up libthumbnail.so from software/.
    INSTALL_RPATH            "$ORIGIN"
    BUILD_RPATH              "$ORIGIN/../libs/thumbnail;$ORIGIN/../libs/searchengine;${CMAKE_BINARY_DIR}/software"
    BUILD_WITH_INSTALL_RPATH OFF
)

slint_target_sources(tuxstore ui/main.slint)