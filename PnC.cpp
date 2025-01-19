#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const ll modd = 998244353;


ll modInverse(ll a, ll m) {
    ll res = 1, p = m - 2ll;
    while (p) {
        if (p & 1ll) res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1ll;
    }
    return res;
}

vector<ll> fact, invFact;

void f(ll maxN) {
    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);
    fact[0] = invFact[0] = 1;

    for (ll i = 1; i <= maxN; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    for (ll i = 0; i <= maxN; ++i) {
        invFact[i] = modInverse(fact[i], mod);
    }
}

ll p(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * invFact[n - r] % mod;
}

ll c(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f(1e5);

    return 0;
}
