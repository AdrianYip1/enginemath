#pragma once

#include <cassert>
#include <cmath>
#include "vec4.hpp"

namespace enginemath {

    struct Mat4 {
        union {
            struct 
                    {
                        Vec4 c0;
                        Vec4 c1;
                        Vec4 c2;
                        Vec4 c3;
                    };

            float m[4][4]; // m[col][row]
        };

        //constructor
        constexpr Mat4(const Vec4& _c0, const Vec4& _c1, const Vec4& _c2, const Vec4& _c3) noexcept : 
            c0(_c0), c1(_c1), c2(_c2), c3(_c3) {}


        // important matrices
        static constexpr Mat4 zeroMatrix() noexcept { return Mat4(Vec4(0.0f), Vec4(0.0f), Vec4(0.0f), Vec4(0.0f) ); }
        static constexpr Mat4 identityMatrix() noexcept { 
            return Mat4(
            Vec4(1.0f, 0.0f, 0.0f, 0.0f), 
            Vec4(0.0f, 1.0f, 0.0f, 0.0f), 
            Vec4(0.0f, 0.0f, 1.0f, 0.0f), 
            Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }
        
    }

}// namespace enginemath