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
const ll mod = 1e9 + 7;
const ll modd = 998244353;

template<typename T>
struct Matrix {
    vector<vector<T>> mat;
    ll n, m;
    Matrix(ll _n, ll _m) : n(_n), m(_m) {
        mat.resize(n, vector<T>(m, 0));
    }
    Matrix(const vector<vector<T>> &a) : n((ll)a.size()), m((ll)a[0].size()) {
        mat = a;
    }
    Matrix operator * (const Matrix &b) const {
        assert(m == b.n);
        Matrix res(n, b.m);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < b.m; j++) {
                for (ll k = 0; k < m; k++) {
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator + (const Matrix &b) const {
        assert(n == b.n && m == b.m);
        Matrix res(n, m);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                res.mat[i][j] = mat[i][j] + b.mat[i][j];
            }
        }
        return res;
    }

    Matrix operator += (const Matrix &b) {
        assert(n == b.n && m == b.m);
        *this = (*this) + b;
        return *this;
    }

    Matrix operator *= (const Matrix &b) {
        assert(n == b.n && m == b.m);
        *this = (*this) * b;
        return *this;
    }

    Matrix pow(ll p) const {
        assert(n == m);
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res.mat[i][i] = 1;
        Matrix base = *this;
        while (p) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};

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
    
    for (int i = 1; i <= t; i++) {
        cerr << "Testcase No. - " << i << "\n";
        solve();    
    }

    return 0;
}
