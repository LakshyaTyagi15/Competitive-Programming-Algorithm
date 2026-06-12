#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(x...)
#endif

using namespace std;

template <typename T>
constexpr T extGcdInverse(T a, T m) {
    T u = 0, v = 1, orig = m;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    return u < 0 ? u + orig : u;
}

template <typename F>
struct Modular {
    using T = typename F::value_type;
    static constexpr T mod = F::value;

    // using T = typename decay<decltype(F::value)>::type;
    // T mod = F::value;

    T x;
    constexpr Modular() { x = 0; }

    template <typename U, enable_if_t<is_integral_v<U>, int> = 0>
    constexpr Modular(U y) {
        using W = conditional_t<is_signed_v<U>, int64_t, uint64_t>;
        W v = static_cast<W>(y) % static_cast<W>(mod);
        if (v < 0) v += mod;
        x = static_cast<T>(v);
    }
    constexpr T val() const { return x; }
    constexpr Modular& operator++() {
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    constexpr Modular& operator--() {
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    constexpr Modular operator++(int32_t) {
        Modular res = *this;
        ++*this;
        return res;
    }
    constexpr Modular operator--(int32_t) {
        Modular res = *this;
        --*this;
        return res;
    }
    constexpr Modular& operator+=(const Modular& b) {
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    constexpr Modular& operator-=(const Modular& b) {
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    constexpr Modular& operator*=(const Modular& b) {
        x = static_cast<T>(static_cast<int64_t>(x) * b.x % mod);
        return *this;
    }
    constexpr Modular operator+() const { return *this; }
    constexpr Modular operator-() const { return Modular() - *this; }
    constexpr Modular& operator/=(const Modular& b) {
        return *this = *this * b.inv();
    }
    template <typename U>
    constexpr Modular power(U n) const {
        Modular y = *this, r = 1;
        if (n < 0) return (y.inv()).power(-n);
        while (n) {
            if (n & 1) {
                r *= y;
            }
            y *= y;
            n >>= 1;
        }
        return r;
    }
    constexpr Modular inv() const { return Modular(extGcdInverse(x, mod)); }

    friend constexpr Modular operator+(const Modular& a, const Modular& b) { return Modular(a) += b; }
    friend constexpr Modular operator-(const Modular& a, const Modular& b) { return Modular(a) -= b; }
    friend constexpr Modular operator*(const Modular& a, const Modular& b) { return Modular(a) *= b; }
    friend constexpr Modular operator/(const Modular& a, const Modular& b) { return Modular(a) /= b; }

    template <typename U>
    friend constexpr Modular operator+(const Modular& a, const U& b) { return Modular(a) += Modular(b); }
    template <typename U>
    friend constexpr Modular operator-(const Modular& a, const U& b) { return Modular(a) -= Modular(b); }
    template <typename U>
    friend constexpr Modular operator*(const Modular& a, const U& b) { return Modular(a) *= Modular(b); }
    template <typename U>
    friend constexpr Modular operator/(const Modular& a, const U& b) { return Modular(a) /= Modular(b); }

    template <typename U>
    friend constexpr Modular operator+(const U& a, const Modular& b) { return Modular(a) += b; }
    template <typename U>
    friend constexpr Modular operator-(const U& a, const Modular& b) { return Modular(a) -= b; }
    template <typename U>
    friend constexpr Modular operator*(const U& a, const Modular& b) { return Modular(a) *= b; }
    template <typename U>
    friend constexpr Modular operator/(const U& a, const Modular& b) { return Modular(a) /= b; }

    friend constexpr bool operator==(const Modular& a, const Modular& b) { return a.x == b.x; }
    friend constexpr bool operator!=(const Modular& a, const Modular& b) { return a.x != b.x; }
    template <typename U>
    friend constexpr bool operator==(const Modular& a, const U& b) { return a.x == Modular(b).x; }
    template <typename U>
    friend constexpr bool operator!=(const Modular& a, const U& b) { return a.x != Modular(b).x; }
    template <typename U>
    friend constexpr bool operator==(const U& a, const Modular& b) { return Modular(a).x == b.x; }
    template <typename U>
    friend constexpr bool operator!=(const U& a, const Modular& b) { return Modular(a).x != b.x; }

    friend constexpr bool operator<(const Modular& a, const Modular& b) { return a.x < b.x; }
    friend constexpr bool operator<=(const Modular& a, const Modular& b) { return a.x <= b.x; }

    friend istream& operator>>(istream& is, Modular& m) {
        int64_t y;
        is >> y;
        m = Modular(y);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Modular& m) {
        os << m.x;
        return os;
    }
    explicit constexpr operator bool() const { return x != 0; }
    explicit constexpr operator T() const { return x; }
    explicit constexpr operator long long() const { return x; }
};

// using ModType = int;
// struct Mod { static ModType value; };
// ModType Mod::value;
// ModType& mod = Mod::value;
// using Int = Modular<Mod>;

constexpr int mod = 1e9 + 7;
constexpr int modd = 998244353;
using Int = Modular<integral_constant<decay<decltype(mod)>::type, mod>>;

template <typename F>
Int power(F a, int64_t n) { return Modular(a).power(n); }

int main() { return 0; }
