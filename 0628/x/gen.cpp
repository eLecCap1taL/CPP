#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

/* =========== Parameter =========== */

const int SEED = chrono::system_clock::now().time_since_epoch().count();

bool multiedge = false;
bool onlyOddCircle = false;

int n = 1000;
int m_limit = -1;  // -1 for not limit

/* =========== Parameter =========== */

void _err(const char* msg, int lineNum) {
    fprintf(stderr, "Error at line #%d: %s\n", lineNum, msg);
    exit(1);
}
#define err(msg) _err(msg, __LINE__)

inline int rand(int l, int r) {
    static mt19937 rnd(SEED);
    if (l > r) err("invalid range");
    return l + rnd() % (r - l + 1);
}

vector<pair<int, int>> edges;
vector<vector<int>> son(n, vector<int>());
vector<int> dpt(n);

int dfs(int u) {
    int res = u;
    for (size_t i = 0; i < son[u].size(); ++i) {
        int v = son[u][i];
		dpt[v] = dpt[u] + 1;
        int t = dfs(v);
        if (rand(0, son[u].size()) == 0)
            res = t;
        else if ((t != v || multiedge)
                && ((dpt[t] - dpt[u] + 1) % 2 == 1 || !onlyOddCircle)
                && (m_limit == -1 || (int)edges.size() < m_limit))
            edges.emplace_back(u, t);
    }
    return res;
}

signed main() {
    freopen("yzh", "w", stdout);
    
    if (n < 1) err("n shouldn't be less than 1");
    if (m_limit != -1 && m_limit < n - 1)
        err("m_limit shouldn't less than n-1");
    
    for (int i = 1; i < n; ++i) {
        int fa = rand(0, i - 1);
        edges.emplace_back(fa, i);
        son[fa].emplace_back(i);
    }
    dfs(0);
    
    for (size_t i = 1; i < edges.size(); ++i)
        swap(edges[i], edges[rand(0, i)]);
    
    printf("%d %d\n", n, (int)edges.size());
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (rand(0, 1)) swap(u, v);
        printf("%d %d\n", u + 1, v + 1);
    }
    
    fprintf(stderr, "Success!\n");
    fprintf(stderr, "n = %d, m = %d\n", n, (int)edges.size());
    fprintf(stderr, "circle = %d\n", (int)edges.size() - (n - 1));
    return 0;
}