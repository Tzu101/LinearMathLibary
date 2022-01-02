#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Mat3 {
        
        protected:
        T values[9];

        public:

        // Constructors
        Mat3() {}
        Mat3(T t) {
            this->values[0] = t;
            this->values[1] = t;
            this->values[2] = t;
            this->values[3] = t;
            this->values[4] = t;
            this->values[5] = t;
            this->values[6] = t;
            this->values[7] = t;
            this->values[8] = t;
        }
        Mat3(T values[9]) {
            this->values[0] = values[0];
            this->values[1] = values[1];
            this->values[2] = values[2];
            this->values[3] = values[3];
            this->values[4] = values[4];
            this->values[5] = values[5];
            this->values[6] = values[6];
            this->values[7] = values[7];
            this->values[8] = values[8];
        }
        Mat3(T values[3][3]) {
            this->values[0] = values[0][0];
            this->values[1] = values[0][1];
            this->values[2] = values[0][2];
            this->values[3] = values[1][0];
            this->values[4] = values[1][1];
            this->values[5] = values[1][2];
            this->values[6] = values[2][0];
            this->values[7] = values[2][1];
            this->values[8] = values[2][2];
        }

        // Variadic constructor
        template <typename... Ts>
        Mat3(T t, Ts... ts) {
            auto n = 9;
            *this = Mat3(&n, t, ts...);
        }
        template <typename... Ts>
        Mat3(auto* n, T t, Ts... ts) : Mat3(n, ts...) {
            *n = *n - 1;
            values[*n] = t;
        }
        Mat3(auto*){}


        // Matrix determinant
        T det() {
            return determinant();
        }
        T determinant() {
            return  values[0]*( values[4]*values[8] - values[5]*values[7] )-
                    values[1]*( values[3]*values[8] - values[5]*values[6] )+
                    values[2]*( values[3]*values[7] - values[4]*values[6] );
        }

        // Matrix transpozition
        void transpoze() {
            T t;

            t = values[1];
            values[1] = values[3];
            values[3] = t;

            t = values[2];
            values[2] = values[6];
            values[6] = t;

            t = values[5];
            values[5] = values[7];
            values[7] = t;
        }
        Mat3<T> transpozed() {
            Mat3<T> mat = *this;
            mat[1] = values[3];
            mat[3] = values[1];

            mat[2] = values[6];
            mat[6] = values[2];

            mat[5] = values[7];
            mat[7] = values[5];
            return mat;
        }

        // Matrix inverse
        void inverse() {
            T det = determinant();

            Mat3<T> mat = transpozed();

            values[0] = mat[4]*mat[8] - mat[5]*mat[7];
            values[1] = -(mat[3]*mat[8] - mat[5]*mat[6]);
            values[2] = mat[3]*mat[7] - mat[4]*mat[6];
            values[3] = -(mat[1]*mat[8] - mat[2]*mat[7]);
            values[4] = mat[0]*mat[8] - mat[2]*mat[6];
            values[5] = -(mat[0]*mat[7] - mat[1]*mat[6]);
            values[6] = mat[1]*mat[5] - mat[2]*mat[4];
            values[7] = -(mat[0]*mat[5] - mat[2]*mat[3]);
            values[8] = mat[0]*mat[4] - mat[1]*mat[3];

            *this /= det;
        }
        Mat3<T> inversed() {
            Mat3<T> mat = *this;
            mat.inverse();
            return mat;
        }

        // TODO
        // Matrix pivot
        /*void pivot() {

            values[2] = values[]
        }
        Mat3<T> pivoted() {
            return Mat3<T>(1);
        }*/

        // Dot product
        Mat3<T> dot(const Mat3<T>& mat) {
            Mat3<T> dot = Mat3<T>();
            dot[0] = values[0]*mat[0] + values[1]*mat[3] + values[2]*mat[6];
            dot[1] = values[0]*mat[1] + values[1]*mat[4] + values[2]*mat[7];
            dot[2] = values[0]*mat[2] + values[1]*mat[5] + values[2]*mat[8];
            dot[3] = values[3]*mat[0] + values[4]*mat[3] + values[5]*mat[6];
            dot[4] = values[3]*mat[1] + values[4]*mat[4] + values[5]*mat[7];
            dot[5] = values[3]*mat[2] + values[4]*mat[5] + values[5]*mat[8];
            dot[6] = values[6]*mat[0] + values[7]*mat[3] + values[8]*mat[6];
            dot[7] = values[6]*mat[1] + values[7]*mat[4] + values[8]*mat[7];
            dot[8] = values[6]*mat[2] + values[7]*mat[5] + values[8]*mat[8];
            return dot;
        }

        // Negation
        Mat3<T> operator-() {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator++() {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator--() {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator++(int) {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator--(int) {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator+(const T t) {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator-(const T t) {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator*(const T t) {
            Mat3<T> mat = Mat3<T>();
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
        Mat3<T> operator/(const T t) {
            Mat3<T> mat = Mat3<T>();
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
       Mat3<T> operator%(const T t) {
            Mat3<T> mat = Mat3<T>();
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
        }
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
        }
        void operator%=(const T t) {
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
        Mat3<T> operator+(const Mat3<T>& mat) {
            Mat3<T> out = Mat3<T>();
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
        Mat3<T> operator-(const Mat3<T>& mat) {
            Mat3<T> out = Mat3<T>();
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
        Mat3<T> operator*(const Mat3<T>& mat) {
            Mat3<T> out = Mat3<T>();
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
        Mat3<T> operator/(const Mat3<T>& mat) {
            Mat3<T> out = Mat3<T>();
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
        void operator+=(const Mat3<T>& mat) {
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
        void operator-=(const Mat3<T>& mat) {
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
        void operator*=(const Mat3<T>& mat) {
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
        void operator/=(const Mat3<T>& mat) {
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
        bool operator==(const Mat3<T>& mat) {
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
        bool operator!=(const Mat3<T>& mat) {
            return  values[0] != mat[0] || 
                    values[1] != mat[1] || 
                    values[2] != mat[2] || 
                    values[3] != mat[3] || 
                    values[4] != mat[4] || 
                    values[5] != mat[5] || 
                    values[6] != mat[6] || 
                    values[7] != mat[7] || 
                    values[8] != mat[8];
        }

        // Array functionality
        T& operator[](uint8_t i) {
            return values[i];
        }
        const T& operator[](uint8_t i) const {
            return values[i];
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Mat3<T>& mat) { 
            output << mat[0] << " ";
            output << mat[1] << " ";
            output << mat[2] << "\n";
            output << mat[3] << " ";
            output << mat[4] << " ";
            output << mat[5] << "\n";
            output << mat[6] << " ";
            output << mat[7] << " ";
            output << mat[8];
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Mat3<T>& mat) { 
            for (uint8_t i=0; i<9; i++)
                input >> mat[i];
            return input;            
        }

        // Predefined matricies
        static Mat3<T> zero();
        static Mat3<T> onei(uint8_t ind);
        static Mat3<T> oner(uint8_t row);
        static Mat3<T> onec(uint8_t col);
        static Mat3<T> identity();
        static Mat3<T> one();

        // Transformation matricies
        static Mat3<T> translation(T tx, T ty);
        static Mat3<T> rotation(T ang);
        static Mat3<T> rotationDeg(T ang);
        static Mat3<T> scale(T sx, T sy);
    };

    // Predefined matricies
    template <typename T>
    Mat3<T> Mat3<T>::zero() {
        return Mat3<T>(.0);
    }
    template <typename T>
    Mat3<T> Mat3<T>::onei(uint8_t ind) {
        Mat3<T> mat(.0);
        mat[ind] = 1;
        return mat;
    }
    template <typename T>
    Mat3<T> Mat3<T>::oner(uint8_t row) {
        Mat3<T> mat(.0);
        for (uint8_t col=0; col<3; col++)
            mat[3*row + col] = 1;
        return mat;
    }
    template <typename T>
    Mat3<T> Mat3<T>::onec(uint8_t col) {
        Mat3<T> mat(.0);
        for (uint8_t row=0; row<3; row++)
            mat[3*row + col] = 1;
        return mat;
    }
    template <typename T>
    Mat3<T> Mat3<T>::identity() {
        return Mat3<T>(1, 0, 0, 0, 1, 0, 0, 0, 1);
    }
    template <typename T>
    Mat3<T> Mat3<T>::one() {
        return Mat3<T>(1);
    }

    // Transformation matricies
    template<typename T>
    Mat3<T> Mat3<T>::translation(T tx, T ty) {
        return Mat3<T>(1, 0, 0, 0, 1, 0, tx, ty, 1);
    }
    template<typename T>
    Mat3<T> Mat3<T>::rotation(T ang) {
        return Mat3<T>(cos(ang), -sin(ang), 0, sin(ang), cos(ang), 0, 0, 0, 1);
    }
    template<typename T>
    Mat3<T> Mat3<T>::rotationDeg(T ang) {
        return rotation(ang*3.14159265/180);
    }
    template<typename T>
    Mat3<T> Mat3<T>::scale(T sx, T sy) {
        return Mat3<T>(sx, 0, 0, 0, sy, 0, 0, 0, 1);
    }

    // Overload functions
    template <typename T, typename K>
    Mat3<T> operator+(const Mat3<T> mat, const K k) {
        Mat3<T> out = Mat3<T>();
        out[0] = mat[0] + k;
        out[1] = mat[1] + k;
        out[2] = mat[2] + k;
        out[3] = mat[3] + k;
        out[4] = mat[4] + k;
        out[5] = mat[5] + k;
        out[6] = mat[6] + k;
        out[7] = mat[7] + k;
        out[8] = mat[8] + k;
        return out;
    }
    template <typename T, typename K>
    Mat3<T> operator-(const Mat3<T> mat, const K k) {
        Mat3<T> out = Mat3<T>();
        out[0] = mat[0] - k;
        out[1] = mat[1] - k;
        out[2] = mat[2] - k;
        out[3] = mat[3] - k;
        out[4] = mat[4] - k;
        out[5] = mat[5] - k;
        out[6] = mat[6] - k;
        out[7] = mat[7] - k;
        out[8] = mat[8] - k;
        return out;
    }
    template <typename T, typename K>
    Mat3<T> operator*(const Mat3<T> mat, const K k) {
        Mat3<T> out = Mat3<T>();
        out[0] = mat[0] * k;
        out[1] = mat[1] * k;
        out[2] = mat[2] * k;
        out[3] = mat[3] * k;
        out[4] = mat[4] * k;
        out[5] = mat[5] * k;
        out[6] = mat[6] * k;
        out[7] = mat[7] * k;
        out[8] = mat[8] * k;
        return out;
    }
    template <typename T, typename K>
    Mat3<T> operator/(const Mat3<T> mat, const K k) {
        Mat3<T> out = Mat3<T>();
        out[0] = mat[0] / k;
        out[1] = mat[1] / k;
        out[2] = mat[2] / k;
        out[3] = mat[3] / k;
        out[4] = mat[4] / k;
        out[5] = mat[5] / k;
        out[6] = mat[6] / k;
        out[7] = mat[7] / k;
        out[8] = mat[8] / k;
        return out;
    }
    template <typename T, typename K>
    Mat3<T> operator%(const Mat3<T> mat, const K k) {
        Mat3<T> out = Mat3<T>();
        out[0] = mat[0] % k;
        out[1] = mat[1] % k;
        out[2] = mat[2] % k;
        out[3] = mat[3] % k;
        out[4] = mat[4] % k;
        out[5] = mat[5] % k;
        out[6] = mat[6] % k;
        out[7] = mat[7] % k;
        out[8] = mat[8] % k;
        return out;
    }
}

#endif
