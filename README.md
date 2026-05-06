EngineMath

Lightweight C++ math library used across my game engine projects.

EngineMath will provide mathematical types and operations commonly required for rendering, physics, and general engine systems while remaining independent from graphics APIs. Currently EngineMath contains simple operations across Vec2, vec3, Vec4, and Mat4.

Features
Vector math (Vec2, Vec3, Vec4)
Matrix math (Mat4)
Transform utilities
Header-only design
No external dependencies
Designed for reuse via Git submodules
Repository Structure:
EngineMath/
│
├── include/
│   └── enginemath/
│       ├── vec2.h
│       ├── vec3.h
│       ├── vec4.h
│       ├── mat4.h
│       └── math_utils.h
│
├── examples/
├── tests/
└── README.md
Installation (w/ Git Submodule)

EngineMath is intended to be added to projects as a Git submodule.

1. Add Submodule

From your engine or game repository:

git submodule add https://github.com/YOUR_USERNAME/EngineMath.git external/EngineMath

Then initialize:

git submodule update --init --recursive
2. Include in Your Project

Add the include directory to your compiler:

CMake
target_include_directories(MyEngine PRIVATE
    external/EngineMath/include
)

3. Use in Code
#include <enginemath/vec3.h>

using namespace enginemath;

Vec3 position(1.0f, 2.0f, 3.0f);
Updating the Submodule

To pull EngineMath changes:

git submodule update --remote --merge

