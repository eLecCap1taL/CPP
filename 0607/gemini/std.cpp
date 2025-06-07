#include <bits/stdc++.h>

const int mod = 1e9 + 7, iv2 = (mod + 1) / 2;

int qpow(int a, int b) {
  assert(b >= 0);
  int ans(1);
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
  }
  return ans;
}

using v1 = std::vector<int>;
using v2 = std::vector<v1>;
using v3 = std::vector<v2>;

int main() {
  #ifndef LOCAL
  freopen("gemini0.in", "r", stdin);
//   freopen("gemini.out", "w", stdout);
  #endif
  int n; scanf("%d", &n);
  v3 cnt(2, v2(2, v1(2)));
  cnt[0][0][0] = 1;
  std::vector<std::vector<int>> f(n, std::vector<int>(2));
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    v3 g(2, v2(2, v1(2)));
    int c, a; scanf("%d %d", &c, &a);
    for (int t : {0, 1}) for (int p : {0, 1}) for (int q : {0, 1}) {
      int x = 1ll * cnt[t][p][q] * qpow(2, 1ll * a * (a - 1) / 2 % (mod - 1)) % mod;
      if (!x) continue;
      if (c != 1) {
        if (q) {
          int s = qpow(2, (sum - 1) % (mod - 1));
          (g[t][p][q] += 1ll * x * qpow(s, a) % mod) %= mod;
          (g[t ^ 1][1][q] += 1ll * x * qpow(s, a) % mod * qpow(2, a - 1) % mod) %= mod;
          (g[t][1][q] += 1ll * x * qpow(s, a) % mod * (qpow(2, a - 1) - 1) % mod) %= mod;
        } else {
          int s = qpow(2, sum % (mod - 1));
          (g[t ^ (a & 1)][1][q] += 1ll * x * qpow(s, a) % mod) %= mod;
        }
      }
      if (c != 0) {
        if (p) {
          int s = qpow(2, (sum - 1) % (mod - 1)); 
          (g[t][p][q] += 1ll * x * qpow(s, a) % mod) %= mod;
          (g[t ^ 1][p][1] += 1ll * x * qpow(s, a) % mod * qpow(2, a - 1) % mod) %= mod;
          (g[t][p][1] += 1ll * x * qpow(s, a) % mod * (qpow(2, a - 1) - 1) % mod) %= mod;
        } else {
          int s = qpow(2, sum % (mod - 1));
          (g[t ^ (a & 1)][p][1] += 1ll * x * qpow(s, a) % mod) %= mod;
        }
      }
    } 
    sum += a, cnt.swap(g);
  }
  int ans(0);
  for (int p : {0, 1}) for (int q : {0, 1}) (ans += cnt[1][p][q]) %= mod;
  printf("%d\n", ans);
}