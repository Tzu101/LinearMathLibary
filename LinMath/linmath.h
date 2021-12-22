#ifndef LINMATH_H
#define LINMATH_H

#include "vector.h"
#include "matrix.h"

namespace linmath {

    // Conversions between vector and matricies
    template<typename T>
    Mat2<T> vec2matr(const Vec2<T>& vec1, const Vec2<T>& vec2) {
        Mat2<T> mat = Mat2<T>();
        mat[0] = vec1.x;
        mat[1] = vec1.y;
        mat[2] = vec2.x;
        mat[3] = vec2.y;
        return mat;
    }
    template<typename T>
    Mat3<T> vec3matr(const Vec3<T>& vec1, const Vec3<T>& vec2, const Vec3<T>& vec3) {
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
    template<typename T>
    Mat4<T> vec4matr(const Vec4<T>& vec1, const Vec4<T>& vec2, const Vec4<T>& vec3, const Vec4<T>& vec4) {
        Mat3<T> mat = Mat3<T>();
        mat[0] = vec1.x;
        mat[1] = vec1.y;
        mat[2] = vec1.z;
        mat[3] = vec1.w;
        mat[4] = vec2.x;
        mat[5] = vec2.y;
        mat[6] = vec2.z;
        mat[7] = vec2.w;
        mat[8] = vec3.x;
        mat[9] = vec3.y;
        mat[10] = vec3.z;
        mat[11] = vec3.w;
        mat[12] = vec4.x;
        mat[13] = vec4.y;
        mat[14] = vec4.z;
        mat[15] = vec4.w;
        return mat;
    }

    template<typename T>
    Mat2<T> vec2matc(const Vec2<T>& vec1, const Vec2<T>& vec2) {
        Mat2<T> mat = Mat2<T>();
        mat[0] = vec1.x;
        mat[1] = vec2.x;
        mat[2] = vec1.y;
        mat[3] = vec2.y;
        return mat;
    }
    template<typename T>
    Mat3<T> vec3matc(const Vec3<T>& vec1, const Vec3<T>& vec2, const Vec3<T>& vec3) {
        Mat3<T> mat = Mat3<T>();
        mat[0] = vec1.x;
        mat[1] = vec2.x;
        mat[2] = vec3.x;
        mat[3] = vec1.y;
        mat[4] = vec2.y;
        mat[5] = vec3.y;
        mat[6] = vec1.z;
        mat[7] = vec2.z;
        mat[8] = vec3.z;
        return mat;
    }
    template<typename T>
    Mat4<T> vec4matc(const Vec4<T>& vec1, const Vec4<T>& vec2, const Vec4<T>& vec3, const Vec4<T>& vec4) {
        Mat3<T> mat = Mat3<T>();
        mat[0] = vec1.x;
        mat[1] = vec2.x;
        mat[2] = vec3.x;
        mat[3] = vec4.x;
        mat[4] = vec1.y;
        mat[5] = vec2.y;
        mat[6] = vec3.y;
        mat[7] = vec4.y;
        mat[8] = vec1.z;
        mat[9] = vec2.z;
        mat[10] = vec3.z;
        mat[11] = vec4.z;
        mat[12] = vec1.w;
        mat[13] = vec2.w;
        mat[14] = vec3.w;
        mat[15] = vec4.w;
        return mat;
    }

    template<typename T>
    Vec2<T> matr2vec(const Mat2<T>& mat, int row) {
        Vec2<T> vec = Vec2<T>();
        for (int col=0; col<2; col++)
            vec[col] = mat.values[2*row + col];
        return vec;
    }
    template<typename T>
    Vec3<T> matr3vec(const Mat3<T>& mat, int row) {
        Vec3<T> vec = Vec3<T>();
        for (int col=0; col<3; col++)
            vec[col] = mat.values[3*row + col];
        return vec;
    }
    template<typename T>
    Vec4<T> matr4vec(const Mat4<T>& mat, int row) {
        Vec4<T> vec = Vec4<T>();
        for (int col=0; col<4; col++)
            vec[col] = mat.values[4*row + col];
        return vec;
    }
    
    template<typename T>
    Vec2<T> matc2vec(const Mat2<T>& mat, int col) {
        Vec2<T> vec = Vec2<T>();
        for (int row=0; row<2; row++)
            vec[row] = mat.values[2*row + col];
        return vec;
    }
    template<typename T>
    Vec3<T> matc3vec(const Mat3<T>& mat, int col) {
        Vec3<T> vec = Vec3<T>();
        for (int row=0; row<3; row++)
            vec[row] = mat.values[3*row + col];
        return vec;
    }
    template<typename T>
    Vec4<T> matc4vec(const Mat4<T>& mat, int col) {
        Vec4<T> vec = Vec4<T>();
        for (int row=0; row<4; row++)
            vec[row] = mat.values[4*row + col];
        return vec;
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
    template<typename T>
    Vec4<T> vec4x4mat(const Vec4<T>& vec, const Mat4<T>& mat) {
        return Vec4<T>( vec.x*mat.values[0] + vec.y*mat.values[4] + vec.z*mat.values[8] + vec.w*mat.values[12], 
                        vec.x*mat.values[1] + vec.y*mat.values[5] + vec.z*mat.values[9] + vec.w*mat.values[13],
                        vec.x*mat.values[2] + vec.y*mat.values[6] + vec.z*mat.values[10] + vec.w*mat.values[14],
                        vec.x*mat.values[3] + vec.y*mat.values[7] + vec.z*mat.values[11] + vec.w*mat.values[15]);
    }

    template<typename T>
    Vec2<T> mat2x2vec(const Mat2<T>& mat, const Vec2<T>& vec) {
        return Vec2<T>( vec.x*mat.values[0] + vec.y*mat.values[1], 
                        vec.x*mat.values[2] + vec.y*mat.values[3]);
    }
    template<typename T>
    Vec3<T> mat3x3vec(const Mat3<T>& mat, const Vec3<T>& vec) {
        return Vec3<T>( vec.x*mat.values[0] + vec.y*mat.values[1] + vec.z*mat.values[2], 
                        vec.x*mat.values[3] + vec.y*mat.values[4] + vec.z*mat.values[5],
                        vec.x*mat.values[6] + vec.y*mat.values[7] + vec.z*mat.values[8]);
    }
    template<typename T>
    Vec4<T> mat4x4vec(const Mat4<T>& mat, const Vec4<T>& vec) {
        return Vec4<T>( vec.x*mat.values[0] + vec.y*mat.values[1] + vec.z*mat.values[2] + vec.w*mat.values[3], 
                        vec.x*mat.values[4] + vec.y*mat.values[5] + vec.z*mat.values[6] + vec.w*mat.values[7],
                        vec.x*mat.values[8] + vec.y*mat.values[9] + vec.z*mat.values[10] + vec.w*mat.values[11],
                        vec.x*mat.values[12] + vec.y*mat.values[13] + vec.z*mat.values[14] + vec.w*mat.values[15]);
    }
}

#endif