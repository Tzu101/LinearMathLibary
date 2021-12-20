#ifndef LINMATH_H
#define LINMATH_H

#include "vector.h"
#include "matrix.h"

namespace linmath {

    // Conversions between vector and matricies
    template<typename T>
    Mat2<T> vec2mat(const Vec2<T>& vec1, const Vec2<T>& vec2) {
        Mat2<T> mat = Mat2<T>();
        mat[0] = vec1.x;
        mat[1] = vec1.y;
        mat[2] = vec2.x;
        mat[3] = vec2.y;
        return mat;
    }
    template<typename T>
    Mat3<T> vec3mat(const Vec3<T>& vec1, const Vec3<T>& vec2, const Vec3<T>& vec3) {
        Mat3<T> mat = Mat3<T>();
        mat[0] = vec1.x;
        mat[1] = vec1.y;
        mat[2] = vec1.z;
        mat[3] = vec2.x;
        mat[4] = vec2.y;
        mat[5] = vec2.z;
        mat[6] = vec3.x;
        mat[7] = vec3.y;
        mat[8] = vec3.z;
        return mat;
    }

    // Vector and matrix multiplication
    template<typename T>
    Vec2<T> vec2x2mat(const Vec2<T>& vec, const Mat2<T>& mat) {
        return Vec2<T>( vec.x*mat.values[0] + vec.y*mat.values[2], 
                        vec.x*mat.values[1] + vec.y*mat.values[3]);
    }
    template<typename T>
    Vec3<T> vec3x3mat(const Vec3<T>& vec, const Mat3<T>& mat) {
        return Vec3<T>( vec.x*mat.values[0] + vec.y*mat.values[3] + vec.z*mat.values[6], 
                        vec.x*mat.values[1] + vec.y*mat.values[4] + vec.z*mat.values[7],
                        vec.x*mat.values[2] + vec.y*mat.values[5] + vec.z*mat.values[8]);
    }
}

#endif