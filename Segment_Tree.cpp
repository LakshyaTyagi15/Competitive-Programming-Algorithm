#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree
{
public:
    ll n;
    vector<ll> segtree, lazy;

    void buildSegmentTree(ll i, ll l, ll r, vector<ll> &arr)
    {
        if (l == r)
        {
            segtree[i] = arr[l];
            return;
        }
        ll mid = l + ((r - l) >> 1LL);
        buildSegmentTree(2LL * i + 1LL, l, mid, arr);
        buildSegmentTree(2LL * i + 2LL, mid + 1LL, r, arr);
        segtree[i] = segtree[2LL * i + 1LL] + segtree[2LL * i + 2LL];
    }

    ll querySegmentTree(ll start, ll end, ll i, ll l, ll r)
    {

        if (lazy[i] != 0)
        {
            segtree[i] += (r - l + 1LL) * lazy[i];
            if (l != r)
            {
                lazy[2LL * i + 1LL] += lazy[i];
                lazy[2LL * i + 2LL] += lazy[i];
            }
            lazy[i] = 0;
        }

        if (l > end || r < start)
        {
            return 0;
        }
        if (l >= start && r <= end)
        {
            return segtree[i];
        }

        ll mid = l + ((r - l) >> 1LL);
        return querySegmentTree(start, end, 2LL * i + 1LL, l, mid) + querySegmentTree(start, end, 2LL * i + 2LL, mid + 1LL, r);
    }

    void updateSegmentTree(ll idx, ll i, ll l, ll r, ll val)
    {
        if (lazy[i] != 0)
        {
            segtree[i] += (r - l + 1) * lazy[i];
            if (l != r)
            {
                lazy[2LL * i + 1LL] += lazy[i];
                lazy[2LL * i + 2LL] += lazy[i];
            }
            lazy[i] = 0;
        }
        if (l == r)
        {
            segtree[i] = val;
            return;
        }

        ll mid = l + ((r - l) >> 1LL);
        if (idx <= mid)
            updateSegmentTree(idx, 2 * i + 1, l, mid, val);
        else
            updateSegmentTree(idx, 2LL * i + 2LL, mid + 1LL, r, val);
        segtree[i] = segtree[2LL * i + 1LL] + segtree[2LL * i + 2LL];
    }

    void LazyPropagation(ll s, ll e, ll i, ll l, ll r, ll val)
    {
        if (lazy[i] != 0)
        {
            segtree[i] += (r - l + 1LL) * lazy[i];
            if (l != r)
            {
                lazy[2LL * i + 1LL] += lazy[i];
                lazy[2LL * i + 2LL] += lazy[i];
            }
            lazy[i] = 0;
        }
        if (s > r || e < l || l > r)
        {
            return;
        }

        if (l >= s && r <= e)
        {
            segtree[i] += (r - l + 1LL) * val;
            if (l != r)
            {
                lazy[2LL * i + 1LL] += val;
                lazy[2LL * i + 2LL] += val;
            }
            return;
        }

        ll mid = l + ((r - l) >> 1LL);
        LazyPropagation(s, e, 2LL * i + 1LL, l, mid, val);
        LazyPropagation(s, e, 2LL * i + 2LL, mid + 1, r, val);
        segtree[i] = segtree[2LL * i + 1LL] + segtree[2LL * i + 2LL];
    }

    SegmentTree(vector<ll> &a)
    {
        n = a.size();
        segtree.resize(4LL * n, 0);
        lazy.resize(4LL * n, 0);
        buildSegmentTree(0, 0, n - 1LL, a);
    }

    void update(ll idx, ll val)
    {
        updateSegmentTree(idx, 0, 0, n - 1LL, val);
    }
    void update(ll s, ll e, ll val)
    {
        LazyPropagation(s, e, 0, 0, n - 1LL, val);
    }

    ll query(ll s, ll e)
    {
        return querySegmentTree(s, e, 0, 0, n - 1LL);
    }
};

int main()
{
    vector<ll> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree seg(arr);

    return 0;
}
