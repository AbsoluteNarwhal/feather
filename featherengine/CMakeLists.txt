set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# spdlog
set(spdlog_DIR vendor/spdlog/build)
set(SPDLOG_BUILD_SHARED OFF)
set(SPDLOG_BUILD_STATIC ON)
set(SPDLOG_HEADER_ONLY OFF)
add_subdirectory(vendor/spdlog)

# openGL
find_package(OpenGL REQUIRED)

# glfw
add_subdirectory(vendor/glfw)

set(enginesrc 
    src/feather/application.cpp
    src/feather/log.cpp
    src/window/window.cpp
    src/event/event.cpp
    src/event/keyevent.cpp
    src/event/mouseevent.cpp
    src/opengl/init.cpp

    vendor/glad/src/glad.c # glad
)

add_library(featherengine SHARED ${enginesrc})

target_link_libraries(featherengine PRIVATE spdlog::spdlog)
target_compile_definitions(featherengine PRIVATE SPDLOG_COMPILED_LIB)
target_link_libraries(featherengine PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(featherengine PRIVATE glfw)

target_include_directories(featherengine PRIVATE
    src
    vendor/glad/include
    ${OpenGL_INCLUDE_DIRS}
    vendor/glm
)

target_include_directories(featherengine PUBLIC
    "include"
    vendor/spdlog/include
    vendor/glfw/include
)

if(MSVC)
    target_compile_definitions(featherengine PRIVATE COMPILER_MSVC)
endif()

target_compile_definitions(featherengine PRIVATE
    FT_BUILD_DLL
    GRAPHICSAPI_OPENGL
    FT_ENABLE_CORE_LOGGING
    FT_ENABLE_CORE_ASSERTS
)

target_compile_definitions(featherengine PUBLIC 
    FT_ENABLE_CLIENT_LOGGING
    FT_ENABLE_CLIENT_ASSERTS
)