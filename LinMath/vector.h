#ifndef VECTOR_H
#define VECTOR_H

#include "Vector/vec2.h"
#include "Vector/vec3.h"
#include "Vector/vec4.h"
#include "Vector/vecN.h"

namespace linmath {

    // Conversions between vector types
    template <typename T>
    linmath::Vec3<T> vec2to3(linmath::Vec2<T>& vec) {

        return Vec3<T>(vec.x, vec.y, 0);
    }
    template <typename T>
    linmath::Vec3<T> vec2to3(linmath::Vec2<T>& vec, T z) {

        return Vec3<T>(vec.x, vec.y, z);
    }

    template <typename T>
    linmath::Vec4<T> vec2to4(linmath::Vec2<T>& vec) {

        return Vec4<T>(vec.x, vec.y, 0, 0);
    }
    template <typename T>
    linmath::Vec4<T> vec2to4(linmath::Vec2<T>& vec, T z, T w) {

        return Vec4<T>(vec.x, vec.y, z, w);
    }

    template <typename T>
    linmath::Vec4<T> vec3to4(linmath::Vec3<T>& vec) {

        return Vec4<T>(vec.x, vec.y, vec.z, 0);
    }
    template <typename T>
    linmath::Vec4<T> vec3to4(linmath::Vec3<T>& vec, T w) {

        return Vec4<T>(vec.x, vec.y, vec.z, w);
    }

    template <typename T>
    linmath::Vec2<T> vec3to2(linmath::Vec3<T>& vec) {

        return Vec2<T>(vec.x, vec.y);
    }
    template <typename T>
    linmath::Vec2<T> vec4to2(linmath::Vec4<T>& vec) {

        return Vec2<T>(vec.x, vec.y);
    }
    template <typename T>
    linmath::Vec3<T> vec4to3(linmath::Vec4<T>& vec) {

        return Vec3<T>(vec.x, vec.y, vec.z);
    }
}

#endif
