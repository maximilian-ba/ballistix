cmake_minimum_required(VERSION 3.15)

project(Ballistix
    VERSION 0.1.0
    DESCRIPTION "A modern C++ ballistics simulation library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Support for VS Code IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---
# Project Section
add_library(Ballistix INTERFACE)

target_include_directories(Ballistix INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)