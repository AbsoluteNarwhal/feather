git submodule update --init --recursive

# spdlog
mkdir -p featherengine/vendor/spdlog/build && cd featherengine/vendor/spdlog/build
cmake ..
cmake --build .
cd ../../../..

# feather
mkdir -p build && cd build
cmake ..
cmake --build .
cd ..