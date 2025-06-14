#include<bits/stdc++.h>
using namespace std;
#define ll int
#define inf INT_MAX
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w=1; n=0; char ch=getchar();
    while (!isdigit(ch) && ch!=EOF){ if (ch=='-') w=-1; ch=getchar(); }
    while (isdigit(ch) && ch!=EOF){ n=(n<<3)+(n<<1)+(ch&15); ch=getchar(); }
    n*=w;
}
template<typename T>inline void write(T x){
    if (x==0){ putchar('0'); return ; }
    T tmp;
    if (x>0) tmp=x;
    else tmp=-x;
    if (x<0) putchar('-');
    char F[105];
    long long cnt=0;
    while (tmp){
        F[++cnt]=tmp%10+48;
        tmp/=10;
    }
    while (cnt) putchar(F[cnt--]);
}
#define Min(x,y) x = min(x,y)
#define Max(x,y) x = max(x,y)
//基础配置=================================================================================
const ll N = 405;
ll n,m;
ll c[N][N];
bool e1[N][N], e2[N][N];
bool f1[N][N], f2[N][N];
ll id[N][N];
void init(){
    ll i,j;
    ll d[N][N]; memset(d,0,sizeof(d));
    fr(i,1,n) fr(j,1,m){
        if (e1[i][j]) d[i][j]++, d[i+1][j]++;
        if (e2[i][j]) d[i][j]++, d[i][j+1]++;
    }
    ll col = 0, s0 = 0, s1 = 0;
    fr(i,1,n) fr(j,1,m){
        if (c[i][j]==0) s0++;
        if (c[i][j]==1) s1++;
        // printf("%lld ",c[i][j]);
    }
    fr(i,1,n) fr(j,1,m)
        if (d[i][j]==1) col |= 1<<c[i][j];
    // printf("s0 = %lld , s1 = %lld\n",s0,s1);
    if (s0==s1){ printf("No\n"); exit(0); }
    if (col==1 && s1>=s0){ printf("No\n"); exit(0); }
    if (col==2 && s0>=s1){ printf("No\n"); exit(0); }
    if (col==3){ printf("No\n"); exit(0); }
    if (s1<s0) col = 0; else col = 1;
    fr(i,1,n) fr(j,1,m)
        if (c[i][j]!=-1) c[i][j] = c[i][j]==col;
}
void print(){
    ll i,j;
    printf("Yes\n");
    fr(i,1,n+n+1){
        fr(j,1,m+m+1){
            if (i&1){
                if (j&1) putchar('#');
                else{
                    if (f1[i/2][j/2]) putchar('.');
                    else putchar('#');
                }
            }
            else {
                if (j&1){
                    if (f2[i/2][j/2]) putchar('.');
                    else putchar('#');
                }
                else{
                    if (c[i/2][j/2]>=0) putchar('.');
                    else putchar('#');
                }
            }
        }
        putchar('\n');
    }
}
struct MAX_FLOW{
    #define N 160005
    #define M 500005
    struct edge{
        ll x,y,w;
    };
    ll n;
    ll cnt=1,head[N];
    edge e[2*M];
    void init(ll _n){
        n = _n;
        cnt = 1;
        for (ll i=0; i<=n+1; i++) head[i] = 0;
    }
    void Addedge(ll x,ll y,ll w){
        cnt++;
        e[cnt].x = head[x];
        e[cnt].y = y;
        e[cnt].w = w;
        head[x] = cnt;
    }
    void addedge(ll x,ll y,ll w){
        Addedge(x,y,w);
        Addedge(y,x,0);
    }
    ll S,T;
    ll dep[N];
    bool bfs(ll x){
        ll i;
        fr(i,0,n) dep[i] = inf;
        dep[x] = 0;
        queue<ll> q;
        q.push(x);
        while (!q.empty()){
            x = q.front(); q.pop();
            for (i=head[x]; i; i=e[i].x){
                ll go = e[i].y;
                if (e[i].w>0 && dep[x]+1<dep[go]){
                    dep[go] = dep[x]+1;
                    if (go==T) return true;
                    q.push(go);
                }
            }
        }
        return false;
    }
    ll nw[N];
    ll dfs(ll x,ll flow){
        if (x==T) return flow;
        ll i; ll go,k,ans=0;
        for (i=nw[x]; i; i=e[i].x){
            go = e[i].y; nw[x] = i;
            if (e[i].w==0 || dep[x]+1!=dep[go]) continue;
            k = dfs(go,min(flow-ans,e[i].w));
            e[i].w -= k; e[i^1].w += k;
            ans += k;
            if(flow==ans) break;
        }
        return ans;
    }
    ll dinic(ll _S,ll _T){
        S = _S; T = _T;
        ll ans = 0;
        while (bfs(S)){
            for (ll i=0; i<=n; i++) nw[i] = head[i];
            ans += dfs(S,inf);
        }
        return ans;
    }
    ll fd[N];
    void src(ll x,ll fa,ll ffa){
        if (fd[x]) return ;
        // printf("src %lld , fa = %lld , ffa = %lld\n",x,fa,ffa);
        fd[x] = ffa;
        for (ll i=head[x]; i; i=e[i].x)
            if (!e[i].w){
                // printf("%lld --> %lld\n",x,e[i].y);
                src(e[i].y,x,fa);
            }
    }
    #undef N
    #undef M
}flow;
ll To[N*N][2];
bool chk(ll x,ll y){ return To[x][0]==y || To[x][1]==y; }
struct Union_Find{
    ll n, fa[N*N];
    void init(ll _n){
        ll i;
        n = _n;
        fr(i,0,n+1) fa[i] = i;
    }
    ll find(ll x){
        if (fa[x]==x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(ll x,ll y){
        // printf("merge %lld %lld\n",x,y);
        x = find(x), y = find(y);
        if (x==y){
            assert(0);
            return false;
        }
        fa[x] = y;
        return true;
    }
};
int main(){
	// freopen("a.in","r",stdin);
	freopen("castle4.in","r",stdin);
	freopen("castle.out","w",stdout);
    ll i,j;
    read(n), read(m);
    fr(i,1,n) fr(j,1,m) c[i][j] = -1;
    ll cnt = 0, s1 = 0;
    fr(i,1,2*n+1){
        char ch[N+N];
        scanf("%s",ch+1);
        fr(j,1,2*m+1) if (ch[j]=='.'){
            if (i&1){
                if (j&1);
                else e1[i/2][j/2] = true;
            }
            else {
                if (j&1) e2[i/2][j/2] = true;
                else c[i/2][j/2] = (i/2+j/2)&1;
            }
        }
    }
    init();
    fr(i,1,n) fr(j,1,m) if (c[i][j]==0) id[i][j] = ++cnt, s1++;
    fr(i,1,n) fr(j,1,m) if (c[i][j]==1) id[i][j] = ++cnt;
    cerr<<s1<<' '<<cnt<<endl;
    ll S = ++cnt, T = ++cnt;
    flow.init(cnt);
    int ct=0;
    map<int,int> mp;
    fr(i,1,n) fr(j,1,m) if (id[i][j] && c[i][j]==0){
        int oct=ct;
        if (e1[i-1][j] && id[i-1][j]) flow.addedge(id[i][j],id[i-1][j],1),ct++;
        if (e1[i][j]   && id[i+1][j]) flow.addedge(id[i][j],id[i+1][j],1),ct++;
        if (e2[i][j-1] && id[i][j-1]) flow.addedge(id[i][j],id[i][j-1],1),ct++;
        if (e2[i][j]   && id[i][j+1]) flow.addedge(id[i][j],id[i][j+1],1),ct++;
        // cerr<<ct-oct<<endl;
        mp[ct-oct]++;
    }
    for(auto [X,Y]:mp){
        cerr<<X<<' '<<Y<<endl;
    }
    fr(i,1,n) fr(j,1,m){
        if (c[i][j]==0) flow.addedge(S,id[i][j],1),ct++;
        if (c[i][j]==1) flow.addedge(id[i][j],T,1),ct++;
    }
    cerr<<ct<<endl;
    cerr<<flow.dinic(S,T);
    exit(1);
    // printf("all = %lld\n",flow.dinic(S,T));
    flow.src(T,-1,-1);
    fr(i,s1+1,cnt-2){
        // printf("%lld : fd = %lld\n",i,flow.fd[i]);
        if (!flow.fd[i]){ printf("No\n"); return 0; }
    }
    fr(i,1,s1){
        for (j=flow.head[i]; j; j=flow.e[j].x){
            if (!flow.e[j].w){
                To[i][0] = flow.e[j].y, To[i][1] = flow.fd[flow.e[j].y];
                break;
            }
        }
    }
    Union_Find uf;
    uf.init(cnt);
    fr(i,1,n) fr(j,1,m) if (0<id[i][j] && id[i][j]<=s1){
        ll p = id[i][j];
        if (id[i+1][j] && chk(p,id[i+1][j])){
            f1[i][j] = true;
            // assert(uf.merge(p,id[i+1][j]));
            uf.merge(p,id[i+1][j]);
        }
        if (id[i-1][j] && chk(p,id[i-1][j])){
            f1[i-1][j] = true;
            // assert(uf.merge(p,id[i-1][j]));
            uf.merge(p,id[i-1][j]);
        }
        if (id[i][j+1] && chk(p,id[i][j+1])){
            f2[i][j] = true;
            // assert(uf.merge(p,id[i][j+1]));
            uf.merge(p,id[i][j+1]);
        }
        if (id[i][j-1] && chk(p,id[i][j-1])){
            f2[i][j-1] = true;
            // assert(uf.merge(p,id[i][j-1]));
            uf.merge(p,id[i][j-1]);
        }
    }
    fr(i,1,n) fr(j,1,m) if (id[i][j]){
        ll p = id[i][j];
        if (e1[i][j] && id[i+1][j] && uf.find(p)!=uf.find(id[i+1][j]))
            f1[i][j] = true, uf.merge(p,id[i+1][j]);
        if (e1[i-1][j] && id[i-1][j] && uf.find(p)!=uf.find(id[i-1][j]))
            f1[i-1][j] = true, uf.merge(p,id[i-1][j]);
        if (e2[i][j] && id[i][j+1] && uf.find(p)!=uf.find(id[i][j+1]))
            f2[i][j] = true, uf.merge(p,id[i][j+1]);
        if (e2[i][j-1] && id[i][j-1] && uf.find(p)!=uf.find(id[i][j-1]))
            f2[i][j-1] = true, uf.merge(p,id[i][j-1]);
    }
    ll rt = uf.find(1);
    fr(i,1,cnt-2) assert(uf.find(i)==rt);
    fr(i,1,n) fr(j,1,m) if (c[i][j]==0){
        ll s = f1[i][j] + f1[i-1][j] + f2[i][j] + f2[i][j-1];
        assert(s>=2);
    }
    print();
    return 0;
}
//g++ a.cpp -o a -Wall -Wl,--stack=512000000 -std=c++11 -O2