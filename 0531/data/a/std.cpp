#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int mod = 1e9 + 7;
struct mint{
	int x;
	mint():x(0){}
	mint(int64_t y, bool o = 0){x = o ? y : (y % mod + mod) % mod;}
	friend const mint qpow(mint a, int64_t b);
	friend mint operator+(const mint &a, const mint &b){mint res(a.x + b.x, 1); if(res.x >= mod) res.x -= mod; return res;}
	friend mint operator-(const mint &a, const mint &b){mint res(a.x - b.x, 1); if(res.x < 0) res.x += mod; return res;}
	friend mint operator*(const mint &a, const mint &b){return mint(1ll * a.x * b.x % mod, 1);}
	friend mint operator/(const mint &a, const mint &b){return mint(1ll * a.x * qpow(b, mod - 2).x % mod, 1);}
	friend bool operator!(const mint &a){return !a.x;}
	friend bool operator==(const mint &a, const mint &b){return a.x == b.x;}
	friend bool operator!=(const mint &a, const mint &b){return a.x != b.x;}
	friend bool operator>(const mint &a, const mint &b){return a.x > b.x;}
	friend bool operator<(const mint &a, const mint &b){return a.x < b.x;}
	mint& operator+=(const mint &b){x += b.x; if(x >= mod) x -= mod; return *this;}
	mint& operator-=(const mint &b){x -= b.x; if(x < 0) x += mod; return *this;}
	mint& operator*=(const mint &b){x = 1ll * x * b.x % mod; return *this;}
	mint& operator/=(const mint &b){x = 1ll * x * qpow(b, mod - 2).x % mod; return *this;}
	friend istream& operator>>(istream &is, mint &x){int v; is >> v; x = mint(v); return is;}
	friend ostream& operator<<(ostream &os, mint x){os << x.x; return os;}
};
const mint qpow(mint a, int64_t b){
	mint res(1, 1);
	for(; b; a *= a, b /= 2) if(b & 1) res *= a;
	return res;
}
int n, k, tot, sz[114514], vis[25];
mint m, f[114514], g[114514];
map<vector<int>, int> s;
int findf(vector<int> &fa, int x){return x == fa[x] ? x : (fa[x] = findf(fa, fa[x]));}
pair<int, int> e[114514][2];
int dfs(vector<int> now){
	if (s.count(now)) return s[now];
	int res = s[now] = ++tot;
	memset(vis, 0, sizeof(vis));
	For(i, 0, (int)now.size() - 1) vis[now[i]] = 1;
	For(i, 0, (int)now.size() - 1) sz[res] += vis[i];
	now.push_back(k - 1);
	int mn = 0; vector<int> old = now;
	For(i, 1, (int)now.size() - 1) if(now[i] == 0 && !mn) mn = i;
	For(i, 0, (int)now.size() - 1) if(now[i] == 0) now[i] = mn;
	vector<int> nxt;
	For(i, 1, (int)now.size() - 1) nxt.push_back(now[i] - 1);
	e[res][0] = {dfs(nxt), mn == 0};
	now = old;
	For(i, (k + 1) / 2, k - 1){
		int fx = findf(now, i), fy = findf(now, k - i - 1);
		if(fx > fy) now[fx] = fy; else now[fy] = fx;
	}
	mn = 0;
	For(i, 0, k - 1){
		now[i] = findf(now, i);
		if(now[i] == 0 && !mn) mn = i;
	}
	int cnt = 0;
	For(i, 1, k - 1) if(now[i] == 0) now[i] = mn, cnt++;
	nxt.clear();
	For(i, 1, k - 1) nxt.push_back(now[i] - 1);
	e[res][1] = {dfs(nxt), mn == 0};
	return res;
}
void Solve(){
	cin >> m >> n >> k;
	if(n < k) return cout << qpow(m, n) << '\n', void();
	vector<int> beg(k - 1);
	iota(beg.begin(), beg.end(), 0);
	f[dfs(beg)] = 1;
	cerr<<tot<<endl;
	For(i, k, n){
		memset(g, 0, sizeof(g));
		For(j, 1, tot){
			g[e[j][0].first] += f[j] * (e[j][0].second ? m : 1);
			g[e[j][1].first] -= f[j];
		}
		memcpy(f, g, sizeof(g));
	}
	mint res = 0;
	For(i, 1, tot) res += f[i] * qpow(m, sz[i]);
	cout << res << "\n";
}
signed main(){
	if(freopen("a0.in","r",stdin));
	cin.tie(0)->sync_with_stdio(0); 
	int T = 1; //cin >> T;
	while(T--) Solve();
	return 0;
}