#pragma once
#include "vec3.hpp"
#include <cassert>
#include <cmath>

namespace enginemath {

    struct Quaternion {
        union {
            struct 
            {
                float x;
                float y;
                float z;
                float w;
            };

            float elements[4]; //Allows Quat to be accessed by name and index
        };

        // Constructor
        constexpr Quaternion(float _x, float _y, float _z, float _w) noexcept 
            : x(_x), y(_y), z(_z), w(_w) {}

        // Identity
        static constexpr Quaternion identity() noexcept { return {0, 0, 0, 1}; }

        static Quaternion fromAxisAngle(const Vec3& axis, float angleRad) {
            Vec3 n = axis.normalized();
            float half = angleRad * 0.5f;
            float s = std::sin(half);
            return { n.x * s, n.y * s, n.z * s, std::cos(half) };
        }

       

    
    };
}// namespace enginemath