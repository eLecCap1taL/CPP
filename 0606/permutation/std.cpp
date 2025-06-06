#include <bits/stdc++.h>
#define File(name) freopen(#name".in", "r", stdin); freopen(#name".out", "w", stdout);
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<typename T>
inline T read(){
    T n = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return f * n;
}
template<typename T>
void write(T n){
    if(n < 0) return putchar('-'), write(-n);
    if(n / 10) write(n / 10);
    putchar(n % 10 + '0');
}
void input() {}
template<typename Type, typename... Types>
void input(Type &arg, Types &...args){
    arg = read<Type>();
    input(args...);
}
namespace Main{
    const int MOD = 998244353;
    const int N = 1000005;
    int n, q, a[N];
    ll fac[N], ifac[N], suf[N], f[N];
    pair<int, int> s[N];
    ll qpow(ll n, ll k){
        ll res = 1;
        while(k > 0){
            if(k & 1) res = res * n % MOD;
            n = n * n % MOD;
            k >>= 1;
        }
        return res;
    }
    ll binom(int n, int k){
        return fac[n] * ifac[n - k] % MOD * ifac[k] % MOD;
    }
    void Main(){
        fac[0] = 1;
        for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
        ifac[N - 1] = qpow(fac[N - 1], MOD - 2);
        for(int i = N - 2; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
        input(n, q);
        for(int i = 1; i <= n; i++) input(a[i]);
        vector<int> v(a + 1, a + n + 1);
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && v[i] == v[j]) j++;
            s[v[i]] = {i + 1, j};
        }
        s[(int)1e6 + 1] = {1, 0};
        for(int i = 1e6; i >= 1; i--){
            if(!s[i].first) s[i].first = s[i + 1].second + 1, s[i].second = s[i + 1].second;
        }
        for(int i = n; i >= 0; i--) suf[i] = (suf[i + 2] + binom(n, i)) % MOD;
        for(int i = 1; i <= n; i++){
            int p = min(0, i - n / 2);
            f[i] = (n / 2 + p) * binom(n, i - 2 * p) % MOD - suf[i - 2 * p + 2];
            f[i] = (f[i] + MOD) * fac[i] % MOD * fac[n - i] % MOD;
        }
        for(int i = n; i > 1; i--) f[i] = (f[i] - f[i - 1] + MOD) % MOD;
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans = (ans + f[i] * v[i - 1]) % MOD;
        while(q--){
            int x, y; input(x, y);
            if(y < 0){
                ans = (ans - f[s[a[x]].second] * a[x] % MOD + MOD) % MOD;
                s[a[x]].second--;
                for(int i = a[x] - 1; i > a[x] + y; i--){
                    ans = (ans + (f[s[i].first - 1] - f[s[i].second] + MOD) * i) % MOD;
                    s[i].first--, s[i].second--;
                }
                ans = (ans + f[s[a[x] + y].first - 1] * (a[x] + y)) % MOD;
                s[a[x] + y].first--;
                a[x] += y;
            }
            else if(y > 0){
                ans = (ans - f[s[a[x]].first] * a[x] % MOD + MOD) % MOD;
                s[a[x]].first++;
                for(int i = a[x] + 1; i < a[x] + y; i++){
                    ans = (ans + (f[s[i].second + 1] - f[s[i].first] + MOD) * i) % MOD;
                    s[i].first++, s[i].second++;
                }
                ans = (ans + f[s[a[x] + y].second + 1] * (a[x] + y)) % MOD;
                s[a[x] + y].second++;
                a[x] += y;
            }
            write(ans), puts("");
        }
        return;
    }
} // namespace Main
int main(){
// #ifdef Liuxizai
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
// #else
//     File(permutation)
// #endif // Liuxizai
    Main::Main();
    return 0;
}