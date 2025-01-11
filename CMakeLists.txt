cmake_minimum_required(VERSION 3.21)

project(external-hook-api)

# Create an INTERFACE library
add_library(external-hook-api INTERFACE)

# Set visibility of the symbols
set_target_properties(external-hook-api PROPERTIES CXX_VISIBILITY_PRESET hidden)

# Add source files if applicable
# target_sources(external-hook-api INTERFACE
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/backend.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/hooks.cpp
# )

# Add include directories
target_include_directories(external-hook-api INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Installation rules (if applicable)
# install(TARGETS external-hook-api EXPORT external-hook-api-targets)
# install(DIRECTORY include/ DESTINATION include)

# Optionally, export the target for `find_package`
# export(EXPORT external-hook-api-targets FILE external-hook-api-targets.cmake)
