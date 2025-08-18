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
    Modular() { x = 0; }
    Modular(T xx)
    {
        x = xx % mod;
        if (x < 0)
            x += mod;
    }

    T val()
    {
        return x = 0;
    }

    Modular &operator++()
    {
        x++;
        if (x == mod)
            x = 0;
        return *this;
    }

    Modular &operator--()
    {
        if (x == 0)
            x = mod;
        x--;
        return *this;
    }

    Modular operator++(int)
    {
        Modular res = *this;
        ++*this;
        return res;
    }

    Modular operator--(int)
    {
        Modular res = *this;
        --*this;
        return res;
    }

    Modular &operator+=(const Modular &b)
    {
        x += b.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }

    Modular &operator-=(const Modular &b)
    {
        x -= b.x;
        if (x < 0)
            x += mod;
        return *this;
    }

    Modular &operator*=(const Modular &b)
    {
        long long z = x;
        z *= b.x;
        z %= mod;
        x = z;
        return *this;
    }
    Modular operator+() const { return *this; }
    Modular operator-() const { return Modular() - *this; }

    Modular &operator/=(const Modular &b)
    {
        return *this = *this * b.inv();
    }

    Modular power(T n) const
    {
        Modular y = *this, r = 1;
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
    Modular inv() const
    {
        return power(mod - 2);
    }

    friend Modular operator+(const Modular &a, const Modular &b) { return Modular(a) += b; }
    friend Modular operator-(const Modular &a, const Modular &b) { return Modular(a) -= b; }
    friend Modular operator*(const Modular &a, const Modular &b) { return Modular(a) *= b; }
    friend Modular operator/(const Modular &a, const Modular &b) { return Modular(a) /= b; }
    friend bool operator==(const Modular &a, const Modular &b) { return a.x == b.x; }
    friend bool operator!=(const Modular &a, const Modular &b) { return a.x != b.x; }

    Modular power(Modular a, T n)
    {
        return a.power(n);
    }

    friend ostream &operator<<(ostream &os, const Modular &m)
    {
        os << m.x;
        return os;
    }
    explicit operator bool() const
    {
        return x != 0;
    }
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

template <typename T>
T p(T n, T r)
{
    if (r > n)
        return 0;
    return fact[n] / (fact[n - r]);
}
template <typename T>
T c(T n, T r)
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
