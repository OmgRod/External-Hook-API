cmake_minimum_required(VERSION 3.21)

project(ExternalHookAPI)

add_library(ExternalHookAPI INTERFACE)

set_target_properties(ExternalHookAPI PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_sources(ExternalHookAPI INTERFACE
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/backend.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/hooks.cpp
)

target_include_directories(ExternalHookAPI INTERFACE include)