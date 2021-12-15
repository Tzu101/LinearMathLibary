#ifndef VEC3_H
#define VEC3_H

#include <cmath>

namespace linmath {

    template <typename T>
    class Vec3 {

        public:
        T x;
        T y;
        T z;

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

        void normalize() {
            T len = length();
            x = x / len;
            y = y / len;
            z = z / len;
        }
        void normalize_sum() {
            T sum = x + y + z;
            x = x / sum;
            y = y / sum;
            z = z / sum;
        }

        T length()const {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }
        T sum()const {
            return x + y + z;
        }

        /*Vec3<T> operator++(int) {
            return Vec3<T>(x++, y++);
        }
        Vec3<T> operator--(int) {
            return Vec3<T>(x--, y--);
        }

        Vec3<T> operator-() {
            return Vec3<T>(-x, -y);
        }*/

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
        Vec3<T> operator+=(const T t) {
            return Vec3<T>(x + t, y + t, z + t);
        }
        Vec3<T> operator-=(const T t) {
            return Vec3<T>(x - t, y - t, z - t);
        }
        Vec3<T> operator*=(const T t) {
            return Vec3<T>(x * t, y * t, z * t);
        }
        Vec3<T> operator/=(const T t) {
            return Vec3<T>(x / t, y / t, z / t);
        }
        Vec3<T> operator%=(const T t) {
            return Vec3<T>(x % t, y % t, z % t);
        }

        T operator*(const Vec3<T>& vec) {
            return x*vec.x + y*vec.y + z*vec.z;
        }

        Vec3<T> operator+(const Vec3<T>& vec) {
            return Vec3<T>(x + vec.x, y + vec.y, z + vec.z);
        }
        Vec3<T> operator-(const Vec3<T>& vec) {
            return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
        }
        Vec3<T> operator+=(const Vec3<T>& vec) {
            return Vec3<T>(x + vec.x, y + vec.y, z + vec.z);
        }
        Vec3<T> operator-=(const Vec3<T>& vec) {
            return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
        }

        bool operator<(const Vec3<T>& vec) {
            return this->length() < vec.length();
        }
        bool operator>(const Vec3<T>& vec) {
            return this->length() > vec.length();
        }
        bool operator<=(const Vec3<T>& vec) {
            return this->length() <= vec.length();
        }
        bool operator>=(const Vec3<T>& vec) {
            return this->length() >= vec.length();
        }
        bool operator==(const Vec3<T>& vec) {
            return this->length() == vec.length();
        }
        bool operator!=(const Vec3<T>& vec) {
            return this->length() != vec.length();
        }

        static Vec3<T> zero();
        static Vec3<T> onex();
        static Vec3<T> oney();
        static Vec3<T> onez();
        static Vec3<T> one();
    };

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
        return Vec3<T>(0, 1, 1);
    }
    template <typename T>
    Vec3<T> Vec3<T>::one() {
        return Vec3<T>(1, 1, 1);
    }
}

#endif
