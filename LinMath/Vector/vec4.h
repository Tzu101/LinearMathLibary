#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Vec4 {

        public:
        T x;
        T y;
        T z;
        T w;

        // Constructors
        Vec4() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
            this->w = 0;
        }
        Vec4(T x, T y, T z, T w) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        // Directional normalization
        T length()const {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
        }
        void normalize() {
            T len = length();
            x = x / len;
            y = y / len;
            z = z / len;
            w = w / len;
        }
        Vec4<T> normalized() {
            T len = length();
            return Vec4(x / len, y / len, z / len, w / len);
        }

        // Sum of all values
        T sum()const {
            return x + y + z + w;
        }

        // Dot product
        T dot(const Vec4<T>& vec) {
            return x*vec.x + y*vec.y + z*vec.z + w*vec.w;
        }

        // Negation
        Vec4<T> operator-() {
            return Vec4<T>(-x, -y, -z, -w);
        }

        // Prefix increment and decrement
        Vec4<T> operator++() {
            x++;
            y++;
            z++;
            w++;
            return Vec4<T>(x, y, z);
        }
        Vec4<T> operator--() {
            x--;
            y--;
            z--;
            w--;
            return Vec4<T>(x, y, z);
        }

        // Postfix increment and decrement
        Vec4<T> operator++(int) {
            Vec4<T> vec(x, y, z, w);
            x++;
            y++;
            z++;
            w++;
            return vec;
        }
        Vec4<T> operator--(int) {
            Vec4<T> vec(x, y, z, w);
            x--;
            y--;
            z--;
            w--;
            return vec;
        }

        // Operations with scalars
        Vec4<T> operator+(const T t) {
            return Vec4<T>(x + t, y + t, z + t, w + t);
        }
        Vec4<T> operator-(const T t) {
            return Vec4<T>(x - t, y - t, z - t, w - t);
        }
        Vec4<T> operator*(const T t) {
            return Vec4<T>(x * t, y * t, z * t, w * t);
        }
        Vec4<T> operator/(const T t) {
            return Vec4<T>(x / t, y / t, z / t, w / t);
        }
        Vec4<T> operator%(const T t) {
            return Vec4<T>(x % t, y % t, z % t, w % t);
        }
        Vec4<T> operator+=(const T t) {
            x += t;
            y += t;
            z += t;
            w += t;
        }
        Vec4<T> operator-=(const T t) {
            x -= t;
            y -= t;
            z -= t;
            w -= t;
        }
        Vec4<T> operator*=(const T t) {
            x *= t;
            y *= t;
            z *= t;
            w *= t;
        }
        Vec4<T> operator/=(const T t) {
            x /= t;
            y /= t;
            z /= t;
            w /= t;
        }
        Vec4<T> operator%=(const T t) {
            x %= t;
            y %= t;
            z %= t;
            w %= t;
        }

        // Operations with vectors
        Vec4<T> operator+(const Vec4<T>& vec) {
            return Vec4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
        }
        Vec4<T> operator-(const Vec4<T>& vec) {
            return Vec4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
        }
        Vec4<T> operator*(const Vec4<T>& vec) {
            return Vec4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
        }
        Vec4<T> operator/(const Vec4<T>& vec) {
            return Vec4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
        }
        void operator+=(const Vec4<T>& vec) {
            x += vec.x;
            y += vec.y;
            z += vec.z;
            w += vec.w;
        }
        void operator-=(const Vec4<T>& vec) {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
            w -= vec.w;
        }
        void operator*=(const Vec4<T>& vec) {
            x *= vec.x;
            y *= vec.y;
            z *= vec.z;
            w *= vec.w;
        }
        void operator/=(const Vec4<T>& vec) {
            x /= vec.x;
            y /= vec.y;
            z /= vec.z;
            w /= vec.w;
        }

        // Comparison between vectors
        bool operator<(const Vec4<T>& vec) {
            return length() < vec.length();
        }
        bool operator>(const Vec4<T>& vec) {
            return length() > vec.length();
        }
        bool operator<=(const Vec4<T>& vec) {
            return length() <= vec.length();
        }
        bool operator>=(const Vec4<T>& vec) {
            return length() >= vec.length();
        }
        bool operator==(const Vec4<T>& vec) {
            return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
        }
        bool operator!=(const Vec4<T>& vec) {
            return (x != vec.x || y != vec.y || z != vec.z || w != vec.w);
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
            case 3:
                return w;
            default:
                return w;
            }
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Vec4<T>& vec) { 
            output << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Vec4<T>& vec) { 
            input >> vec.x >> vec.y >> vec.z >> vec.w;
            return input;            
        }

        // Predefined vectors
        static Vec4<T> zero();
        static Vec4<T> onex();
        static Vec4<T> oney();
        static Vec4<T> onez();
        static Vec4<T> onew();
        static Vec4<T> one();
    };

    // Predefined vectors
    template <typename T>
    Vec4<T> Vec4<T>::zero() {
        return Vec4<T>(0, 0, 0, 0);
    }
    template <typename T>
    Vec4<T> Vec4<T>::onex() {
        return Vec4<T>(1, 0, 0, 0);
    }
    template <typename T>
    Vec4<T> Vec4<T>::oney() {
        return Vec4<T>(0, 1, 0, 0);
    }
    template <typename T>
    Vec4<T> Vec4<T>::onez() {
        return Vec4<T>(0, 0, 1, 0);
    }
    template <typename T>
    Vec4<T> Vec4<T>::onew() {
        return Vec4<T>(0, 0, 0, 1);
    }
    template <typename T>
    Vec4<T> Vec4<T>::one() {
        return Vec4<T>(1, 1, 1, 1);
    }

    // Overload functions
    template <typename T, typename K>
    Vec4<T> operator+(const K k, const Vec4<T>& vec) {
        return Vec4<T>(vec.x + k, vec.y + k, vec.z + k, vec.w + k);
    }
    template <typename T, typename K>
    Vec4<T> operator-(const K k, const Vec4<T>& vec) {
        return Vec4<T>(vec.x - k, vec.y - k, vec.z - k, vec.w - k);
    }
    template <typename T, typename K>
    Vec4<T> operator*(const K k, const Vec4<T>& vec) {
        return Vec4<T>(vec.x * k, vec.y * k, vec.z * k, vec.w * k);
    }
    template <typename T, typename K>
    Vec4<T> operator/(const K k, const Vec4<T>& vec) {
        return Vec4<T>(vec.x / k, vec.y / k, vec.z / k, vec.w / k);
    }
    template <typename T, typename K>
    Vec4<T> operator%(const K k, const Vec4<T>& vec) {
        return Vec4<T>(vec.x % k, vec.y % k, vec.z % k, vec.w % k);
    }
}

#endif
