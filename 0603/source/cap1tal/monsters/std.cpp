#include <cstdio>
#include <algorithm>

#define int long long

using namespace std;

const int N = 400005;

int n, m, K, Q, cnt, a[N], b[N];

struct Node
{
    int o, x, y, u, v;
};
Node q[N];

struct BIT
{
    int c[N];
    void add(int x, int k)
    {
        for(; x <= cnt; x += x & -x)
            c[x] += k;
    }
    int get(int x)
    {
        if(x <= 0)
            return 0;
        int res = 0;
        for(; x; x -= x & -x)
            res += c[x];
        return res;
    }
};
BIT A, B;

int getpos(int x, int &u, int &v)
{
    int l = 1, r = cnt, res = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(A.get(mid) >= x)
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }
    u = x - A.get(res - 1);
    v = A.get(res) - x;
    return res;
}

int calc(int val, int x, int w, int u, int v, int m)
{
    int p = lower_bound(b + 1, b + 1 + cnt, val) - b - 1, res = 0;
    if(w - 1 > p)
        res += (B.get(w - 1) - B.get(p)) - (A.get(w - 1) - A.get(p)) * val;
    res += max(b[w] - val, 0ll) * u;
    p = lower_bound(b + 1, b + 1 + cnt, val + m + 1) - b - 1;
    if(p > w)
        res += (B.get(p) - B.get(w)) - (A.get(p) - A.get(w)) * (val + 1);
    res += (A.get(cnt) - A.get(max(p, w))) * m;
    res += min(b[w] - val - 1, m) * v;
    return res;
}

int query(int m, int k, int x)
{
    int u, v, w = getpos(x, u, v);
    int res = b[w], l = b[w] - m, r = b[w] - 1;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(calc(mid, x, w, u, v, m) <= m * k)
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }
    return res;
}

int get(int x, int m, int k)
{
    if(x > n)
        return 0;
    int y = query(m, k, x);
    int u, v, w = getpos(x, u, v), t = 0, s = 0;
    int p = lower_bound(b + 1, b + 1 + cnt, y) - b - 1;
    if(w - 1 > p)
        t += (B.get(w - 1) - B.get(p)) - (A.get(w - 1) - A.get(p)) * y;
    t += max(b[w] - y, 0ll) * (u - 1);
    p = lower_bound(b + 1, b + 1 + cnt, y + m) - b - 1;
    s = p > w ? (B.get(p) - B.get(w)) - (A.get(p) - A.get(w)) * y : 0;
    s += (A.get(cnt) - A.get(max(p, w))) * m + min(b[w] - y, m) * (v + 1);
    return B.get(cnt) - B.get(w - 1) - (u - 1) * b[w] - min(m * k - t, s);
}

signed main()
{
    // freopen("monsters.in", "r", stdin);
    // freopen("monsters.out", "w", stdout);

    scanf("%lld%lld%lld%lld", &n, &m, &K, &Q);
    for(int i = 1; i <= n; ++ i)
        scanf("%lld", &a[i]), b[++ cnt] = a[i];

    for(int i = 1; i <= Q; ++ i)
    {
        scanf("%lld", &q[i].o);
        if(q[i].o == 1)
            scanf("%lld%lld%lld", &q[i].x, &q[i].y, &q[i].u);
        if(q[i].o == 2)
            scanf("%lld%lld", &q[i].x, &q[i].y), b[++ cnt] = q[i].y;
        if(q[i].o == 3)
            scanf("%lld%lld%lld%lld", &q[i].x, &q[i].y, &q[i].u, &q[i].v);
    }

    sort(b + 1, b + 1 + cnt);
    cnt = unique(b + 1, b + 1 + cnt) - b - 1;

    for(int i = 1; i <= n; ++ i)
    {
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
        A.add(a[i], 1), B.add(a[i], b[a[i]]);
    }

    for(int i = 1; i <= n; ++ i)
        printf("%lld ", query(m, K, i));
    printf("\n");

    for(int i = 1; i <= Q; ++ i)
    {
        if(q[i].o == 1)
            printf("%lld\n", query(q[i].x, q[i].y, q[i].u));
        if(q[i].o == 2)
        {
            A.add(a[q[i].x], -1), B.add(a[q[i].x], -b[a[q[i].x]]);
            a[q[i].x] = lower_bound(b + 1, b + 1 + cnt, q[i].y) - b;
            A.add(a[q[i].x], 1), B.add(a[q[i].x], b[a[q[i].x]]);
        }
        if(q[i].o == 3)
            printf("%lld\n", get(q[i].u, q[i].x, q[i].y) - get(q[i].v + 1, q[i].x, q[i].y));
    }

    return 0;
}