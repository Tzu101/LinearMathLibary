#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T>
    class Vec2 {

        public:
        T x;
        T y;

        // Constructors
        Vec2() {
            this->x = 0;
            this->y = 0;
        }
        Vec2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        // Directional normalization
        T length()const {
            return sqrt(pow(x, 2) + pow(y, 2));
        }
        void normalize() {
            T len = length();
            x = x / len;
            y = y / len;
        }
        Vec2<T> normalized() {
            T len = length();
            return Vec2(x / len, y / len);
        }

        // Sum of all values
        T sum()const {
            return x + y;
        }

        // Dot product
        T dot(const Vec2<T>& vec) {
            return x*vec.x + y*vec.y;
        }

        // Negation
        Vec2<T> operator-() {
            return Vec2<T>(-x, -y);
        }

        // Prefix increment and decrement
        Vec2<T> operator++() {
            x++;
            y++;
            return Vec2<T>(x, y);
        }
        Vec2<T> operator--() {
            x--;
            y--;
            return Vec2<T>(x, y);
        }

        // Postfix increment and decrement
        Vec2<T> operator++(int) {
            Vec2<T> vec(x, y);
            x++;
            y++;
            return vec;
        }
        Vec2<T> operator--(int) {
            Vec2<T> vec(x, y);
            x--;
            y--;
            return vec;
        }

        // Operations with scalars
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
        void operator+=(const T t) {
            x += t;
            y += t;
        }
        void operator-=(const T t) {
            x -= t;
            y -= t;
        }
        void operator*=(const T t) {
            x *= t;
            y *= t;
        }
        void operator/=(const T t) {
            x /= t;
            y /= t;
        }
        void operator%=(const T t) {
            x %= t;
            y %= t;
        }

        // Operations with vectors
        Vec2<T> operator+(const Vec2<T>& vec) {
            return Vec2<T>(x + vec.x, y + vec.y);
        }
        Vec2<T> operator-(const Vec2<T>& vec) {
            return Vec2<T>(x - vec.x, y - vec.y);
        }
        Vec2<T> operator*(const Vec2<T>& vec) {
            return Vec2<T>(x * vec.x, y * vec.y);
        }
        Vec2<T> operator/(const Vec2<T>& vec) {
            return Vec2<T>(x / vec.x, y / vec.y);
        }
        void operator+=(const Vec2<T>& vec) {
            x += vec.x;
            y += vec.y;
        }
        void operator-=(const Vec2<T>& vec) {
            x -= vec.x;
            y -= vec.y;
        }
        void operator*=(const Vec2<T>& vec) {
            x *= vec.x;
            y *= vec.y;
        }
        void operator/=(const Vec2<T>& vec) {
            x /= vec.x;
            y /= vec.y;
        }

        // Comparison between vectors
        bool operator<(const Vec2<T>& vec) {
            return length() < vec.length();
        }
        bool operator>(const Vec2<T>& vec) {
            return length() > vec.length();
        }
        bool operator<=(const Vec2<T>& vec) {
            return length() <= vec.length();
        }
        bool operator>=(const Vec2<T>& vec) {
            return length() >= vec.length();
        }
        bool operator==(const Vec2<T>& vec) {
            return (x == vec.x && y == vec.y);
        }
        bool operator!=(const Vec2<T>& vec) {
            return (x != vec.x || y != vec.y);
        }

        // Array functionality
        T& operator[](int i) {

            switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            default:
                return y;
            }
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const Vec2<T>& vec) { 
            output << vec.x << " " << vec.y;
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, Vec2<T>& vec) { 
            input >> vec.x >> vec.y;
            return input;            
        }

        // Predefined vectors
        static Vec2<T> zero();
        static Vec2<T> onex();
        static Vec2<T> oney();
        static Vec2<T> one();
    };

    // Predefined vectors
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
