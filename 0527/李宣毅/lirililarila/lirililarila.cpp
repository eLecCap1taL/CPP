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
#define MAXN 200005
#define mkp(x,y) make_pair(x,y)
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
int n;
int fa[MAXN];
vector<int> e[MAXN];

int dep[MAXN];
int dfn[MAXN],DFN;
int sz[MAXN];
void pre(int u){
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    dfn[u]=++DFN;
    for(auto v:e[u]){
        pre(v);
        sz[u]+=sz[v];
    }
}

class BIT{
public:
    int c[MAXN];
    inline int lb(int x){return x&(-x);}
    void add(int x,int k){
        for(;x<=n;x+=lb(x)) c[x]+=k;
    }
    int qry(int x){
        int ret=0;
        for(;x;x-=lb(x))    ret+=c[x];
        return ret;
    }
    int qry(int l,int r){
        if(l==1)    return qry(r);
        return qry(r)-qry(l-1);
    }
}ds;

namespace Requirements{
    vector<vector<int>> ls;
    vector<int> req[MAXN];
    
    unordered_map<int,int> ban[MAXN];
    unordered_map<int,int> bel[MAXN];
    vector<int> depls[MAXN];

    int depbl[MAXN];

    void dfs(int u){
        // cout<<"vis "<<u<<endl;
        if(depbl[dep[u]]!=0){
            // cout<<u<<' '<<depbl[u]<<endl;
            int master=depbl[dep[u]];
            auto it=bel[dep[u]].find(master);
            int N;
            if(it==bel[dep[u]].end()){
                N=ls.size();
                ls+=vector<int>();
                bel[dep[u]][master]=N;
            }else{
                N=it->se;
            }
            ls[N]+=u;
        }
        for(auto d:req[u]){
            if(ban[d][u])   continue;
            assert(depbl[d]==0);
            depbl[d]=u;
        }
        for(auto v:e[u]){
            dfs(v);
        }
        for(auto d:req[u]){
            if(ban[d][u])   continue;
            assert(depbl[d]==u);
            depbl[d]=0;
        }
    }

    void work(){
        int m=RIN;
        foru(i,1,m){
            int u=RIN,k=RIN;
            assert(k>0);
            req[u]+=dep[u]+k;
            depls[dep[u]+k]+=u;
        }
        foru(i,1,n){
            auto& LS=depls[i];
            sort(All(LS));
            LS.erase(unique(All(LS)),LS.end());
        }
        foru(i,1,n){
            auto& LS=req[i];
            sort(All(LS));
            LS.erase(unique(All(LS)),LS.end());
        }
        foru(i,1,n){
            auto& LS=depls[i];
            for(auto u:LS){
                auto res=ds.qry(dfn[u],dfn[u]+sz[u]-1);
                assert(res==0);
            }
            for(auto u:LS){
                ds.add(dfn[u],1);
            }
            for(auto u:LS){
                // cout<<u<<' '<<dfn[u]<<' '<<dfn[u]+sz[u]-1<<endl;
                auto res=ds.qry(dfn[u],dfn[u]+sz[u]-1);
                if(res!=1){
                    ban[i][u]=1;
                    // cerr<<"ban "<<u<<' '<<i<<' '<<res<<endl;
                }else{
                    ban[i][u]=0;
                    // cerr<<"PASS "<<u<<' '<<i<<endl;
                }
            }
            for(auto u:LS){
                ds.add(dfn[u],-1);
            }
        }
        dfs(1);
    }
}

using Requirements::ls;

void process(){
    //sort
    for(auto& LS:ls){
        sort(All(LS));
    }

    //mark
    static int bl[MAXN];
    foru(i,1,n){
        bl[i]=-1;
    }
    for(size_t i=0;i<ls.size();i++){
        for(auto u:ls[i]){
            bl[u]=i;
        }
        ls[i]+=INT_MAX;
    }

    int ans=INT_MAX;
    int L=-1,R=-1;

    //scan
    static set<int> st;
    for(auto& LS:ls){
        st.insert(LS[0]);
    }
    foru(i,1,n){
        // cout<<bl[i]<<endl;continue;
        if(bl[i]!=-1){
            int r=*st.rbegin();
            if(r==INT_MAX)  break;
            if(chkmin(ans,r-i+1)){
                L=i,R=r;
            }
            auto& LS=ls[bl[i]];
            int cur=i;
            int nxt=*upper_bound(All(LS),i);
            st.erase(cur);
            st.insert(nxt);
        }
    }
    cout<<L<<" "<<R;
}

int main(){
    #ifndef ONLINE_JUDGE
    // if(freopen("sample6.in","r",stdin));
    if(freopen("lirililarila.in","r",stdin));
    if(freopen("lirililarila.out","w",stdout));
    #endif

    n=RIN;
    foru(i,2,n){
        fa[i]=RIN;
        e[fa[i]]+=i;
    }

    pre(1);

    Requirements::work();

    process();
    
    return 0;
}