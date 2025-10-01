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
struct Fenwick {
    ll n;
    vector<T> bit;

    Fenwick(ll size = 0) {
        this->n = size;
        bit.assign(size + 1, T(0));
    }

    template<typename U>
    Fenwick(const vector<U> &a) : Fenwick((ll)a.size()) {
        for (ll i = 0; i < (ll)a.size(); i++) {
            add(i, T(a[i]));
        }
    }

    void add(ll idx, const T &val) {
        for (ll i = idx + 1; i <= n; i += i & -i)
            bit[i] += val;
    }

    T query(ll idx) const {
        T ans = 0;
        for (ll i = idx + 1; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }

    T query(ll l, ll r) const {
        return query(r) - (l > 0 ? query(l - 1) : T(0));
    }
};

template<typename U>
Fenwick(const vector<U>&) -> Fenwick<U>;

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
