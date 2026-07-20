#include <bits/stdc++.h>

using namespace std;

struct Sum {
    int64_t x;
    static const int64_t segfactor = 0;
    static const int64_t updatefactor = 1;

    Sum(int64_t val = 0) {
        x = val;
    }

    Sum operator+(const Sum& other) {
        return x + other.x;
    }

    Sum operator*(const Sum& other) {
        return x * other.x;
    }

    void add(int64_t d, int64_t val) {
        x = x * updatefactor + d * val;
    }
};

struct Max {
    int64_t x;
    static const int64_t segfactor = -1000000000000000000LL;
    static const int64_t updatefactor = 0;

    Max(int64_t val = segfactor) {
        x = val;
    }

    Max operator+(const Max& other) {
        return max(x, other.x);
    }

    Max operator*(const Max& other) {
        return x * other.x;
    }

    void add(int64_t d, int64_t val) {
        x = x * updatefactor + val;
    }
};

struct Min {
    int64_t x;
    static const int64_t segfactor = 1000000000000000000LL;
    static const int64_t updatefactor = 0;

    Min(int64_t val = segfactor) {
        x = val;
    }

    Min operator+(const Min& other) {
        return min(x, other.x);
    }

    Min operator*(const Min& other) {
        return x * other.x;
    }

    void add(int64_t d, int64_t val) {
        x = x * updatefactor + val;
    }
};

struct Xor {
    int64_t x;
    static const int64_t segfactor = 0;
    static const int64_t updatefactor = 1;

    Xor(int64_t val = 0) {
        x = val;
    }

    Xor operator+(const Xor& other) {
        return x ^ other.x;
    }

    Xor operator*(const Xor& other) {
        return x * other.x;
    }

    void add(int64_t d, int64_t val) {
        if (d & 1) {
            x = (x * updatefactor) ^ val;
        }
    }
};

template<typename Info, typename Tag>
struct SegmentTree {
    int n;
    vector<Info> seg;
    vector<Tag> lazy;
    vector<bool> has_lazy;

    void pull(int i) {
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    template<typename T>
    void push(int i, int l, int r, T val) {
        seg[i].add(r - l + 1, val.x);

        if (l != r) {
            lazy[2 * i + 1].add(1, val.x);
            lazy[2 * i + 2].add(1, val.x);
            has_lazy[2 * i + 1] = true;
            has_lazy[2 * i + 2] = true;
        }
    }

    SegmentTree(int m) {
        n = m;
        if (n > 0) {
            seg.resize(4 * n + 10, Info(Info::segfactor));
            lazy.resize(4 * n + 10, Tag());
            has_lazy.resize(4 * n + 10, false);
        }
    }

    template<typename T>
    SegmentTree(vector<T> a) {
        n = a.size();
        if (n > 0) {
            seg.resize(4 * n + 10, Info(Info::segfactor));
            lazy.resize(4 * n + 10, Tag());
            has_lazy.resize(4 * n + 10, false);
            init(a);
        }
    }

    template<typename T>
    void init(vector<T> &a) {
        if (n > 0) build(0, 0, n - 1, a);
    }

    template<typename T>
    void build(int i, int l, int r, vector<T> &a) {
        if (l == r) {
            seg[i].x = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, a);
        build(2 * i + 2, mid + 1, r, a);
        pull(i);
    }

    template<typename T>
    void update(int i, int l, int r, int x, int y, T val) {
        if (has_lazy[i]) {
            push(i, l, r, lazy[i]);
            lazy[i] = Tag();
            has_lazy[i] = false;
        }
        if (x > r || y < l || l > r) return;
        if (x <= l && r <= y) {
            push(i, l, r, val);
            return;
        }
        int mid = l + (r - l) / 2;
        update(2 * i + 1, l, mid, x, y, val);
        update(2 * i + 2, mid + 1, r, x, y, val);
        pull(i);
    }

    Info query(int i, int l, int r, int x, int y) {
        if (has_lazy[i]) {
            push(i, l, r, lazy[i]);
            lazy[i] = Tag();
            has_lazy[i] = false;
        }
        if (x > r || y < l || l > r) {
            return Info(Info::segfactor);
        }
        if (x <= l && r <= y) {
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, x, y) + query(2 * i + 2, mid + 1, r, x, y);
    }

    template<typename T>
    void apply(int i, T val) {
        if (n > 0) update(0, 0, n - 1, i, i, val);
    }

    template<typename T>
    void apply(int l, int r, T val) {
        if (n > 0) update(0, 0, n - 1, l, r, val);
    }

    auto get(int i) {
        return query(0, 0, n - 1, i, i).x;
    }

    auto get(int l, int r) {
        return query(0, 0, n - 1, l, r).x;
    }
};

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
