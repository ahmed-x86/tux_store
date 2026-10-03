cmake_minimum_required(VERSION 3.21)

# searchengine — package search / query library.
# Builds as a SHARED library alongside the main binary.

find_package(Qt6 REQUIRED COMPONENTS Core Concurrent)

add_library(searchengine SHARED
    src/searchengine.cpp
    # Public QObject header listed so AUTOMOC generates MOC code.
    include/searchengine.h
)

target_compile_definitions(searchengine PRIVATE SEARCHENGINE_BUILDING_LIB)

target_include_directories(searchengine
    PUBLIC  include
    PRIVATE src
)

# The library needs access to the application's Package / PackageDetails types.
# These are defined in the main project's include/ directory. We expose them
# as a PUBLIC include so consumers (the main binary) can also find package.h
# through this target if needed.
target_include_directories(searchengine
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(searchengine
    PRIVATE
        Qt6::Core
        Qt6::Concurrent
)

set_target_properties(searchengine PROPERTIES
    OUTPUT_NAME              "searchengine"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/software"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/software"
)
