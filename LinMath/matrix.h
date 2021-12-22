#ifndef MATRIX_H
#define MATRIX_H

#include "Matrix/mat2.h"
#include "Matrix/mat3.h"
#include "Matrix/mat4.h"
#include "Matrix/matN.h"

namespace linmath {

    // Conversions between matricies
    template<typename T>
    Mat3<T> mat2to3(const Mat2<T>& mat) {
        return Mat3<T>( mat[0], mat[1], 0,
                        mat[2], mat[3], 0,
                        0, 0, 0);
    }
    template<typename T>
    Mat2<T> mat3to2(const Mat3<T>& mat) {
        return Mat2<T>( mat[0], mat[1],
                        mat[3], mat[4]);
    }

    template<typename T>
    Mat4<T> mat2to4(const Mat2<T>& mat) {
        return Mat4<T>( mat[0], mat[1], 0, 0,
                        mat[2], mat[3], 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0);
    }
    template<typename T>
    Mat2<T> mat4to2(const Mat2<T>& mat) {
        return Mat2<T>( mat[0], mat[1],
                        mat[4], mat[5]);
    }

    template<typename T>
    Mat4<T> mat3to4(const Mat3<T>& mat) {
        return Mat4<T>( mat[0], mat[1], mat[2], 0,
                        mat[3], mat[4], mat[5], 0,
                        mat[6], mat[7], mat[8], 0,
                        0, 0, 0, 0);
    }
    template<typename T>
    Mat3<T> mat4to3(const Mat4<T>& mat) {
        return Mat3<T>( mat[0], mat[1], mat[2],
                        mat[4], mat[5], mat[6],
                        mat[8], mat[9], mat[10]);
    }
}

#endif