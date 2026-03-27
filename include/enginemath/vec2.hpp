#pragma once

#include <cassert>

namespace enginemath {

struct Vec2 {
    float x{0.0f};
    float y{0.0f};

    constexpr Vec2() noexcept = default;
    constexpr Vec2(float x_, float y_) noexcept : x(x_), y(y_) {}
    explicit constexpr Vec2(float scalar) noexcept : x(scalar), y(scalar) {}

    constexpr Vec2 operator+(const Vec2& other) const noexcept { return {x + other.x, y + other.y}; }
    constexpr Vec2 operator-(const Vec2& other) const noexcept { return {x - other.x, y - other.y}; }
    constexpr Vec2 operator*(float scalar) const noexcept { return {x * scalar, y * scalar}; }

    Vec2 operator/(float scalar) const {
        assert(scalar != 0.0f);
        return {x / scalar, y / scalar};
    }

    constexpr Vec2 operator-() const noexcept { return {-x, -y}; }

    Vec2& operator+=(const Vec2& other) noexcept { x += other.x; y += other.y; return *this; }
    Vec2& operator-=(const Vec2& other) noexcept { x -= other.x; y -= other.y; return *this; }
    Vec2& operator*=(float scalar) noexcept { x *= scalar; y *= scalar; return *this; }

    Vec2& operator/=(float scalar) {
        assert(scalar != 0.0f);
        x /= scalar;
        y /= scalar;
        return *this;
    }
};

} // namespace enginemath
