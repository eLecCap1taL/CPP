#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 405;
const int M = 160005;

int n, m, f[M], p[M], vis[M], match[M], a[N][N], c[N][N], id[N][N], num[2];
char S[805], s[805][805];

vector < pair <int, int> > E, ans;

namespace Flow
{
int s, t, tot = 1, ans, dis[M], cur[M], head[M];

struct Edge
{
    int to, nex, val;
};
Edge e[M << 3];

void add(int u, int v, int w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
    e[++ tot] = {u, head[v], 0};
    head[v] = tot;
}

bool bfs()
{
    queue <int> q;
    memset(dis, -1, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    q.push(s);
    dis[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u], v; i; i = e[i].nex)
            if(e[i].val && dis[v = e[i].to] == -1)
                dis[v] = dis[u] + 1, q.push(v);
    }
    return dis[t] != -1;
}

int dfs(int u, int flow)
{
    if(u == t)
        return flow;
    int val = flow;
    for(int i = cur[u], v, w, c; i && val; i = e[i].nex)
    {
        cur[u] = i;
        if((w = e[i].val) && dis[v = e[i].to] == dis[u] + 1)
            val -= (c = dfs(v, min(val, w))), e[i].val -= c, e[i ^ 1].val += c;
    }
    return flow - val;
}

int Dinic()
{
    while(bfs()){
        cerr<<ans<<endl;
        ans += dfs(s, 1e9);
        cerr<<ans<<endl;
    }
        
    return ans;
}

void build()
{
    for(int i = 1; i <= n * m; ++ i)
    {
        if(c[(i - 1) / m + 1][i % m == 0 ? m : i % m] == 0)
            for(int j = head[i]; j; j = e[j].nex)
                if(!e[j].val && e[j].to != s)
                    p[i] = e[j].to, match[e[j].to] = 1;
    } 
}
}

vector <int> e[M];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void add(int u, int v)
{
    if(find(u) == find(v))
        return;
    f[find(u)] = find(v);
    ans.push_back({u, v});
}

void dfs(int u)
{
    vis[u] = 1;
    for(int v : e[u])
    {
        if(vis[v])
            continue;
        vis[v] = 1;
        add(u, v), add(v, p[v]), dfs(p[v]);
    }
}

int main()
{
    freopen("castle4.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            id[i][j] = (i - 1) * m + j, c[i][j] = i + j & 1;
    for(int i = 1; i <= n + n + 1; ++ i)
    {
        for(int j = 1; j <= m + m + 1; ++ j)
            s[i][j] = '#';
        scanf("%s", S + 1);
        if(i == 1 || i == n + n + 1)
            continue;
        if(i & 1)
        {
            for(int j = 2; j <= m + m + 1; j += 2)
                if(S[j] == '.')
                    E.push_back({id[i - 1 >> 1][j >> 1], id[i + 1 >> 1][j >> 1]});
        }
        else
        {
            for(int j = 1; j <= m + m + 1; j += 2)
                if(S[j] == '.')
                    E.push_back({id[i >> 1][j - 1 >> 1], id[i >> 1][j + 1 >> 1]});
            for(int j = 2; j <= m + m + 1; j += 2)
                if(S[j] == '.')
                    a[i >> 1][j >> 1] = 1, ++ num[c[i >> 1][j >> 1]];
        }
    }

    if(num[0] == num[1])
        return printf("No\n"), 0;
    if(num[0] > num[1])
    {
        swap(num[0], num[1]);
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                c[i][j] ^= 1;
    }

    int ct=0;
    Flow::s = n * m + 1, Flow::t = Flow::s + 1;
    for(auto &[u, v] : E)
    {
        if(c[(u - 1) / m + 1][u % m == 0 ? m : u % m] == 1)
            swap(u, v);
        Flow::add(u, v, 1),ct++;
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            c[i][j] ? (Flow::add(id[i][j], Flow::t, 1),ct++) : (Flow::add(Flow::s, id[i][j], 1),ct++);

    if(Flow::Dinic() != num[0])
        return printf("No\n"), 0;
    cerr<<Flow::Dinic()<<' '<<ct<<endl;
    cerr<<400*400*4+400*400<<endl;
    exit(0);

    Flow::build();
    for(int i = 1; i <= n * m; ++ i)
        f[i] = i;
    for(auto [u, v] : E)
        e[u].push_back(v), e[v].push_back(u);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] && c[i][j] && !match[id[i][j]])
                dfs(id[i][j]);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] && c[i][j] == 0 && !vis[id[i][j]])
                return printf("No\n"), 0;

    for(auto [u, v] : E)
        add(u, v);

    for(auto [u, v] : ans)
    {
        int xu = (u - 1) / m + 1, yu = u % m == 0 ? m : u % m;
        int xv = (v - 1) / m + 1, yv = v % m == 0 ? m : v % m;
        if(xu == xv)
            s[xu << 1][min(yu, yv) << 1 | 1] = '.';
        else
            s[min(xu, xv) << 1 | 1][yu << 1] = '.';
    }

    printf("Yes\n");
    for(int i = 1; i <= n + n + 1; ++ i)
    {
        if(i == 1 || i == n + n + 1)
        {
            for(int j = 1; j <= m + m + 1; ++ j)
                printf("#");
        }
        else if(i & 1)
        {
            for(int j = 1; j <= m + m + 1; ++ j)
                if(j & 1)
                    printf("#");
                else
                    printf("%c", s[i][j]);
        }
        else
        {
            for(int j = 1; j <= m + m + 1; ++ j)
                if(j & 1)
                    printf("%c", s[i][j]);
                else
                    printf("%c", a[i >> 1][j >> 1] ? '.' : '#');
        }
        printf("\n");
    }

    return 0;
}