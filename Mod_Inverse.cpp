#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9 + 7;
ll modd = 998244353;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll A, ll M) {
    return power(A, M - 2, M);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
