#include <bits/stdc++.h>
using namespace std;

template <typename F>
struct Modular
{
    using T = typename F::value_type;
    static constexpr T mod = F::value;

    // using T = typename decay<decltype(F::value)>::type;
    // T mod = F::value;

    T x;
    constexpr Modular() { x = 0; }
    constexpr Modular(T y)
    {
        x = y % mod;
        if (x < 0)
            x += mod;
    }
    constexpr T val()
    {
        return x;
    }
    constexpr Modular &operator++()
    {
        x++;
        if (x == mod)
            x = 0;
        return *this;
    }
    constexpr Modular &operator--()
    {
        if (x == 0)
            x = mod;
        x--;
        return *this;
    }
    constexpr Modular operator++(int32_t)
    {
        Modular res = *this;
        ++*this;
        return res;
    }
    constexpr Modular operator--(int32_t)
    {
        Modular res = *this;
        --*this;
        return res;
    }
    constexpr Modular &operator+=(const Modular &b)
    {
        x += b.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    constexpr Modular &operator-=(const Modular &b)
    {
        x -= b.x;
        if (x < 0)
            x += mod;
        return *this;
    }
    constexpr Modular &operator*=(const Modular &b)
    {
        long long z = x;
        z *= b.x;
        z %= mod;
        x = z;
        return *this;
    }
    constexpr Modular operator+() const { return *this; }
    constexpr Modular operator-() const { return Modular() - *this; }
    constexpr Modular &operator/=(const Modular &b)
    {
        return *this = *this * b.inv();
    }
    constexpr Modular power(T n) const
    {
        Modular y = *this, r = 1;
        if (n < 0)
            return (y.inv()).power(-n);
        while (n)
        {
            if (n & 1)
            {
                r *= y;
            }
            y *= y;
            n >>= 1;
        }
        return r;
    }
    constexpr Modular inv() const
    {
        return power(mod - 2);
    }

    friend constexpr Modular operator+(const Modular &a, const Modular &b) { return Modular(a) += b; }
    friend constexpr Modular operator-(const Modular &a, const Modular &b) { return Modular(a) -= b; }
    friend constexpr Modular operator*(const Modular &a, const Modular &b) { return Modular(a) *= b; }
    friend constexpr Modular operator/(const Modular &a, const Modular &b) { return Modular(a) /= b; }

    template <typename U>
    friend constexpr Modular operator+(const Modular &a, const U &b) { return Modular(a) += Modular(b); }
    template <typename U>
    friend constexpr Modular operator-(const Modular &a, const U &b) { return Modular(a) -= Modular(b); }
    template <typename U>
    friend constexpr Modular operator*(const Modular &a, const U &b) { return Modular(a) *= Modular(b); }
    template <typename U>
    friend constexpr Modular operator/(const Modular &a, const U &b) { return Modular(a) /= Modular(b); }

    template <typename U>
    friend constexpr Modular operator+(const U &a, const Modular &b) { return Modular(a) += b; }
    template <typename U>
    friend constexpr Modular operator-(const U &a, const Modular &b) { return Modular(a) -= b; }
    template <typename U>
    friend constexpr Modular operator*(const U &a, const Modular &b) { return Modular(a) *= b; }
    template <typename U>
    friend constexpr Modular operator/(const U &a, const Modular &b) { return Modular(a) /= b; }

    friend constexpr bool operator==(const Modular &a, const Modular &b) { return a.x == b.x; }
    friend constexpr bool operator!=(const Modular &a, const Modular &b) { return a.x != b.x; }
    template <typename U>
    friend constexpr bool operator==(const Modular &a, const U &b) { return a.x == Modular(b).x; }
    template <typename U>
    friend constexpr bool operator!=(const Modular &a, const U &b) { return a.x != Modular(b).x; }

    friend istream &operator>>(istream &is, Modular &m)
    {
        T y;
        is >> y;
        m = Modular(y);
        return is;
    }
    friend ostream &operator<<(ostream &os, const Modular &m)
    {
        os << m.x;
        return os;
    }
    explicit constexpr operator bool() const
    {
        return x != 0;
    }
    constexpr operator T() const { return x; }
};

// using ModType = int;
// struct Mod { static ModType value; };
// ModType Mod::value;
// ModType& mod = Mod::value;
// using Int = Modular<Mod>;

constexpr int mod = 1e9 + 7;
constexpr int modd = 998244353;
using Int = Modular<integral_constant<decay<decltype(mod)>::type, mod>>;

Int modInverse(Int a)
{
    return a.inv();
}

int main()
{
    return 0;
}
