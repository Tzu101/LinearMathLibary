#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Mat4 {

        protected:
        T values[16];

        public:

        // Constructors
        Mat4() {}
        Mat4(T t) {
            this->values[0] = t;
            this->values[1] = t;
            this->values[2] = t;
            this->values[3] = t;
            this->values[4] = t;
            this->values[5] = t;
            this->values[6] = t;
            this->values[7] = t;
            this->values[8] = t;
            this->values[9] = t;
            this->values[10] = t;
            this->values[11] = t;
            this->values[12] = t;
            this->values[13] = t;
            this->values[14] = t;
            this->values[15] = t;
        }
        Mat4(T values[9]) {
            this->values[0] = values[0];
            this->values[1] = values[1];
            this->values[2] = values[2];
            this->values[3] = values[3];
            this->values[4] = values[4];
            this->values[5] = values[5];
            this->values[6] = values[6];
            this->values[7] = values[7];
            this->values[8] = values[8];
            this->values[9] = values[9];
            this->values[10] = values[10];
            this->values[11] = values[11];
            this->values[12] = values[12];
            this->values[13] = values[13];
            this->values[14] = values[14];
            this->values[15] = values[15];
        }
        Mat4(T values[4][4]) {
            this->values[0] = values[0][0];
            this->values[1] = values[0][1];
            this->values[2] = values[0][2];
            this->values[3] = values[0][3];
            this->values[4] = values[1][0];
            this->values[5] = values[1][1];
            this->values[6] = values[1][2];
            this->values[7] = values[1][3];
            this->values[8] = values[2][0];
            this->values[9] = values[2][1];
            this->values[10] = values[2][2];
            this->values[11] = values[2][3];
            this->values[12] = values[3][0];
            this->values[13] = values[3][1];
            this->values[14] = values[3][2];
            this->values[15] = values[3][3];
        }

        // Variadic constructor
        template <typename... Ts>
        Mat4(T t, Ts... ts) {
            auto n = 16;
            *this = Mat4(&n, t, ts...);
        }
        template <typename... Ts>
        Mat4(auto* n, T t, Ts... ts) : Mat4(n, ts...) {
            *n = *n - 1;
            values[*n] = t;
        }
        Mat4(auto*){}


        // Matrix determinant
        T det() {
            return determinant();
        }
        T determinant() {
            return  values[0]* (values[5]*values[10]*values[15] -
                                values[5]*values[11]*values[14] -
                                values[9]*values[6]*values[15] +
                                values[9]*values[7]*values[14] +
                                values[13]*values[6]*values[11] -
                                values[13]*values[7]*values[10]) +
                    values[1]* (-values[4]*values[10]*values[15] +
                                values[4]*values[11]*values[14] +
                                values[8]*values[6]*values[15] -
                                values[8]*values[7]*values[14] -
                                values[12]*values[6]*values[11] +
                                values[12]*values[7]*values[10]) +
                    values[2]* (values[4]*values[9]*values[15] -
                                values[4]*values[11]*values[13] -
                                values[8]*values[5]*values[15] +
                                values[8]*values[7]*values[13] +
                                values[12]*values[5]*values[11] -
                                values[12]*values[7]*values[9]) +
                    values[3]* (-values[4]*values[9]*values[14] +
                                values[4]*values[10]*values[13] +
                                values[8]*values[5]*values[14] -
                                values[8]*values[6]*values[13] -
                                values[12]*values[5]*values[10] +
                                values[12]*values[6]*values[9]);
        }

        // Matrix transpozition
        void transpoze() {
            T t;

            t = values[1];
            values[1] = values[4];
            values[4] = t;

            t = values[2];
            values[2] = values[8];
            values[8] = t;

            t = values[3];
            values[3] = values[12];
            values[12] = t;

            t = values[6];
            values[6] = values[9];
            values[9] = t;

            t = values[7];
            values[7] = values[13];
            values[13] = t;

            t = values[11];
            values[11] = values[14];
            values[14] = t;
        }
        Mat4<T> transpozed() {
            Mat4<T> mat = *this;
            mat[1] = values[4];
            mat[4] = values[1];

            mat[2] = values[8];
            mat[8] = values[2];

            mat[3] = values[12];
            mat[12] = values[3];

            mat[6] = values[9];
            mat[9] = values[6];

            mat[7] = values[13];
            mat[13] = values[7];

            mat[11] = values[14];
            mat[14] = values[11];
            return mat;
        }

        // Matrix inverse
        void inverse() {
            Mat4<T> mat = *this;

            values[0] = mat[5]  * mat[10] * mat[15] - 
                 mat[5]  * mat[11] * mat[14] - 
                 mat[9]  * mat[6]  * mat[15] + 
                 mat[9]  * mat[7]  * mat[14] +
                 mat[13] * mat[6]  * mat[11] - 
                 mat[13] * mat[7]  * mat[10];
    
            values[4] = -mat[4]  * mat[10] * mat[15] + 
                    mat[4]  * mat[11] * mat[14] + 
                    mat[8]  * mat[6]  * mat[15] - 
                    mat[8]  * mat[7]  * mat[14] - 
                    mat[12] * mat[6]  * mat[11] + 
                    mat[12] * mat[7]  * mat[10];
        
            values[8] = mat[4]  * mat[9] * mat[15] - 
                    mat[4]  * mat[11] * mat[13] - 
                    mat[8]  * mat[5] * mat[15] + 
                    mat[8]  * mat[7] * mat[13] + 
                    mat[12] * mat[5] * mat[11] - 
                    mat[12] * mat[7] * mat[9];
        
            values[12] = -mat[4]  * mat[9] * mat[14] + 
                    mat[4]  * mat[10] * mat[13] +
                    mat[8]  * mat[5] * mat[14] - 
                    mat[8]  * mat[6] * mat[13] - 
                    mat[12] * mat[5] * mat[10] + 
                    mat[12] * mat[6] * mat[9];
        
            values[1] = -mat[1]  * mat[10] * mat[15] + 
                    mat[1]  * mat[11] * mat[14] + 
                    mat[9]  * mat[2] * mat[15] - 
                    mat[9]  * mat[3] * mat[14] - 
                    mat[13] * mat[2] * mat[11] + 
                    mat[13] * mat[3] * mat[10];
        
            values[5] = mat[0]  * mat[10] * mat[15] - 
                    mat[0]  * mat[11] * mat[14] - 
                    mat[8]  * mat[2] * mat[15] + 
                    mat[8]  * mat[3] * mat[14] + 
                    mat[12] * mat[2] * mat[11] - 
                    mat[12] * mat[3] * mat[10];
        
            values[9] = -mat[0]  * mat[9] * mat[15] + 
                    mat[0]  * mat[11] * mat[13] + 
                    mat[8]  * mat[1] * mat[15] - 
                    mat[8]  * mat[3] * mat[13] - 
                    mat[12] * mat[1] * mat[11] + 
                    mat[12] * mat[3] * mat[9];
        
            values[13] = mat[0]  * mat[9] * mat[14] - 
                    mat[0]  * mat[10] * mat[13] - 
                    mat[8]  * mat[1] * mat[14] + 
                    mat[8]  * mat[2] * mat[13] + 
                    mat[12] * mat[1] * mat[10] - 
                    mat[12] * mat[2] * mat[9];
        
            values[2] = mat[1]  * mat[6] * mat[15] - 
                    mat[1]  * mat[7] * mat[14] - 
                    mat[5]  * mat[2] * mat[15] + 
                    mat[5]  * mat[3] * mat[14] + 
                    mat[13] * mat[2] * mat[7] - 
                    mat[13] * mat[3] * mat[6];
        
            values[6] = -mat[0]  * mat[6] * mat[15] + 
                    mat[0]  * mat[7] * mat[14] + 
                    mat[4]  * mat[2] * mat[15] - 
                    mat[4]  * mat[3] * mat[14] - 
                    mat[12] * mat[2] * mat[7] + 
                    mat[12] * mat[3] * mat[6];
        
            values[10] = mat[0]  * mat[5] * mat[15] - 
                    mat[0]  * mat[7] * mat[13] - 
                    mat[4]  * mat[1] * mat[15] + 
                    mat[4]  * mat[3] * mat[13] + 
                    mat[12] * mat[1] * mat[7] - 
                    mat[12] * mat[3] * mat[5];
        
            values[14] = -mat[0]  * mat[5] * mat[14] + 
                    mat[0]  * mat[6] * mat[13] + 
                    mat[4]  * mat[1] * mat[14] - 
                    mat[4]  * mat[2] * mat[13] - 
                    mat[12] * mat[1] * mat[6] + 
                    mat[12] * mat[2] * mat[5];
        
            values[3] = -mat[1] * mat[6] * mat[11] + 
                    mat[1] * mat[7] * mat[10] + 
                    mat[5] * mat[2] * mat[11] - 
                    mat[5] * mat[3] * mat[10] - 
                    mat[9] * mat[2] * mat[7] + 
                    mat[9] * mat[3] * mat[6];
        
            values[7] = mat[0] * mat[6] * mat[11] - 
                    mat[0] * mat[7] * mat[10] - 
                    mat[4] * mat[2] * mat[11] + 
                    mat[4] * mat[3] * mat[10] + 
                    mat[8] * mat[2] * mat[7] - 
                    mat[8] * mat[3] * mat[6];
        
            values[11] = -mat[0] * mat[5] * mat[11] + 
                    mat[0] * mat[7] * mat[9] + 
                    mat[4] * mat[1] * mat[11] - 
                    mat[4] * mat[3] * mat[9] - 
                    mat[8] * mat[1] * mat[7] + 
                    mat[8] * mat[3] * mat[5];
        
            values[15] = mat[0] * mat[5] * mat[10] - 
                    mat[0] * mat[6] * mat[9] - 
                    mat[4] * mat[1] * mat[10] + 
                    mat[4] * mat[2] * mat[9] + 
                    mat[8] * mat[1] * mat[6] - 
                    mat[8] * mat[2] * mat[5];
        
            T det = mat[0] * values[0] + mat[1] * values[4] + mat[2] * values[8] + mat[3] * values[12];
        
            *this /= det;
        }
        Mat4<T> inversed() {
            Mat4<T> mat = *this;
            mat.inverse();
            return mat;
        }

        // TODO
        // Matrix pivot
        /*void pivot() {

            values[2] = values[]
        }
        Mat4<T> pivoted() {
            return Mat4<T>(1);
        }*/

        // Dot product
        Mat4<T> dot(const Mat4<T>& mat) {
            Mat4<T> dot = Mat4<T>(1);
            dot[0] = mat[0];
            /*dot[0] = values[0]
            dot[1] = 
            dot[2] = 
            dot[3] = 
            dot[4] = 
            dot[5] = 
            dot[6] = 
            dot[7] = 
            dot[8] = 
            dot[9] = 
            dot[10] = 
            dot[11] = 
            dot[12] = 
            dot[13] = 
            dot[14] = 
            dot[15] = */
            return dot;
        }

        // Negation
        /*Mat4<T> operator-() {
            Mat4<T> mat = Mat4<T>();
            mat[0] = -values[0];
            mat[1] = -values[1];
            mat[2] = -values[2];
            mat[3] = -values[3];
            mat[4] = -values[4];
            mat[5] = -values[5];
            mat[6] = -values[6];
            mat[7] = -values[7];
            mat[8] = -values[8];
            return mat;
        }

        // Prefix increment and decrement
        Mat4<T> operator++() {
            Mat4<T> mat = Mat4<T>();
            mat[0] = ++values[0];
            mat[1] = ++values[1];
            mat[2] = ++values[2];
            mat[3] = ++values[3];
            mat[4] = ++values[4];
            mat[5] = ++values[5];
            mat[6] = ++values[6];
            mat[7] = ++values[7];
            mat[8] = ++values[8];
            return mat;
        }
        Mat4<T> operator--() {
            Mat4<T> mat = Mat4<T>();
            mat[0] = --values[0];
            mat[1] = --values[1];
            mat[2] = --values[2];
            mat[3] = --values[3];
            mat[4] = --values[4];
            mat[5] = --values[5];
            mat[6] = --values[6];
            mat[7] = --values[7];
            mat[8] = --values[8];
            return mat;
        }

        // Postfix increment and decrement
        Mat4<T> operator++(int) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0]++;
            mat[1] = values[1]++;
            mat[2] = values[2]++;
            mat[3] = values[3]++;
            mat[4] = values[4]++;
            mat[5] = values[5]++;
            mat[6] = values[6]++;
            mat[7] = values[7]++;
            mat[8] = values[8]++;
            return mat;
        }
        Mat4<T> operator--(int) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0]--;
            mat[1] = values[1]--;
            mat[2] = values[2]--;
            mat[3] = values[3]--;
            mat[4] = values[4]--;
            mat[5] = values[5]--;
            mat[6] = values[6]--;
            mat[7] = values[7]--;
            mat[8] = values[8]--;
            return mat;
        }

        // Operations with scalars
        Mat4<T> operator+(const T t) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0] + t;
            mat[1] = values[1] + t;
            mat[2] = values[2] + t;
            mat[3] = values[3] + t;
            mat[4] = values[4] + t;
            mat[5] = values[5] + t;
            mat[6] = values[6] + t;
            mat[7] = values[7] + t;
            mat[8] = values[8] + t;
            return mat;
        }
        Mat4<T> operator-(const T t) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0] - t;
            mat[1] = values[1] - t;
            mat[2] = values[2] - t;
            mat[3] = values[3] - t;
            mat[4] = values[4] - t;
            mat[5] = values[5] - t;
            mat[6] = values[6] - t;
            mat[7] = values[7] - t;
            mat[8] = values[8] - t;
            return mat;
        }
        Mat4<T> operator*(const T t) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0] * t;
            mat[1] = values[1] * t;
            mat[2] = values[2] * t;
            mat[3] = values[3] * t;
            mat[4] = values[4] * t;
            mat[5] = values[5] * t;
            mat[6] = values[6] * t;
            mat[7] = values[7] * t;
            mat[8] = values[8] * t;
            return mat;
        }
        Mat4<T> operator/(const T t) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0] / t;
            mat[1] = values[1] / t;
            mat[2] = values[2] / t;
            mat[3] = values[3] / t;
            mat[4] = values[4] / t;
            mat[5] = values[5] / t;
            mat[6] = values[6] / t;
            mat[7] = values[7] / t;
            mat[8] = values[8] / t;
            return mat;
        }
       Mat4<T> operator%(const T t) {
            Mat4<T> mat = Mat4<T>();
            mat[0] = values[0] % t;
            mat[1] = values[1] % t;
            mat[2] = values[2] % t;
            mat[3] = values[3] % t;
            mat[4] = values[4] % t;
            mat[5] = values[5] % t;
            mat[6] = values[6] % t;
            mat[7] = values[7] % t;
            mat[8] = values[8] % t;
            return mat;
        }
        void operator+=(const T t) {
            values[0] += t;
            values[1] += t;
            values[2] += t;
            values[3] += t;
            values[4] += t;
            values[5] += t;
            values[6] += t;
            values[7] += t;
            values[8] += t;
        }
        void operator-=(const T t) {
            values[0] -= t;
            values[1] -= t;
            values[2] -= t;
            values[3] -= t;
            values[4] -= t;
            values[5] -= t;
            values[6] -= t;
            values[7] -= t;
            values[8] -= t;
        }
        void operator*=(const T t) {
            values[0] *= t;
            values[1] *= t;
            values[2] *= t;
            values[3] *= t;
            values[4] *= t;
            values[5] *= t;
            values[6] *= t;
            values[7] *= t;
            values[8] *= t;
        }*/
        void operator/=(const T t) {
            values[0] /= t;
            values[1] /= t;
            values[2] /= t;
            values[3] /= t;
            values[4] /= t;
            values[5] /= t;
            values[6] /= t;
            values[7] /= t;
            values[8] /= t;
            values[9] /= t;
            values[10] /= t;
            values[11] /= t;
            values[12] /= t;
            values[13] /= t;
            values[14] /= t;
            values[15] /= t;
        }
        /*void operator%=(const T t) {
            values[0] %= t;
            values[1] %= t;
            values[2] %= t;
            values[3] %= t;
            values[4] %= t;
            values[5] %= t;
            values[6] %= t;
            values[7] %= t;
            values[8] %= t;
        }

        // Operations with matricies
        Mat4<T> operator+(const Mat4<T>& mat) {
            Mat4<T> out = Mat4<T>();
            out[0] = values[0]+mat[0];
            out[1] = values[1]+mat[1];
            out[2] = values[2]+mat[2];
            out[3] = values[3]+mat[3];
            out[4] = values[4]+mat[4];
            out[5] = values[5]+mat[5];
            out[6] = values[6]+mat[6];
            out[7] = values[7]+mat[7];
            out[8] = values[8]+mat[8];
            return out;
        }
        Mat4<T> operator-(const Mat4<T>& mat) {
            Mat4<T> out = Mat4<T>();
            out[0] = values[0]-mat[0];
            out[1] = values[1]-mat[1];
            out[2] = values[2]-mat[2];
            out[3] = values[3]-mat[3];
            out[4] = values[4]-mat[4];
            out[5] = values[5]-mat[5];
            out[6] = values[6]-mat[6];
            out[7] = values[7]-mat[7];
            out[8] = values[8]-mat[8];
            return out;
        }
        Mat4<T> operator*(const Mat4<T>& mat) {
            Mat4<T> out = Mat4<T>();
            out[0] = values[0]*mat[0];
            out[1] = values[1]*mat[1];
            out[2] = values[2]*mat[2];
            out[3] = values[3]*mat[3];
            out[4] = values[4]*mat[4];
            out[5] = values[5]*mat[5];
            out[6] = values[6]*mat[6];
            out[7] = values[7]*mat[7];
            out[8] = values[8]*mat[8];
            return out;
        }
        Mat4<T> operator/(const Mat4<T>& mat) {
            Mat4<T> out = Mat4<T>();
            out[0] = values[0]/mat[0];
            out[1] = values[1]/mat[1];
            out[2] = values[2]/mat[2];
            out[3] = values[3]/mat[3];
            out[4] = values[4]/mat[4];
            out[5] = values[5]/mat[5];
            out[6] = values[6]/mat[6];
            out[7] = values[7]/mat[7];
            out[8] = values[8]/mat[8];
            return out;
        }
        void operator+=(const Mat4<T>& mat) {
            values[0] += mat[0];
            values[1] += mat[1];
            values[2] += mat[2];
            values[3] += mat[3];
            values[4] += mat[4];
            values[5] += mat[5];
            values[6] += mat[6];
            values[7] += mat[7];
            values[8] += mat[8];
        }
        void operator-=(const Mat4<T>& mat) {
            values[0] -= mat[0];
            values[1] -= mat[1];
            values[2] -= mat[2];
            values[3] -= mat[3];
            values[4] -= mat[4];
            values[5] -= mat[5];
            values[6] -= mat[6];
            values[7] -= mat[7];
            values[8] -= mat[8];
        }
        void operator*=(const Mat4<T>& mat) {
            values[0] *= mat[0];
            values[1] *= mat[1];
            values[2] *= mat[2];
            values[3] *= mat[3];
            values[4] *= mat[4];
            values[5] *= mat[5];
            values[6] *= mat[6];
            values[7] *= mat[7];
            values[8] *= mat[8];
        }
        void operator/=(const Mat4<T>& mat) {
            values[0] /= mat[0];
            values[1] /= mat[1];
            values[2] /= mat[2];
            values[3] /= mat[3];
            values[4] /= mat[4];
            values[5] /= mat[5];
            values[6] /= mat[6];
            values[7] /= mat[7];
            values[8] /= mat[8];
        }

        // Comparison between matricies
        bool operator==(const Mat4<T>& mat) {
            return  values[0] == mat[0] && 
                    values[1] == mat[1] && 
                    values[2] == mat[2] && 
                    values[3] == mat[3] && 
                    values[4] == mat[4] && 
                    values[5] == mat[5] && 
                    values[6] == mat[6] && 
                    values[7] == mat[7] && 
                    values[8] == mat[8];
        }
        bool operator!=(const Mat4<T>& mat) {
            return values[0] != mat[0] || 
                values[1] != mat[1] || 
                values[2] != mat[2] || 
                values[3] != mat[3] || 
                values[4] != mat[4] || 
                values[5] != mat[5] || 
                values[6] != mat[6] || 
                values[7] != mat[7] || 
                values[8] != mat[8];
        }*/

        // Array functionality
        T& operator[](uint8_t i) {
            return values[i];
        }
        const T& operator[](uint8_t i) const {
            return values[i];
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Mat4<T>& mat) { 
            output << mat[0] << " ";
            output << mat[1] << " ";
            output << mat[2] << " ";
            output << mat[3] << "\n";
            output << mat[4] << " ";
            output << mat[5] << " ";
            output << mat[6] << " ";
            output << mat[7] << "\n";
            output << mat[8] << " ";
            output << mat[9] << " ";
            output << mat[10] << " ";
            output << mat[11] << "\n";
            output << mat[12] << " ";
            output << mat[13] << " ";
            output << mat[14] << " ";
            output << mat[15];
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Mat4<T>& mat) { 
            for (uint8_t i=0; i<16; i++)
                input >> mat[i];
            return input;            
        }

        // Predefined matricies
        static Mat4<T> zero();
        static Mat4<T> onei(uint8_t ind);
        static Mat4<T> oner(uint8_t row);
        static Mat4<T> onec(uint8_t col);
        static Mat4<T> identity();
        static Mat4<T> one();

        // Transformation matricies
        static Mat4<T> translation(T tx, T ty, T tz);
        static Mat4<T> rotationX(T ang);
        static Mat4<T> rotationDegX(T ang);
        static Mat4<T> rotationY(T ang);
        static Mat4<T> rotationDegY(T ang);
        static Mat4<T> rotationZ(T ang);
        static Mat4<T> rotationDegZ(T ang);
        static Mat4<T> scale(T sx, T sy, T sz);
    };

    // Predefined matricies
    template <typename T>
    Mat4<T> Mat4<T>::zero() {
        return Mat4<T>(.0);
    }
    template <typename T>
    Mat4<T> Mat4<T>::onei(uint8_t ind) {
        Mat4<T> mat(.0);
        mat[ind] = 1;
        return mat;
    }
    template <typename T>
    Mat4<T> Mat4<T>::oner(uint8_t row) {
        Mat4<T> mat(.0);
        for (uint8_t col=0; col<4; col++)
            mat[4*row + col] = 1;
        return mat;
    }
    template <typename T>
    Mat4<T> Mat4<T>::onec(uint8_t col) {
        Mat4<T> mat(.0);
        for (uint8_t row=0; row<4; row++)
            mat[4*row + col] = 1;
        return mat;
    }
    template <typename T>
    Mat4<T> Mat4<T>::identity() {
        return Mat4<T>( 1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1);
    }
    template <typename T>
    Mat4<T> Mat4<T>::one() {
        return Mat4<T>(1);
    }

    // Transformation matricies
    template<typename T>
    Mat4<T> Mat4<T>::translation(T tx, T ty, T tz) {
        return Mat4<T>( 1, 0, 0, 0, 
                        0, 1, 0, 0, 
                        0, 0, 1, 0, 
                        tx, ty, tz, 1);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationX(T ang) {
        return Mat4<T>( 1, 0, 0, 0, 
                        0, cos(ang), sin(ang), 0, 
                        0, -sin(ang), cos(ang), 0, 
                        0, 0, 0, 1);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationDegX(T ang) {
        return rotationX(ang*3.14159265/180);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationY(T ang) {
        return Mat4<T>( cos(ang), 0, -sin(ang), 0, 
                        0, 1, 0, 0,
                        sin(ang), 0, cos(ang), 0,
                        0, 0, 0, 1);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationDegY(T ang) {
        return rotationY(ang*3.14159265/180);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationZ(T ang) {
        return Mat4<T>( cos(ang), sin(ang), 0, 0, 
                        -sin(ang), cos(ang), 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1);
    }
    template<typename T>
    Mat4<T> Mat4<T>::rotationDegZ(T ang) {
        return rotationZ(ang*3.14159265/180);
    }
    template<typename T>
    Mat4<T> Mat4<T>::scale(T sx, T sy, T sz) {
        return Mat4<T>( sx, 0, 0, 0, 
                        0, sy, 0, 0,
                        0, 0, sz, 0,
                        0, 0, 0, 1);
    }
}

#endif
