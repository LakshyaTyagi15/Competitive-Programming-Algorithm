#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree
{
public:

    void buildSegmentTree(ll i, ll l, ll r, vector<ll> &segtree, vector<ll> &arr)
    {
        if (l == r)
        {
            segtree[i] = arr[l];
            return;
        }
        ll mid = l + ((r - l) >> 1LL);
        buildSegmentTree(2LL * i + 1LL, l, mid, segtree, arr);
        buildSegmentTree(2LL * i + 2LL, mid + 1LL, r, segtree, arr);
        segtree[i] = segtree[2LL * i + 1LL] + segtree[2LL * i + 2LL];
    }

    ll querySegmentTree(ll start, ll end, ll i, ll l, ll r, vector<ll> &segtree)
    {
        if (l > end || r < start)
        {
            return 0;
        }
        if (l >= start && r <= end)
        {
            return segtree[i];
        }

        ll mid = l + ((r - l) >> 1LL);
        return querySegmentTree(start, end, 2LL * i + 1LL, l, mid, segtree) + querySegmentTree(start, end, 2LL * i + 2LL, mid + 1LL, r, segtree);
    }

    void updateSegmentTree(ll idx, ll i, ll l, ll r, ll val, vector<ll> &segtree)
    {
        if (l == r)
        {
            segtree[i] = val;
            return;
        }

        ll mid = l + ((r - l) >> 1LL);
        if (idx <= mid)
            updateSegmentTree(idx, 2 * i + 1, l, mid, val, segtree);
        else
            updateSegmentTree(idx, 2LL * i + 2LL, mid + 1LL, r, val, segtree);
        segtree[i] = segtree[2LL * i + 1LL] + segtree[2LL * i + 2LL];
    }

    void build(vector<ll>&a, ll n) {
        vector<ll> segtree(4LL * n, -1);
        buildSegmentTree(0, 0, n - 1, segtree, a);
    }
};

int main()
{
    vector<ll>arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree seg;
    seg.build(arr, 8);


    return 0;
}
