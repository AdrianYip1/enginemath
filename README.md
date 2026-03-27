# enginemath

A small, header-only C++17 math library for game development.

## Usage

In your code:

```cpp
#include <enginemath/enginemath.hpp>

enginemath::Vec2 a{1.0f, 2.0f};
enginemath::Vec2 b{3.0f, 4.0f};
auto c = a + b;
```

## CMake

### Add as a subdirectory

```cmake
add_subdirectory(enginemath)

target_link_libraries(your_target PRIVATE enginemath::enginemath)
```

### Install + find_package

```bash
cmake -S . -B build
cmake --build build
cmake --install build --prefix <install-dir>
```

Then:

```cmake
find_package(enginemath CONFIG REQUIRED)

target_link_libraries(your_target PRIVATE enginemath::enginemath)
```
