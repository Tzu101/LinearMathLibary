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
        return Mat3<T>( mat.values[0], mat.values[1], 0,
                        mat.values[2], mat.values[3], 0,
                        0, 0, 0);
    }
    template<typename T>
    Mat2<T> mat3to2(const Mat3<T>& mat) {
        return Mat2<T>( mat.values[0], mat.values[1],
                        mat.values[3], mat.values[4]);
    }
}

#endif