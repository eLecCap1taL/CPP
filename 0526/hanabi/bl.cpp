#include <bits/stdc++.h>
#define fi first
#define se second 
#define foru(a,b,c) for(int a=(b);a<=(c);a++)
#define All(x) x.begin(),x.end()
#define LL long long
#define u64 unsigned long long
#define u32 unsigned
#define RIN read()
#define LXF int
#define MAXN 1000005
using namespace std;
LXF read(){
    LXF ret=0;
    int w=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')  w=-1;
        c=getchar();
    }
    while(isdigit(c)){
        ret=ret*10+(c^48);
        c=getchar();
    }
    return ret*w;
}
template<typename T>
vector<T>& operator += (vector<T>& ls,const T& x){
    ls.push_back(x);
    return ls;
}
template<typename T1,typename T2>
bool chkmax(T1& x,const T2& y){
    return y>x?x=y,true:false;
}
template<typename T1,typename T2>
bool chkmin(T1& x,const T2& y){
    return y<x?x=y,true:false;
}
int n,m;
int fa[MAXN];
vector<int> e[MAXN];

int sz[MAXN],son[MAXN],id[MAXN],DFN,dep[MAXN],top[MAXN];
void dfs1(int u){
    sz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for(auto v:e[u]){
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])    son[u]=v;
    }
}
void dfs2(int u,int topf){
    top[u]=topf;
    id[u]=++DFN;
    if(!son[u]) return ;
    dfs2(son[u],topf);
    for(auto v:e[u]){
        if(v==son[u])   continue;
        dfs2(v,v);
    }
}

void fpath(int u,function<void(int,int)> callback){
    while(u){
        callback(id[top[u]],id[u]);
        u=fa[top[u]];
    }
}

class DS{
    pair<int,int> d[MAXN];
public:
    void init(){
        foru(i,1,n){
            d[i]={0,0};
        }
    }
    void apply(int l,int r,int x,int y){
        foru(i,l,r){
            if(d[i].fi!=x)  d[i]={x,y};
        }
    }
    pair<int,int> ask(int x){
        return d[x];
    }
}ds;

int main(){
    #ifndef ONLINE_JUDGE
    if(freopen("ex_hanabi0.in","r",stdin));
    // if(freopen("sample.out","w",stdout));
    #endif

    n=RIN,m=RIN;
    foru(i,2,n){
        fa[i]=RIN;
        e[fa[i]]+=i;
    }

    dfs1(1);
    dfs2(1,1);
    
    ds.init();

    foru(o,1,m){
        int opt=RIN;
        if(opt==1){
            int x=RIN,c=RIN;
            fpath(x,[&](int l,int r)->void{
                ds.apply(l,r,c,o);
            });
        }else{
            int x=RIN;
            auto res=ds.ask(id[x]);
            printf("%d %d\n",res.fi,res.se);
        }
    }


    return 0;
}