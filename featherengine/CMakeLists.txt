set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# spdlog
set(spdlog_DIR vendor/spdlog/build)
set(SPDLOG_BUILD_SHARED OFF)
set(SPDLOG_BUILD_STATIC ON)
set(SPDLOG_HEADER_ONLY OFF)
add_subdirectory(vendor/spdlog)

add_subdirectory(vendor/glfw)

set(enginesrc 
    src/feather/application.cpp
    src/feather/log.cpp
    src/feather/files.cpp
    src/window/window.cpp
    src/event/event.cpp
    src/event/keyevent.cpp
    src/event/mouseevent.cpp
    src/event/appevent.cpp
    src/event/windowevent.cpp
    src/renderer/renderer.cpp
)

if(USE_OPENGL)
    find_package(OpenGL REQUIRED)

    add_library(glad STATIC vendor/glad/src/glad.c)
    target_include_directories(glad PUBLIC vendor/glad/include)

    list(APPEND enginesrc 
        src/opengl/init.cpp
        src/opengl/test.cpp
        src/opengl/shader.cpp
    )
else()
    message(FATAL_ERROR "Other APIs are not supported yet. Please set USE_OPENGL to ON.")
endif()

add_library(featherengine SHARED ${enginesrc})

target_link_libraries(featherengine PRIVATE spdlog::spdlog)
target_compile_definitions(featherengine PRIVATE SPDLOG_COMPILED_LIB)
target_link_libraries(featherengine PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(featherengine PUBLIC glfw)

target_include_directories(featherengine PUBLIC
    "include"
    vendor/spdlog/include
)

target_include_directories(featherengine PRIVATE
    src
)

target_compile_definitions(featherengine PRIVATE
    FT_BUILD_DLL
)

if(USE_OPENGL)
    target_compile_definitions(featherengine PUBLIC
        GRAPHICSAPI_OPENGL
    )
    target_link_libraries(featherengine PRIVATE glad)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(featherengine PRIVATE COMPILER_MSVC)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(featherengine PRIVATE
        FT_BUILD_DEBUG
        FT_ENABLE_CORE_LOGGING
        FT_ENABLE_CORE_ASSERTS
    )
else()
    target_compile_definitions(featherengine PRIVATE
        FT_BUILD_RELEASE
    )
endif()