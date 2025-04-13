# Feather Engine

A 3D voxel engine.

## Build instructions

### Windows

Required software:

- Git
- CMake
- Visual Studio/Ninja/any other build system supported by CMake
- Clang or MSVC (GCC not tested but may work)

1. Clone the repository using `git clone https://github.com/AbsoluteNarwhal/feather`

2. Download dependency sources using `git submodule update --init --recursive`

3. Build spdlog by running the following commands (this only has to be done once):

```
cd featherengine/vendor/spdlog
mkdir build
cd build
cmake .. 
cmake --build .
```

4. Navigate back to the top directory of the project and create a `build` directory.

5. In the `build` directory, run the following commands to build the project: `cmake ..`, `cmake --build .`

6. Run the template project using `./bin/sandbox`

### Linux

Required software: 

- Git 
- CMake 
- Make/Ninja/any other build system supported by CMake
- Clang (GCC not tested but may work)
- Wayland development packages (see below)

Instructions:

1. Ensure the following packages are installed (required to build GLFW)

- APT: `sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`

- DNF: `sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel`

2. Clone the repository using `git clone https://github.com/AbsoluteNarwhal/feather`

3. Download dependency sources using `git submodule update --init --recursive`

4. Build spdlog by running the following commands (this only has to be done once):

```
cd featherengine/vendor/spdlog
mkdir build && cd build
cmake .. && cmake --build .
```

5. Navigate back to the top directory of the project and create a `build` directory.

6. In the `build` directory, run the following commands to build the project: `cmake .. && cmake --build .`

7. Run the template project using `./bin/sandbox`
