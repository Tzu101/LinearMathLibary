#ifndef MATRIX_H
#define MATRIX_H

#include "Matrix/mat2.h"
#include "Matrix/mat3.h"
#include "Matrix/mat4.h"
#include "Matrix/matN.h"

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

    /*template<typename T>
    Mat3<T> vec2mat(const Vec2<T>& vec1, const Vec2<T>& vec2) {
        Mat3<T> mat = Mat3<T>();
        mat[0] = vec1.x;
        mat[1] = vec1.y;
        mat[2] = vec2.x;
        mat[3] = vec2.y;
        return mat;
    }*/
}

#endif