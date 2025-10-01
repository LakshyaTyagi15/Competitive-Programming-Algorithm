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

template<class Info, class Tag>
struct SegmentTree {
    ll n;
    vector<tuple<Info, Tag>> seg;
    SegmentTree(ll _n) : n(_n) {
        seg.resize(4 * n + 10);
    }
    SegmentTree(const vector<Info> &a) : n((ll)a.size()) {
        seg.resize(4 * n + 10);
        build(0, 0, n - 1, a);
    }
    void build(ll i, ll l, ll r, const vector<Info> &a) {
        if (l == r) {
            get<0>(seg[i]) = a[i];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * i + 1, l, mid, a);
        build(2 * i + 2, mid + 1, r, a);
        get<0>(seg[i]) = get<0>(seg[2 * i + 1]) + get<0>(seg[2 * i + 2]);
    }

    ll query(ll x) {
        return query(0, 0, n - 1, x, x);
    }

    ll query(ll x, ll y) {
        return query(0, 0, n - 1, x, y);
    }
    
    Info query(ll i, ll l, ll r, ll x, ll y) {

        if (get<1>(seg[i]) != 0) {
            get<0>(seg[i]) += (r - l + 1) * get<1>(seg[i]);
            if (l != r) {
                get<1>(seg[2 * i + 1]) += get<1>(seg[i]);
                get<1>(seg[2 * i + 2]) += get<1>(seg[i]);
            }
            get<1>(seg[i]) = 0;
        }

        if (r < x || l > y) return 0;
        if ( l >= x && r <= y) return get<0>(seg[i]);
        ll mid = (l + r) / 2;
        return query(2 * i + 1, l, mid, x, y) + query(2 * i + 2, mid + 1, r, x, y);
    }

    template<typename T>
    void update(ll x, ll y, T val) {
        update(0, 0, n - 1, x, y, val);
    }
    template<typename T>
    void update(ll idx, T val) {
        update(0, 0, n - 1, idx, idx, val);
    }
    template<typename T>
    void update(ll i, ll l, ll r, ll x, ll y, T val) {

        if (get<1>(seg[i]) != 0) {
            get<0>(seg[i]) += (r - l + 1) * get<1>(seg[i]);
            if (l != r) {
                get<1>(seg[2 * i + 1]) += get<1>(seg[i]);
                get<1>(seg[2 * i + 2]) += get<1>(seg[i]);
            }
            get<1>(seg[i]) = 0;
        }

        if (r < x || l > y) return;
        if (l >= x && r <= y) {
            get<0>(seg[i]) += (r - l + 1) * val;
            if (l != r) {
                get<1>(seg[2 * i + 1]) += val;
                get<1>(seg[2 * i + 2]) += val;
            }
            return;
        }
        ll mid = (l + r) / 2;
        update(2 * i + 1, l, mid, x, y, val);
        update(2 * i + 2, mid + 1, r, x, y, val);
        get<0>(seg[i]) = get<0>(seg[2 * i + 1]) + get<0>(seg[2 * i + 2]);
    }
};

struct Info {
    ll val = 0;                             // if max, min is being used intialize val = -1e9 or val = 1e9 for handling all types of query
    Info(ll v = 0) : val(v) {}
    operator ll() const { return val; }
};

Info operator+(const Info &a, const Info &b) {
    return Info(a.val + b.val);                // Use max, min, gcd, lcm, etc as per requirement like max(a.val, b.val)
}
Info operator += (Info &a, const Info &b) {
    a.val = a.val + b.val;                     // If we have to change value then a.val = b.val else handle like + operator;
    return a;
}

struct Tag {
    ll val = 0;
    Tag(ll v = 0) : val(v) {}
    operator ll() const { return val; }
};

Tag operator += (Tag &a, const Tag &b) {
    a.val = a.val + b.val;                   // If we have to change value then a.val = b.val else handle like + operator of Info;
    return a;
}

template<typename T, typename U>
SegmentTree(const vector<T>&) -> SegmentTree<T, U>;

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
