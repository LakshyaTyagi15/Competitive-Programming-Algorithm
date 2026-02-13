#include <bits/stdc++.h>
using namespace std;

// firstly import Modular Code

struct Comb {
    int n;
    vector<Int> _fact, _invfact, _inv;
    Comb() : n{0}, _fact{1}, _invfact{1}, _inv{0} {};
    Comb(int m) : Comb() {
        f(m);
    }
    void f(int m) {
        if (m <= n) return;
        _fact.resize(m + 1);
        _invfact.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fact[i] = _fact[i - 1] * i;
            _inv[i] = modInverse(Int(i));
            _invfact[i] = _invfact[i - 1] * _inv[i];
        }
        n = m;
    }
    Int fact(int m) {
        f(m);
        return _fact[m];
    }
    Int invfact(int m) {
        f(m);
        return _invfact[m];
    }
    Int inv(int m) {
        f(m);
        return _inv[m];
    }
    Int C(int N, int K) {
        if (K < 0 || K > N) return 0;
        f(N);
        return _fact[N] * _invfact[K] * _invfact[N - K];
    }

    Int P(int N, int K) {
        if (K < 0 || K > N) return 0;
        f(N);
        return _fact[N] * _invfact[N - K];
    }

} comb;

int main()
{
    return 0;
}
