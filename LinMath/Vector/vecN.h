#ifndef VECN_H
#define VECN_H

#include <cmath>
#include <iostream>

namespace linmath {

    template <typename T, size_t N>
    class VecN {

        protected:
        T values[N];

        public:

        // Constructors
        VecN() {}
        VecN(T t) {
            for (size_t i=0; i<N; i++)
                this->values[i] = t;
        }
        VecN(T values[N]) {
            for (size_t i=0; i<N; i++)
                this->values[i] = values[i];
        }

        // Variadic constructor
        template <typename... Ts>
        VecN(T t, Ts... ts) {
            auto n = N;
            *this = VecN(&n, t, ts...);
        }
        template <typename... Ts>
        VecN(auto* n, T t, Ts... ts) : VecN(n, ts...) {
            *n = *n - 1;
            this->values[*n] = t;
        }
        VecN(auto*){}

        // Directional normalization
        T length()const {
            T len = 0;
            for (size_t i=0; i<N; i++)
                len += pow(values[i], 2);
            return sqrt(len);
        }
        void normalize() {
            T len = length();
            for (size_t i=0; i<N; i++)
                values[i] /= len;
        }
        VecN<T, N> normalized() {
            T len = length();
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = values[i] / len;
            return vec;
        }

        // Sum of all values
        T sum()const {
            T sum = 0;
            for (size_t i=0; i<N; i++)
                sum += values[i];
            return sum;
        }

        // Dot product
        T dot(const VecN<T, N>& vec) {
            T dot = 0;
            for (size_t i=0; i<N; i++)
                dot += values[i]*vec[i];
            return dot;
        }

        // Negation
        VecN<T, N> operator-() {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = -values[i];
            return vec;
        }

        // Prefix increment and decrement
        VecN<T, N> operator++() {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = ++values[i];
            return vec;
        }
        VecN<T, N> operator--() {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = --values[i];
            return vec;
        }

        // Postfix increment and decrement
        VecN<T, N> operator++(int) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = values[i]++;
            return vec;
        }
        VecN<T, N> operator--(int) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec[i] = values[i]--;
            return vec;
        }

        // Operations with scalars
        VecN<T, N> operator+(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec = values[i] + t;
            return vec;
        }
        VecN<T, N> operator-(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec = values[i] - t;
            return vec;
        }
        VecN<T, N> operator*(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec = values[i] * t;
            return vec;
        }
        VecN<T, N> operator/(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec = values[i] / t;
            return vec;
        }
        VecN<T, N> operator%(const T t) {
            VecN<T, N> vec = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                vec = values[i] % t;
            return vec;
        }
        void operator+=(const T t) {
            for (size_t i=0; i<N; i++)
                values[i] += t;
        }
        void operator-=(const T t) {
            for (size_t i=0; i<N; i++)
                values[i] -= t;
        }
        void operator*=(const T t) {
            for (size_t i=0; i<N; i++)
                values[i] *= t;
        }
        void operator/=(const T t) {
            for (size_t i=0; i<N; i++)
                values[i] /= t;
        }
        void operator%=(const T t) {
            for (size_t i=0; i<N; i++)
                values[i] %= t;
        }

        // Operations with vectors
        VecN<T, N> operator+(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                out[i] = values[i] + vec[i];
            return out;
        }
        VecN<T, N> operator-(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                out[i] = values[i] - vec[i];
            return out;
        }
        VecN<T, N> operator*(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                out[i] = values[i] * vec[i];
            return out;
        }
        VecN<T, N> operator/(const VecN<T, N>& vec) {
            VecN<T, N> out = VecN<T, N>();
            for (size_t i=0; i<N; i++)
                out[i] = values[i] / vec[i];
            return out;
        }
        void operator+=(const VecN<T, N>& vec) {
            for (size_t i=0; i<N; i++)
                values[i] += vec[i];
        }
        void operator-=(const VecN<T, N>& vec) {
            for (size_t i=0; i<N; i++)
                values[i] -= vec[i];
        }
        void operator*=(const VecN<T, N>& vec) {
            for (size_t i=0; i<N; i++)
                values[i] *= vec[i];
        }
        void operator/=(const VecN<T, N>& vec) {
            for (size_t i=0; i<N; i++)
                values[i] /= vec[i];
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
            for (size_t i=0; i<N; i++)
                if (values[i] != vec[i]) return false;
            return true;
        }
        bool operator!=(const VecN<T, N>& vec) {
            for (size_t i=0; i<N; i++)
                if (values[i] != vec[i]) return true;
            return false;
        }

        // Array functionality
        T& operator[](size_t i) {
            return values[i];
        }
        const T& operator[](size_t i) const {
            return values[i];
        }

        // Input and output
        friend std::ostream& operator<<(std::ostream& output, const VecN<T, N>& vec) { 
            for (size_t i=0; i<N; i++)
                output << vec[i] << " ";
            return output;            
        }
        friend std::istream& operator>>(std::istream& input, VecN<T, N>& vec) { 
            for (size_t i=0; i<N; i++)
                input >> vec[i];
            return input;            
        }

        // Predefined vectors
        static VecN<T, N> zero();
        static VecN<T, N> onei(size_t ind);
        static VecN<T, N> one();
    };

    // Predefined vectors
    template <typename T, size_t N>
    VecN<T, N> VecN<T, N>::zero() {
        return VecN<T, N>(.0);
    }
    template <typename T, size_t N>
    VecN<T, N> VecN<T, N>::onei(size_t ind) {
        VecN<T, N> vec(.0);
        vec[ind] = 1;
        return vec;
    }
    template <typename T, size_t N>
    VecN<T, N> VecN<T, N>::one() {
        return VecN<T, N>(1);
    }
}

#endif
