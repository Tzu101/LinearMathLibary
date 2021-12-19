#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Mat2 {
        
        public:
        T values[4];

        // Constructors
        Mat2() {}
        Mat2(T t) {
            this->values[0] = t;
            this->values[1] = t;
            this->values[2] = t;
            this->values[3] = t;
        }
        Mat2(T values[4]) {
            this->values[0] = values[0];
            this->values[1] = values[1];
            this->values[2] = values[2];
            this->values[3] = values[3];
        }
        Mat2(T values[2][2]) {
            this->values[0] = values[0][0];
            this->values[1] = values[0][1];
            this->values[2] = values[1][0];
            this->values[3] = values[1][1];
        }

        // Variadic constructor
        template <typename... Ts>
        Mat2(T t, Ts... ts) {
            auto n = 4;
            *this = Mat2(&n, t, ts...);
        }
        template <typename... Ts>
        Mat2(auto* n, T t, Ts... ts) : Mat2(n, ts...) {
            *n = *n - 1;
            values[*n] = t;
        }
        Mat2(auto*){}


        // Matrix determinant
        T det() {
            return determinant();
        }
        T determinant() {
            return values[0]*values[3] - values[1]*values[2];
        }

        // Matrix transpozition
        void transpoze() {
            T t;
            t = values[1];
            values[1] = values[2];
            values[2] = t;
        }
        Mat2<T> transpozed() {
            Mat2<T> mat = *this;
            mat[1] = values[2];
            mat[2] = values[1];
            return mat;
        }

        // Matrix inverse
        void inverse() {
            T det = determinant();

            T t;
            t = values[0];
            values[0] = values[3];
            values[3] = t;

            values[1] = -values[1];
            values[2] = -values[2];

            *this /= det;
        }
        Mat2<T> inversed() {
            T det = determinant();
            Mat2<T> mat = Mat2<T>();

            mat[0] = values[3];
            mat[1] = -values[1];
            mat[2] = -values[2];
            mat[3] = values[0];

            mat /= det;
            return mat / det;
        }

        // TODO
        // Matrix pivot
        /*void pivot() {

            values[2] = values[]
        }
        Mat2<T> pivoted() {
            return Mat2<T>(1);
        }*/

        // Dot product
        Mat2<T> dot(const Mat2<T>& mat) {
            Mat2<T> dot();
            dot[0] = values[0]*mat.values[0] + values[1]*mat.values[2];
            dot[1] = values[0]*mat.values[1] + values[1]*mat.values[3];
            dot[2] = values[2]*mat.values[0] + values[3]*mat.values[2];
            dot[3] = values[2]*mat.values[1] + values[3]*mat.values[3];
            return dot;
        }

        // Negation
        Mat2<T> operator-() {
            Mat2<T> mat = Mat2<T>();
            mat[0] = -values[0];
            mat[1] = -values[1];
            mat[2] = -values[2];
            mat[3] = -values[3];
            return mat;
        }

        // Prefix increment and decrement
        Mat2<T> operator++() {
            Mat2<T> mat = Mat2<T>();
            mat[0] = ++values[0];
            mat[1] = ++values[1];
            mat[2] = ++values[2];
            mat[3] = ++values[3];
            return mat;
        }
        Mat2<T> operator--() {
            Mat2<T> mat = Mat2<T>();
            mat[0] = --values[0];
            mat[1] = --values[1];
            mat[2] = --values[2];
            mat[3] = --values[3];
            return mat;
        }

        // Postfix increment and decrement
        Mat2<T> operator++(int) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0]++;
            mat[1] = values[1]++;
            mat[2] = values[2]++;
            mat[3] = values[3]++;
            return mat;
        }
        Mat2<T> operator--(int) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0]--;
            mat[1] = values[1]--;
            mat[2] = values[2]--;
            mat[3] = values[3]--;
            return mat;
        }

        // Operations with scalars
        Mat2<T> operator+(const T t) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0] + t;
            mat[1] = values[1] + t;
            mat[2] = values[2] + t;
            mat[3] = values[3] + t;
            return mat;
        }
        Mat2<T> operator-(const T t) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0] - t;
            mat[1] = values[1] - t;
            mat[2] = values[2] - t;
            mat[3] = values[3] - t;
            return mat;
        }
        Mat2<T> operator*(const T t) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0] * t;
            mat[1] = values[1] * t;
            mat[2] = values[2] * t;
            mat[3] = values[3] * t;
            return mat;
        }
        Mat2<T> operator/(const T t) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0] / t;
            mat[1] = values[1] / t;
            mat[2] = values[2] / t;
            mat[3] = values[3] / t;
            return mat;
        }
       Mat2<T> operator%(const T t) {
            Mat2<T> mat = Mat2<T>();
            mat[0] = values[0] % t;
            mat[1] = values[1] % t;
            mat[2] = values[2] % t;
            mat[3] = values[3] % t;
            return mat;
        }
        void operator+=(const T t) {
            values[0] += t;
            values[1] += t;
            values[2] += t;
            values[3] += t;
        }
        void operator-=(const T t) {
            values[0] -= t;
            values[1] -= t;
            values[2] -= t;
            values[3] -= t;
        }
        void operator*=(const T t) {
            values[0] *= t;
            values[1] *= t;
            values[2] *= t;
            values[3] *= t;
        }
        void operator/=(const T t) {
            values[0] /= t;
            values[1] /= t;
            values[2] /= t;
            values[3] /= t;
        }
        void operator%=(const T t) {
            values[0] %= t;
            values[1] %= t;
            values[2] %= t;
            values[3] %= t;
        }

        // Operations with matricies
        Mat2<T> operator+(const Mat2<T>& mat) {
            Mat2<T> out = Mat2<T>();
            out[0] = values[0]+mat.values[0];
            out[1] = values[1]+mat.values[1];
            out[2] = values[2]+mat.values[2];
            out[3] = values[3]+mat.values[3];
            return out;
        }
        Mat2<T> operator-(const Mat2<T>& mat) {
            Mat2<T> out = Mat2<T>();
            out[0] = values[0]-mat.values[0];
            out[1] = values[1]-mat.values[1];
            out[2] = values[2]-mat.values[2];
            out[3] = values[3]-mat.values[3];
            return out;
        }
        Mat2<T> operator*(const Mat2<T>& mat) {
            Mat2<T> out = Mat2<T>();
            out[0] = values[0]*mat.values[0];
            out[1] = values[1]*mat.values[1];
            out[2] = values[2]*mat.values[2];
            out[3] = values[3]*mat.values[3];
            return out;
        }
        Mat2<T> operator/(const Mat2<T>& mat) {
            Mat2<T> out = Mat2<T>();
            out[0] = values[0]/mat.values[0];
            out[1] = values[1]/mat.values[1];
            out[2] = values[2]/mat.values[2];
            out[3] = values[3]/mat.values[3];
            return out;
        }
        void operator+=(const Mat2<T>& mat) {
            values[0] += mat.values[0];
            values[1] += mat.values[1];
            values[2] += mat.values[2];
            values[3] += mat.values[3];
        }
        void operator-=(const Mat2<T>& mat) {
            values[0] -= mat.values[0];
            values[1] -= mat.values[1];
            values[2] -= mat.values[2];
            values[3] -= mat.values[3];
        }
        void operator*=(const Mat2<T>& mat) {
            values[0] *= mat.values[0];
            values[1] *= mat.values[1];
            values[2] *= mat.values[2];
            values[3] *= mat.values[3];
        }
        void operator/=(const Mat2<T>& mat) {
            values[0] /= mat.values[0];
            values[1] /= mat.values[1];
            values[2] /= mat.values[2];
            values[3] /= mat.values[3];
        }

        // Comparison between matricies
        bool operator==(const Mat2<T>& mat) {
            return values[0] == mat.values[0] && 
                values[1] == mat.values[1] && 
                values[2] == mat.values[2] && 
                values[3] == mat.values[3];
        }
        bool operator!=(const Mat2<T>& mat) {
            return values[0] != mat.values[0] || 
                values[1] != mat.values[1] || 
                values[2] != mat.values[2] || 
                values[3] != mat.values[3];
        }

        // Array functionality
        T& operator[](int i) {
            return values[i];
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Mat2<T>& mat) { 
            output << mat.values[0] << " ";
            output << mat.values[1] << "\n";
            output << mat.values[2] << " ";
            output << mat.values[3];
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Mat2<T>& mat) { 
            for (int i=0; i<4; i++)
                input >> mat[i];
            return input;            
        }

        // Predefined matricies
        static Mat2<T> zero();
        static Mat2<T> onev(int v);
        static Mat2<T> oner(int r);
        static Mat2<T> onec(int c);
        static Mat2<T> identity();
        static Mat2<T> one();
    };

    // Predefined vectors
    template <typename T>
    Mat2<T> Mat2<T>::zero() {
        return Mat2<T>(.0);
    }
    template <typename T>
    Mat2<T> Mat2<T>::onev(int v) {
        Mat2<T> mat(.0);
        mat[v] = 1;
        return mat;
    }
    template <typename T>
    Mat2<T> Mat2<T>::oner(int r) {
        Mat2<T> mat(.0);
        for (int c=0; c<2; c++)
            mat[2*r + c] = 1;
        return mat;
    }
    template <typename T>
    Mat2<T> Mat2<T>::onec(int c) {
        Mat2<T> mat(.0);
        for (int r=0; r<2; r++)
            mat[2*r + c] = 1;
        return mat;
    }
    template <typename T>
    Mat2<T> Mat2<T>::identity() {
        return Mat2<T>(1, 0, 0, 1);
    }
    template <typename T>
    Mat2<T> Mat2<T>::one() {
        return Mat2<T>(1);
    }
}

#endif
