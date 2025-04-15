set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# spdlog
set(spdlog_DIR ${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog/build)
set(SPDLOG_BUILD_SHARED OFF)
set(SPDLOG_BUILD_STATIC ON)
set(SPDLOG_HEADER_ONLY OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog)

# openGL
find_package(OpenGL REQUIRED)

# glfw
add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine/vendor/glfw)

add_library(featherengine SHARED
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/application.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/log.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/window/window.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/event/event.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/event/keyevent.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/event/mouseevent.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/opengl/init.cpp

    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glad/src/glad.c # glad
)

target_link_libraries(featherengine PRIVATE spdlog::spdlog)
target_compile_definitions(featherengine PRIVATE SPDLOG_COMPILED_LIB)
target_link_libraries(featherengine PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(featherengine PRIVATE glfw)

target_include_directories(featherengine PRIVATE
    ${CMAKE_SOURCE_DIR}/featherengine/src
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glad/include
    ${OpenGL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glm
)

target_include_directories(featherengine PUBLIC
    ${CMAKE_SOURCE_DIR}/featherengine/include
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glfw/include
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