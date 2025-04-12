set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

add_subdirectory(${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog)
set(spdlog_DIR ${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog/build)
find_package(spdlog REQUIRED)

add_library(featherengine SHARED
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/application.cpp
    ${CMAKE_SOURCE_DIR}/featherengine/src/feather/log.cpp
)

target_link_libraries(featherengine PRIVATE spdlog::spdlog)

target_include_directories(featherengine PUBLIC
    ${CMAKE_SOURCE_DIR}/featherengine/include
    ${CMAKE_SOURCE_DIR}/featherengine/vendor/spdlog/include
)