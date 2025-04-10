cmake_minimum_required(VERSION 3.10)
project(Feather VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(featherengine SHARED
    featherengine/src/feather/application.cpp
)

target_include_directories(featherengine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/featherengine/include
)

add_executable(sandbox
    sandbox/src/main.cpp
)

target_link_libraries(sandbox PRIVATE featherengine)

set_target_properties(sandbox PROPERTIES OUTPUT_NAME "sandbox")