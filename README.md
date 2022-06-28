# Multi-UAV path planning BINPAT

Algorithm BINPAT for multi-UAV path planning to cover spatial areas, multi-region expansion and replanning.

Link to the [published paper](https://www.mdpi.com/1424-8220/22/6/2297/htm) describing the algorithm.

## Building

The project can either be built as standalone examples or as a static library for linking. Either way the source must be cloned:

```bash
git clone https://github.com/cvar-upm/multi_uav_planning_binpat.git
```

### Compiling the Example

Examples can be built with CMake version `3.15.0` or greater:

```bash
cd multi_uav_planning_binpat
mkdir build
cd build
cmake ..
cmake --build .
```

Example executables can be invoked once compilation is finished:

```bash
./generate_plan_example
```

### Building and Linking the Library

The library can be built and linked to an external project using CMake. The library target can be added by including the project root directory in the external project `CMakeLists.txt` and linked normally afterwards:

```
add_subdirectory(multi_uav_planning_binpat)

target_link_libraries(target planning_binpat)
```

`C++17` or greater is required.
