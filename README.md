# Feather Engine

A 3D voxel engine.

## Build instructions

### Linux

Required software: 

- Git 
- CMake 
- Make/Ninja/any other build system supported by CMake
- Clang (GCC not tested but may work)
- Wayland development packages (see below)

Instructions:

1. Install the following packages (required by GLFW)

- APT: `sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`

- DNF: `sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel`

2. Clone the repository using `git clone https://github.com/AbsoluteNarwhal/feather`

3. Copy the file `featherengine/vendor/glad/include/glad/glad.h` into `/usr/local/include/glad/glad.h` or somewhere similar. This is required for Glad (OpenGL).

4. Make a build directory and `cd` into it: `mkdir build && cd build`

5. Run the following command to build the project: `cmake .. && cmake --build .`

6. Run the template project using `./bin/sandbox`
