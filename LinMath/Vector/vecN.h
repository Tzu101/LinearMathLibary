#ifndef VECN_H
#define VECN_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T, int N>
    class VecN {

        public:
        T values[N];

        // Constructors
        VecN() {}
        VecN(T value) {
            for (int i=0; i<N; i++)
                this->values[i] = value;
        }
        VecN(int values[N]) {
            for (int i=0; i<N; i++)
                this->values[i] = values[i];
        }

        // Directional normalization
        T length()const {
            T len = 0;
            for (int i=0; i<N; i++)
                len += pow(values[i], 2);
            return sqrt(len);
        }
        void normalize() {
            T len = length();
            for (int i=0; i<N; i++)
                values[i] /= len;
        }
        VecN<T, N> normalized() {
            T len = length();
            VecN<T, N> nor = VecN<T, N>();
            for (int i=0; i<N; i++)
                nor[i] = values[i] / len;
            return nor;
        }

        // Sum of all values
        T sum()const {
            T sum = 0;
            for (int i=0; i<N; i++)
                sum += values[i];
            return sum;
        }

        // Dot product
        T dot(const VecN<T, N>& vec) {
            T dot = 0;
            for (int i=0; i<N; i++)
                dot += values[i]*vec.values[i];
            return dot;
        }

        // Negation
        VecN<T, N> operator-() {
            VecN<T, N> neg = VecN<T, N>();
            for (int i=0; i<N; i++)
                neg[i] = -values[i];
            return neg;
        }

        // Prefix increment
        VecN<T, N> operator++() {
            VecN<T, N> inc = VecN<T, N>();
            for (int i=0; i<N; i++)
                inc[i] = ++values[i];
            return inc;
        }
        VecN<T, N> operator--() {
            VecN<T, N> dec = VecN<T, N>();
            for (int i=0; i<N; i++)
                dec[i] = --values[i];
            return dec;
        }

        // Postfix increment
        VecN<T, N> operator++(int) {
            VecN<T, N> inc = VecN<T, N>();
            for (int i=0; i<N; i++)
                inc[i] = values[i]++;
            return inc;
        }
        VecN<T, N> operator--(int) {
            VecN<T, N> dec = VecN<T, N>();
            for (int i=0; i<N; i++)
                dec[i] = values[i]--;
            return dec;
        }

        // Operations with scalars
        VecN<T, N> operator+(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (int i=0; i<N; i++)
                vec = values[i] + t;
            return vec;
        }
        VecN<T, N> operator-(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (int i=0; i<N; i++)
                vec = values[i] - t;
            return vec;
        }
        VecN<T, N> operator*(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (int i=0; i<N; i++)
                vec = values[i] * t;
            return vec;
        }
        VecN<T, N> operator/(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (int i=0; i<N; i++)
                vec = values[i] / t;
            return vec;
        }
        VecN<T, N> operator%(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (int i=0; i<N; i++)
                vec = values[i] % t;
            return vec;
        }
        void operator+=(const T t) {
            for (int i=0; i<N; i++)
                values[i] += t;
        }
        void operator-=(const T t) {
            for (int i=0; i<N; i++)
                values[i] -= t;
        }
        void operator*=(const T t) {
            for (int i=0; i<N; i++)
                values[i] *= t;
        }
        void operator/=(const T t) {
            for (int i=0; i<N; i++)
                values[i] /= t;
        }
        void operator%=(const T t) {
            for (int i=0; i<N; i++)
                values[i] %= t;
        }

        // Operations with vectors
        VecN<T, N> operator+(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (int i=0; i<N; i++)
                out[i] = values[i] + vec.values[i];
            return out;
        }
        VecN<T, N> operator-(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (int i=0; i<N; i++)
                out[i] = values[i] - vec.values[i];
            return out;
        }
        VecN<T, N> operator*(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (int i=0; i<N; i++)
                out[i] = values[i] * vec.values[i];
            return out;
        }
        VecN<T, N> operator/(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (int i=0; i<N; i++)
                out[i] = values[i] / vec.values[i];
            return out;
        }
        void operator+=(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                values[i] += vec.values[i];
        }
        void operator-=(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                values[i] -= vec.values[i];
        }
        void operator*=(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                values[i] *= vec.values[i];
        }
        void operator/=(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                values[i] /= vec.values[i];
        }

        // Comparison between vectors
        bool operator<(const VecN<T, N>& vec) {
            return length() < vec.length();
        }
        bool operator>(const VecN<T, N>& vec) {
            return length() > vec.length();
        }
        bool operator<=(const VecN<T, N>& vec) {
            return length() <= vec.length();
        }
        bool operator>=(const VecN<T, N>& vec) {
            return length() >= vec.length();
        }
        bool operator==(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                if (values[i] != vec.values[i]) return false;
            return true;
        }
        bool operator!=(const VecN<T, N>& vec) {
            for (int i=0; i<N; i++)
                if (values[i] != vec.values[i]) return true;
            return false;
        }

        // Array functionality
        T& operator[](int i) {

            if (i < N)
                return values[i];
            else
                return values[N-1];
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const VecN<T, N>& vec) { 
            for (int i=0; i<N; i++)
                output << vec.values[i] << " ";
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, VecN<T, N>& vec) { 
            for (int i=0; i<N; i++)
                input >> vec[i];
            return input;            
        }

        // Predefined vectors
        static VecN<T, N> zero();
        static VecN<T, N> onen(int n);
        static VecN<T, N> one();
    };

    // Predefined vectors
    template <typename T, int N>
    VecN<T, N> VecN<T, N>::zero() {
        return VecN<T, N>(.0);
    }
    template <typename T, int N>
    VecN<T, N> VecN<T, N>::onen(int n) {
        VecN<T, N> vec = VecN<T, N>(.0);
        vec[n] = 1;
        return vec;
    }
    template <typename T, int N>
    VecN<T, N> VecN<T, N>::one() {
        return VecN<T, N>(1);
    }
}

#endif