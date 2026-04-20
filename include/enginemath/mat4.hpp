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
        static constexpr Mat4 zero() noexcept { return Mat4(Vec4(0.0f), Vec4(0.0f), Vec4(0.0f), Vec4(0.0f) ); }
        static constexpr Mat4 identity() noexcept { 
            return Mat4(
                Vec4(1.0f, 0.0f, 0.0f, 0.0f), 
                Vec4(0.0f, 1.0f, 0.0f, 0.0f), 
                Vec4(0.0f, 0.0f, 1.0f, 0.0f), 
                Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }
            
        // matrix transforms 
        //translation
        //scale
        //rotation

        // Math Operations
        constexpr Vec4 operator*(const Vec4& right) const {
            return Vec4(
                (*this).c0.x * right.x + (*this).c1.x * right.y + (*this).c2.x * right.z + (*this).c3.x * right.w,
                (*this).c0.y * right.x + (*this).c1.y * right.y + (*this).c2.y * right.z + (*this).c3.y * right.w,
                (*this).c0.z * right.x + (*this).c1.z * right.y + (*this).c2.z * right.z + (*this).c3.z * right.w,
                (*this).c0.w * right.x + (*this).c1.w * right.y + (*this).c2.w * right.z + (*this).c3.w * right.w );
        }

        constexpr Mat4 operator*(const Mat4& right) const {
            return Mat4(
                (*this)*right.c0,
                (*this)*right.c1,
                (*this)*right.c2,
                (*this)*right.c3 );
        }
        
    };

}// namespace enginemath
