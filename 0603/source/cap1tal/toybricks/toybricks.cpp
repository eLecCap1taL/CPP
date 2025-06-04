#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 500005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, a[N];
namespace sub1 {
    int cnt, tot, f[4][N], rt, ls[N << 5], rs[N << 5];
    struct Line {
        int k, b;
        int get(int x) { return x * k + b; }
    } s[N];
    int t[N << 5];
    void upd(int &p, int u, int l, int r) {
        if (!p) p = ++tot, t[p] = ls[p] = rs[p] = 0;
        int mid = l + r >> 1;
        if (s[t[p]].get(mid) < s[u].get(mid))
            swap(t[p], u);
        if (l == r) return;
        if (s[t[p]].get(l) < s[u].get(l)) 
            upd(ls[p], u, l, mid);
        if (s[t[p]].get(r) < s[u].get(r))
            upd(rs[p], u, mid + 1, r);
    }
    int query(int p, int x, int l, int r) {
        int res = s[t[p]].get(x);
        if (l == r || !p) return res;
        int mid = l + r >> 1;
        if (x <= mid) res = max(res, query(ls[p], x, l, mid));
        else res = max(res, query(rs[p], x, mid + 1, r));
        return res;
    }
    int ans[4];
    void solve() {
        memset(f, 0xcf, sizeof f);
        f[0][0] = 0;
        s[0] = {0, -inf};
        F(k, 1, 3) {
            cnt = tot = rt = 0;
            F(i, 1, n) {
                s[++cnt] = {-a[i - 1], f[k - 1][i - 1]};
                upd(rt, cnt, 1, n);
                f[k][i] = query(rt, n + 1 - i, 1, n) + a[i] * (n + 1 - i);
            }
            ans[k] = max(ans[k], *max_element(f[k], f[k] + n + 1));
        }
        memset(f, 0xcf, sizeof f);
        f[0][n + 1] = 0;
        F(k, 1, 3) {
            cnt = tot = rt = 0;
            dF(i, n, 1) {
                s[++cnt] = {i + 1, f[k - 1][i + 1]};
                upd(rt, cnt, 1, 500000);
                f[k][i] = query(rt, a[i], 1, 500000) - a[i] * i;
            }
            ans[k] = max(ans[k], *max_element(f[k], f[k] + n + 1));
            cout << ans[k] << '\n';
        }
    }
}
int calc1() {
    static int s[N], L[N], R[N], top;
    s[top = 0] = 0;
    F(i, 1, n) {
        while (top && a[i] <= a[s[top]]) top--;
        L[i] = s[top], s[++top] = i;
    }
    s[top = 0] = n + 1;
    dF(i, n, 1) {
        while (top && a[i] <= a[s[top]]) top--;
        R[i] = s[top], s[++top] = i;
    }
    int res = 0;
    F(i, 1, n) {
        res = max(res, (R[i] - L[i] - 1) * a[i]);
    }
    return res;
}
int calc2() {
    return 0;
}
int calc3() {
    return 0;
}
signed main() {
    freopen("toybricks.in", "r", stdin);
    freopen("toybricks.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    F(i, 1, n) cin >> a[i];
    if (is_sorted(a + 1, a + n + 1)) sub1::solve();
    else cout << calc1() << '\n' << calc2() << '\n' << calc3();
    return 0;
}