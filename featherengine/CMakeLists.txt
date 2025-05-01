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
    src/event/appevent.cpp
    src/event/windowevent.cpp
    src/opengl/init.cpp
    src/opengl/test.cpp

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

target_compile_definitions(featherengine PRIVATE
    FT_BUILD_DLL
    GRAPHICSAPI_OPENGL
)

if(MSVC)
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