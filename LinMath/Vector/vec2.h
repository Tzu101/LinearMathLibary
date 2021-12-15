#ifndef VEC2_H
#define VEC2_H

#include <cmath>

namespace linmath {

    template <typename T>
    class Vec2 {

        public:
        T x;
        T y;

        Vec2() {
            this->x = 0;
            this->y = 0;
        }

        Vec2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        void normalize() {
            T len = length();
            x = x / len;
            y = y / len;
        }
        void normalize_sum() {
            T sum = x + y;
            x = x / sum;
            y = y / sum;
        }

        T length()const {
            return sqrt(pow(x, 2) + pow(y, 2));
        }
        T sum()const {
            return x + y;
        }

        /*Vec2<T> operator++(int) {
            return Vec2<T>(x++, y++);
        }
        Vec2<T> operator--(int) {
            return Vec2<T>(x--, y--);
        }

        Vec2<T> operator-() {
            return Vec2<T>(-x, -y);
        }*/

        Vec2<T> operator+(const T t) {
            return Vec2<T>(x + t, y + t);
        }
        Vec2<T> operator-(const T t) {
            return Vec2<T>(x - t, y - t);
        }
        Vec2<T> operator*(const T t) {
            return Vec2<T>(x * t, y * t);
        }
        Vec2<T> operator/(const T t) {
            return Vec2<T>(x / t, y / t);
        }
        Vec2<T> operator%(const T t) {
            return Vec2<T>(x % t, y % t);
        }
        Vec2<T> operator+=(const T t) {
            return Vec2<T>(x + t, y + t);
        }
        Vec2<T> operator-=(const T t) {
            return Vec2<T>(x - t, y - t);
        }
        Vec2<T> operator*=(const T t) {
            return Vec2<T>(x * t, y * t);
        }
        Vec2<T> operator/=(const T t) {
            return Vec2<T>(x / t, y / t);
        }
        Vec2<T> operator%=(const T t) {
            return Vec2<T>(x % t, y % t);
        }

        T operator*(const Vec2<T>& vec) {
            return x*vec.x + y*vec.y;
        }

        Vec2<T> operator+(const Vec2<T>& vec) {
            return Vec2<T>(x + vec.x, y + vec.y);
        }
        Vec2<T> operator-(const Vec2<T>& vec) {
            return Vec2<T>(x - vec.x, y - vec.y);
        }
        Vec2<T> operator+=(const Vec2<T>& vec) {
            return Vec2<T>(x + vec.x, y + vec.y);
        }
        Vec2<T> operator-=(const Vec2<T>& vec) {
            return Vec2<T>(x - vec.x, y - vec.y);
        }

        bool operator<(const Vec2<T>& vec) {
            return this->length() < vec.length();
        }
        bool operator>(const Vec2<T>& vec) {
            return this->length() > vec.length();
        }
        bool operator<=(const Vec2<T>& vec) {
            return this->length() <= vec.length();
        }
        bool operator>=(const Vec2<T>& vec) {
            return this->length() >= vec.length();
        }
        bool operator==(const Vec2<T>& vec) {
            return this->length() == vec.length();
        }
        bool operator!=(const Vec2<T>& vec) {
            return this->length() != vec.length();
        }

        static Vec2<T> zero();
        static Vec2<T> onex();
        static Vec2<T> oney();
        static Vec2<T> one();
    };

    template <typename T>
    Vec2<T> Vec2<T>::zero() {
        return Vec2<T>(0, 0);
    }
    template <typename T>
    Vec2<T> Vec2<T>::onex() {
        return Vec2<T>(1, 0);
    }
    template <typename T>
    Vec2<T> Vec2<T>::oney() {
        return Vec2<T>(0, 1);
    }
    template <typename T>
    Vec2<T> Vec2<T>::one() {
        return Vec2<T>(1, 1);
    }
}

#endif
