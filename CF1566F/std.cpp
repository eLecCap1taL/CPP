// 2021.10.19 - 10:38
// Code by LTb
// 午前六時、脇役は最初のページを。

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define debug printf("Passing Line %d in function [%s].\n",__LINE__,__FUNCTION__)
#define fi first
#define se second
inline int read(){
    int x=0,f=1;
    char ch='.';
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
inline void chmax(int &x,int y){x=max(x,y);}
inline void chmin(int &x,int y){x=min(x,y);}

const int MOD = 998244353;
inline int add(int x,int y){return(x+y>=MOD)?(x+y-MOD):((x+y<0)?(x+y+MOD):(x+y));}

const int MAXN = 200005;
const int INF = 1e16;
int n, m, mm;
int a[MAXN];
pair<int,int> seg[MAXN];
bool vis[MAXN];
int tot = 0, ans = 0;

bool cmp(pair<int,int> x, pair<int,int> y) {
	if (x.se == y.se) return x.fi > y.fi;
	return x.se < y.se;
}

void readin() {
	n = read(), m = read();
	mm = m;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n);

	tot = 0;
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		int pos = lower_bound(a + 1, a + 1 + n, x) - a;
		// cout << "qaq: " << i << ' ' << pos << endl;
		if (pos == n + 1 || a[pos] > y) {
			tot++;
			seg[tot].fi = x, seg[tot].se = y;
		}
	}
}

void preparing() {
	m = tot;
	sort(seg + 1, seg + 1 + m, cmp);

	set<int> s;
	for (int i = 1; i <= m; i++) {
		if (seg[i] == seg[i - 1]) continue;
		if (s.lower_bound(seg[i].fi) == s.end()) {
			s.insert(seg[i].fi);
			vis[i] = true;
		}
	}

	tot = 0;
	for (int i = 1; i <= m; i++)
		if (vis[i]) seg[++tot] = seg[i];

	m = tot;
	sort(seg + 1, seg + 1 + m);
	/*for (int i = 1; i <= m; i++)
		cout << "QWQ: " << seg[i].fi << ' ' << seg[i].se << endl;*/
}

int le[MAXN], ri[MAXN];
int len[MAXN]; // 每个点后线段个数
vector<int> dis_pre[MAXN], dis_suf[MAXN];
void preparing2() {
	int pos = 0;

	for (int i = 1; i <= n; i++) {
		while (pos < m && seg[pos + 1].se < a[i]) pos++;
		le[i] = pos, ri[i] = pos + 1;
		if (ri[i] > m) ri[i] = 0;
	}

	if (le[1] != 0) ri[0] = 1;
	if (ri[n] != 0) le[n + 1] = m;

	for (int i = 1; i <= n + 1; i++)
		len[i - 1] = max(0ll, le[i] - ri[i - 1] + 1);
	if (le[1] == 0) len[0] = 0;
	if (ri[n] == 0) len[n] = 0;

	// debug;
	// cout << ri[n] << endl;
	dis_pre[0].resize(2), dis_suf[0].resize(2);
	for (int i = 1; i <= n; i++) {
		dis_pre[i].resize(len[i - 1] + 3);
		dis_pre[i][0] = 0;
		for (int j = 1; j <= len[i - 1]; j++) {
			int x = le[i] - j + 1;
			dis_pre[i][j] = a[i] - seg[x].se;
			// if (dis_pre[i][j] < 0) debug;
			chmax(dis_pre[i][j], 0ll);
			// cout << "pre: " << i << ' ' << j << ' ' << dis_pre[i][j] << endl;
		}

		dis_suf[i].resize(len[i] + 3);
		dis_suf[i][0] = 0;
		for (int j = 1; j <= len[i]; j++) {
			int x = ri[i] + j - 1;
			dis_suf[i][j] = seg[x].fi - a[i];
			// if (dis_suf[i][j] < 0) debug;
			chmax(dis_suf[i][j], 0ll);
			// cout << "suf: " << i << ' ' << j << ' ' << dis_suf[i][j] << endl;
		}
	}
}

vector<int> dp[MAXN];
int ssuf[MAXN], spre[MAXN], d[MAXN];
void solve() {
	if (m == 0) {
		ans = 0;
		return;
	}

	dp[0].resize(len[0] + 3);
	for (int i = 1; i <= len[0]; i++)
		dp[0][i] = INF;

	for (int i = 0; i <= len[0]; i++)
		d[i] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i].resize(len[i] + 3);
		for (int j = 0; j <= len[i - 1]; j++) {
			d[j] = dis_pre[i][j];
			// cout << "Q" << d[j] << ' ';
		}
		// cout << endl;

		ssuf[len[i - 1] + 1] = INF;
		spre[0] = dp[i - 1][0] + dis_pre[i][len[i - 1]];
		for (int j = 1; j <= len[i - 1]; j++)
			spre[j] = min(spre[j - 1], dp[i - 1][j] + dis_pre[i][len[i - 1] - j]);

		for (int j = len[i - 1]; j >= 0; j--)
			ssuf[j] = min(ssuf[j + 1], dp[i - 1][j] + 2 * dis_pre[i][len[i - 1] - j]);
		
		/*cout << "syxqwq: ";
		for (int j = 0; j <= len[i - 1]; j++)
			cout << spre[j] << " ";
		cout << endl;*/

		for (int j = 0; j <= len[i]; j++) {
			int x = lower_bound(d, d + 1 + len[i - 1], dis_suf[i][j]) - d;
			dp[i][j] = INF;
			if (x <= len[i - 1]) chmin(dp[i][j], spre[len[i - 1] - x] + dis_suf[i][j] * 2);
			if (x > 0) chmin(dp[i][j], ssuf[len[i - 1] - x + 1] + dis_suf[i][j]);
			// cout << "qwq: " << x << ' ' << dis_suf[i][j] << ' ' << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}

	ans = dp[n][len[n]];
}

void clear() {
	for (int i = 0; i <= mm + 2; i++)
		vis[i] = false, seg[i] = {0, 0};

	for (int i = 0; i <= n + 2; i++) {
		dp[i].clear(), dis_pre[i].clear(), dis_suf[i].clear();
		le[i] = ri[i] = len[i] = 0;
	}
	
	for (int i = 0; i <= mm + 2; i++)
		d[i] = ssuf[i] = spre[i] = 0;

	tot = ans = 0;
}

signed main()

{
	int test_case = read();
	while (test_case--) {
		readin();
		preparing();
		preparing2();
		solve();
		cout << ans << endl;
		clear();
	}
	return 0;
}