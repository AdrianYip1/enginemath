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

            float m[4][4]; // m[col][row]: columns go down
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
        static constexpr Mat4 translationM(const float x, const float y, const float z) {
            return Mat4(
                Vec4(1.0f, 0.0f, 0.0f, 0.0f),
                Vec4(0.0f, 1.0f, 0.0f, 0.0f),
                Vec4(0.0f, 0.0f, 1.0f, 0.0f),
                Vec4(x, y, z, 1.0f) ); }

        //scale
        static constexpr Mat4 scaleM(const float x, const float y, const float z) noexcept {
            return Mat4(
                Vec4(x, 0.0f, 0.0f, 0.0f),
                Vec4(0.0f, y, 0.0f, 0.0f),
                Vec4(0.0f, 0.0f, z, 0.0f),
                Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }

        //rotation (theta is in radians)
        static Mat4 rotateX(const float theta) noexcept {
            return Mat4(
                Vec4(1.0f, 0.0f, 0.0f, 0.0f),
                Vec4(0.0f, std::cos(theta), std::sin(theta), 0.0f),
                Vec4(0.0f, -std::sin(theta), std::cos(theta), 0.0f),
                Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }

        static Mat4 rotateY(const float theta) noexcept {
            return Mat4(
                Vec4(std::cos(theta), 0.0f, -std::sin(theta), 0.0f),
                Vec4(0.0f, 1.0f, 0.0f, 0.0f),
                Vec4(std::sin(theta), 0.0f, std::cos(theta), 0.0f),
                Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }

        static Mat4 rotateZ(const float theta) noexcept {
            return Mat4(
                Vec4(std::cos(theta), std::sin(theta), 0.0f, 0.0f),
                Vec4(-std::sin(theta), std::cos(theta), 0.0f, 0.0f),
                Vec4(0.0f, 0.0f, 1.0f, 0.0f),
                Vec4(0.0f, 0.0f, 0.0f, 1.0f) ); }

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
