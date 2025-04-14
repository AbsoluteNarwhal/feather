# Feather Engine

A 3D voxel engine.

## Build instructions

Required software: 

- Git 
- CMake 
- Make/Ninja/any other build system supported by CMake
- Clang/MSVC (GCC not tested but may work)
- For Linux: Wayland development packages (see below)

Instructions:

1. On Linux, ensure the following packages are installed (required to build GLFW)

- APT: `sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`

- DNF: `sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel`

2. Clone the repository using `git clone https://github.com/AbsoluteNarwhal/feather`

3. Create a `build` directory if it doesn't already exist, and `cd` into it

4. Run `cmake ..` and `cmake --build .`

5. Run the template project using `./bin/sandbox`
