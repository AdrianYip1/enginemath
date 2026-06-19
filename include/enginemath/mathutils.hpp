#pragma once
#include <cmath>

namespace enginemath {
    // M_PI is not part of the C++ standard (missing on MSVC without _USE_MATH_DEFINES),
    // so define own constant for portability.
    constexpr float PI = 3.14159265358979323846f;

    constexpr float toRad(float degrees) noexcept { return degrees * (PI / 180.0f); }
    constexpr float toDeg(float radians) noexcept { return radians * (180.0f / PI); }
}