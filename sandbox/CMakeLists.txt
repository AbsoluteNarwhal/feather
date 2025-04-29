add_executable(sandbox
    src/main.cpp
)

target_link_libraries(sandbox PRIVATE featherengine)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(sandbox PUBLIC 
        FT_ENABLE_CLIENT_LOGGING
        FT_ENABLE_CLIENT_ASSERTS
    )
endif()

set_target_properties(sandbox PROPERTIES OUTPUT_NAME "sandbox")