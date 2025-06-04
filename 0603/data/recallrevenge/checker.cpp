#include <bits/stdc++.h>
#include "testlib.h"
#define pb emplace_back

using namespace std;

const int maxn = 200100;

int n, m, A, B, S, T, f[maxn], g[maxn];
vector<int> G[maxn];

inline void bfs(int S, int *f) {
	for (int i = 1; i <= n; ++i) {
		f[i] = -1;
	}
	queue<int> q;
	q.push(S);
	f[S] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : G[u]) {
			if (f[v] == -1) {
				f[v] = f[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(int argc, char** argv) {
	registerLemonChecker(argc, argv);
	int t = inf.readInt();
	for (int _ = 1; _ <= t; ++_) {
		setTestCase(_);
		n = inf.readInt();
		m = inf.readInt();
		A = inf.readInt();
		B = inf.readInt();
		for (int i = 1; i <= n; ++i) {
			vector<int>().swap(G[i]);
		}
		S = ouf.readInt(1, n);
		T = ouf.readInt(1, n);
		if (S == T) {
			quitf(_wa, "s is equal to t.");
		}
		while (m--) {
			int u = inf.readInt();
			int v = inf.readInt();
			G[u].pb(v);
			G[v].pb(u);
		}
		bfs(S, f);
		bfs(T, g);
		int x = 0, y = 0;
		for (int i = 1; i <= n; ++i) {
			if (f[i] < g[i]) {
				++x;
			} else if (f[i] > g[i]) {
				++y;
			}
		}
		if (x != A) {
			quitf(_wa, "The number of nodes satisfying dis(s, i) < dis(t, i) is %d, not equal to %d.", x, A);
		}
		if (y != B) {
			quitf(_wa, "The number of nodes satisfying dis(s, i) > dis(t, i) is %d, not equal to %d.", y, B);
		}
	}
	quitf(_ok, "Accepted.");
	return 0;
}
