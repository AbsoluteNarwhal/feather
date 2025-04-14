@echo off

git submodule update --init --recursive

:: spdlog
if not exist "featherengine/vendor/spdlog/build" mkdir featherengine/vendor/spdlog/build
pushd featherengine/vendor/spdlog/build
cmake ..
cmake --build .
popd

:: feather
if not exist "build" mkdir build
pushd build
cmake ..
cmake --build .
popd