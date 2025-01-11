cmake_minimum_required(VERSION 3.21)

project(external-hook-api)

add_library(external-hook-api INTERFACE)

set_target_properties(external-hook-api PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_sources(external-hook-api INTERFACE
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/backend.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/hooks.cpp
)

target_include_directories(external-hook-api INTERFACE include)