cmake_minimum_required(VERSION 3.21)

project(external-hook-api)

add_library(external-hook-api INTERFACE)

# Add include directory as INTERFACE
target_include_directories(external-hook-api INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set visibility to hidden if needed
set_target_properties(external-hook-api PROPERTIES CXX_VISIBILITY_PRESET hidden)
