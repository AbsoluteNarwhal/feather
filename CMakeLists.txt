cmake_minimum_required(VERSION 3.15)
project(Feather VERSION 1.0)

option(USE_OPENGL "Use OpenGL" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine)
add_subdirectory(${CMAKE_SOURCE_DIR}/sandbox)