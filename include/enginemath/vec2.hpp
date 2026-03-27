#pragma once

#include <cassert>
#include <cmath>
#include <iostream>

namespace enginemath {

struct Vec2 {
    float x{0.0f};
    float y{0.0f};

    //Constructors
    constexpr Vec2() noexcept = default;
    constexpr Vec2(float x, float y) noexcept : x(x), y(y) {}
    explicit constexpr Vec2(float scalar) noexcept : x(scalar), y(scalar) {}

    //Simple Operations
    constexpr Vec2 operator+(const Vec2& other) const noexcept { return {x + other.x, y + other.y}; }
    constexpr Vec2 operator-(const Vec2& other) const noexcept { return {x - other.x, y - other.y}; }
    constexpr Vec2 operator*(float scalar) const noexcept { return {x * scalar, y * scalar}; }

    Vec2 operator/(float scalar) const { assert(scalar != 0.0f); return {x / scalar, y / scalar}; }

    constexpr Vec2 operator-() const noexcept { return {-x, -y}; }

    Vec2& operator+=(const Vec2& other) noexcept { x += other.x; y += other.y; return *this; }
    Vec2& operator-=(const Vec2& other) noexcept { x -= other.x; y -= other.y; return *this; }
    Vec2& operator*=(float scalar) noexcept { x *= scalar; y *= scalar; return *this; }
    Vec2& operator/=(float scalar) { assert(scalar != 0.0f); x /= scalar; y /= scalar; return *this; }

    //Comparison
    constexpr bool operator==(const Vec2& other) const noexcept { return (x == other.x && y == other.y); }
    constexpr bool operator!=(const Vec2& other) const noexcept { return (x!= other.x && y != other.y); }
    bool equal_within_decimals(const Vec2& other, const int num_points) const noexcept {
        float eps = std::pow(10.0f, -num_points); 
        return std::fabs(x - other.x) < eps && std::fabs(y - other.y) < eps;
    }
    bool equal_within_tolerance(const Vec2& other, const float tolerance) const noexcept {
        float eps = std::fabs(tolerance);
        return std::fabs(x - other.x) < eps && std::fabs(y - other.y) < eps;
    }

};

} // namespace enginemath
