add_executable(sandbox
    ${CMAKE_SOURCE_DIR}/sandbox/src/main.cpp
)

target_link_libraries(sandbox PRIVATE featherengine)

set_target_properties(sandbox PROPERTIES OUTPUT_NAME "sandbox")