set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# spdlog
add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog)
set(spdlog_DIR ${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog/build)
find_package(spdlog REQUIRED)

# openGL
find_package(OpenGL REQUIRED)

# glfw
add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine/vendor/glfw)

add_library(featherengine SHARED
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/application.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/log.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/window/window.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/opengl/init.cpp

    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glad/src/glad.c # glad
)

target_link_libraries(featherengine PRIVATE spdlog::spdlog)
target_link_libraries(featherengine PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(featherengine PRIVATE glfw)

target_include_directories(featherengine PRIVATE
    ${CMAKE_SOURCE_DIR}/featherengine/src
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/glad/include
    ${OpenGL_INCLUDE_DIRS}
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
    GRAPHICSAPI_OPENGL
)