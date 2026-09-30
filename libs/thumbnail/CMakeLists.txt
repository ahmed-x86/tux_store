cmake_minimum_required(VERSION 3.21)

# thumbnail — high-throughput icon / thumbnail resolution library.
# Builds as a SHARED library and outputs to ${CMAKE_BINARY_DIR}/software/
# alongside the main tuxstore binary.

find_package(Qt6 REQUIRED COMPONENTS Core Network Gui)

add_library(thumbnail SHARED
    # Implementation files
    src/thumbnail_log.cpp
    src/thumbnail_utils.cpp
    src/iconfetcher.cpp
    src/thumbnailservice.cpp
    # Public QObject header — must be listed so AUTOMOC sees Q_OBJECT and
    # generates the required MOC code. Without this, signal/slot symbols
    # (iconReady, staticMetaObject, vtable) remain undefined at link time.
    include/thumbnailservice.h
)

# Mark that we are building the library (controls THUMBNAIL_API visibility macro).
target_compile_definitions(thumbnail PRIVATE THUMBNAIL_BUILDING_LIB)

target_include_directories(thumbnail
    # Public headers: thumbnail.h and thumbnailservice.h are consumed by the
    # main binary and by any future external consumer.
    PUBLIC  include
    # Private headers: iconfetcher_p.h, thumbnail_log.h, thumbnail_utils.h
    PRIVATE src
)

target_link_libraries(thumbnail
    PRIVATE
        Qt6::Core
        Qt6::Network
        Qt6::Gui
)

# Place the .so next to the main executable so the runtime linker finds it
# without RPATH magic when both live in the same directory.
set_target_properties(thumbnail PROPERTIES
    OUTPUT_NAME              "thumbnail"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/software"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/software"
)
