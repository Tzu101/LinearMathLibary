#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Vec3 {

        public:
        T x;
        T y;
        T z;

        // Constructors
        Vec3() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }
        Vec3(T x, T y, T z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        // Directional normalization
        T length()const {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }
        void normalize() {
            T len = length();
            x = x / len;
            y = y / len;
            z = z / len;
        }
        Vec3<T> normalized() {
            T len = length();
            return Vec3(x / len, y / len, z / len);
        }

        // Sum of all values
        T sum()const {
            return x + y + z;
        }

        // Dot product
        T dot(const Vec3<T>& vec) {
            return x*vec.x + y*vec.y + z*vec.z;
        }

        // Cross product
        Vec3<T> cross(const Vec3<T>& vec) {
            return Vec3(y*vec.z - z*vec.y, z*vec.x - x*vec.z, x*vec.y - y*vec.x);
        }

        // Negation
        Vec3<T> operator-() {
            return Vec3<T>(-x, -y, -z);
        }

        // Prefix increment and decrement
        Vec3<T> operator++() {
            x++;
            y++;
            z++;
            return Vec3<T>(x, y, z);
        }
        Vec3<T> operator--() {
            x--;
            y--;
            z--;
            return Vec3<T>(x, y, z);
        }

        // Postfix increment and decrement
        Vec3<T> operator++(int) {
            Vec3<T> vec(x, y, z);
            x++;
            y++;
            z++;
            return vec;
        }
        Vec3<T> operator--(int) {
            Vec3<T> vec(x, y, z);
            x--;
            y--;
            z--;
            return vec;
        }

        // Operations with scalars
        Vec3<T> operator+(const T t) {
            return Vec3<T>(x + t, y + t, z + t);
        }
        Vec3<T> operator-(const T t) {
            return Vec3<T>(x - t, y - t, z - t);
        }
        Vec3<T> operator*(const T t) {
            return Vec3<T>(x * t, y * t, z * t);
        }
        Vec3<T> operator/(const T t) {
            return Vec3<T>(x / t, y / t, z / t);
        }
        Vec3<T> operator%(const T t) {
            return Vec3<T>(x % t, y % t, z % t);
        }
        void operator+=(const T t) {
            x += t;
            y += t;
            z += t;
        }
        void operator-=(const T t) {
            x -= t;
            y -= t;
            z -= t;
        }
        void operator*=(const T t) {
            x *= t;
            y *= t;
            z *= t;
        }
        void operator/=(const T t) {
            x /= t;
            y /= t;
            z /= t;
        }
        void operator%=(const T t) {
            x %= t;
            y %= t;
            z %= t;
        }

        // Operations with vectors
        Vec3<T> operator+(const Vec3<T>& vec) {
            return Vec3<T>(x + vec.x, y + vec.y, z + vec.z);
        }
        Vec3<T> operator-(const Vec3<T>& vec) {
            return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
        }
        Vec3<T> operator*(const Vec3<T>& vec) {
            return Vec3<T>(x * vec.x, y * vec.y, z * vec.z);
        }
        Vec3<T> operator/(const Vec3<T>& vec) {
            return Vec3<T>(x / vec.x, y / vec.y, z / vec.z);
        }
        void operator+=(const Vec3<T>& vec) {
            x += vec.x;
            y += vec.y;
            z += vec.z;
        }
        void operator-=(const Vec3<T>& vec) {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
        }
        void operator*=(const Vec3<T>& vec) {
            x *= vec.x;
            y *= vec.y;
            z *= vec.z;
        }
        void operator/=(const Vec3<T>& vec) {
            x /= vec.x;
            y /= vec.y;
            z /= vec.z;
        }

        // Comparison between vectors
        bool operator<(const Vec3<T>& vec) {
            return length() < vec.length();
        }
        bool operator>(const Vec3<T>& vec) {
            return length() > vec.length();
        }
        bool operator<=(const Vec3<T>& vec) {
            return length() <= vec.length();
        }
        bool operator>=(const Vec3<T>& vec) {
            return length() >= vec.length();
        }
        bool operator==(const Vec3<T>& vec) {
            return (x == vec.x && y == vec.y && z == vec.z);
        }
        bool operator!=(const Vec3<T>& vec) {
            return (x != vec.x || y != vec.y || z != vec.z);
        }

        // Array functionality
        T& operator[](int i) {

            switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                return z;
            }
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Vec3<T>& vec) { 
            output << vec.x << " " << vec.y << " " << vec.z;
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Vec3<T>& vec) { 
            input >> vec.x >> vec.y >> vec.z;
            return input;            
        }

        // Predefined vectors
        static Vec3<T> zero();
        static Vec3<T> onex();
        static Vec3<T> oney();
        static Vec3<T> onez();
        static Vec3<T> one();
    };

    // Predefined vectors
    template <typename T>
    Vec3<T> Vec3<T>::zero() {
        return Vec3<T>(0, 0, 0);
    }
    template <typename T>
    Vec3<T> Vec3<T>::onex() {
        return Vec3<T>(1, 0, 0);
    }
    template <typename T>
    Vec3<T> Vec3<T>::oney() {
        return Vec3<T>(0, 1, 0);
    }
    template <typename T>
    Vec3<T> Vec3<T>::onez() {
        return Vec3<T>(0, 0, 1);
    }
    template <typename T>
    Vec3<T> Vec3<T>::one() {
        return Vec3<T>(1, 1, 1);
    }
}

#endif
