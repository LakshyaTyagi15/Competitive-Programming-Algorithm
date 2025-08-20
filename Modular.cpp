#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(x...)
#endif

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

template <typename T, T mod>
struct Modular
{
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
        return x = 0;
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

    constexpr Modular operator++(int)
    {
        Modular res = *this;
        ++*this;
        return res;
    }

    constexpr Modular operator--(int)
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

    friend constexpr Modular operator+(const Modular &a, T &b) { return Modular(a) += b; }
    friend constexpr Modular operator-(const Modular &a, T &b) { return Modular(a) -= b; }
    friend constexpr Modular operator*(const Modular &a, T &b) { return Modular(a) *= b; }
    friend constexpr Modular operator/(const Modular &a, T &b) { return Modular(a) /= b; }
    friend constexpr bool operator==(const Modular &a, T &b) { return a.x == b.x; }
    friend constexpr bool operator!=(const Modular &a, T &b) { return a.x != b.x; }

    Modular power(Modular a, T n)
    {
        return a.power(n);
    }

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
using mll = Modular<ll, ll(1e9 + 7)>;
vector<mll> fact;

void f(ll n = 1e6 + 10)
{
    fact.resize(n + 1);
    fact[0] = 1;

    for (ll i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i;
    }
}

template <typename T1, typename T2>
ll p(T1 n, T2 r)
{
    if (r > n)
        return 0;
    return fact[n] / (fact[n - r]);
}
template <typename T1, typename T2>
ll c(T1 n, T2 r)
{
    if (r > n)
        return 0;
    return (fact[n] / fact[r]) / fact[n - r];
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
