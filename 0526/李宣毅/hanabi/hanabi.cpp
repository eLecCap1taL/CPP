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
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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

int sz[MAXN],son[MAXN],id[MAXN],DFN,dep[MAXN],top[MAXN],len[MAXN];
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
    len[id[top[u]]]++;
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

class Node{
    public:
    int l,r;
    pair<int,int> v;
    bool force;
}TR[MAXN<<2];
class DS{
    static void opt(pair<int,int>& x,pair<int,int> y){
        if(x.fi!=y.fi)  x=y;
    }
    Node* tr;
    inline static int lc(int x){return x<<1;}
    inline static int rc(int x){return x<<1|1;}
    void upd(int p,pair<int,int> tg,bool force){
        if(force){
            tr[p].v=tg;
            tr[p].force=1;
            return ;
        }
        if(tr[p].v.fi!=tg.fi){
            tr[p].force=tr[p].v.fi!=0;
            tr[p].v=tg;
        }
    }
    void push_down(int p){
        if(tr[p].v.fi==0)   return ;
        upd(lc(p),tr[p].v,tr[p].force);
        upd(rc(p),tr[p].v,tr[p].force);
        tr[p].v={0,0};
        tr[p].force=0;
    }
    void build(int p,int l,int r){
        tr[p].l=l,tr[p].r=r;
        if(l==r)    return ;
        int mid=(l+r)>>1;
        build(lc(p),l,mid);
        build(rc(p),mid+1,r);
    }
    void modify(int p,int l,int r,pair<int,int> tg){
        // cerr<<"mod vis "<<tr[p].l<<" "<<tr[p].r<<endl;
        if(l<=tr[p].l && tr[p].r<=r){
            upd(p,tg,false);
            return ;
        }
        push_down(p);
        int mid=(tr[p].l+tr[p].r)>>1;
        if(l<=mid)  modify(lc(p),l,r,tg);
        if(r>mid)   modify(rc(p),l,r,tg);
    }
    pair<int,int> query(int p,int pos){
        if(tr[p].l==tr[p].r)    return tr[p].v;
        push_down(p);
        int mid=(tr[p].l+tr[p].r)>>1;
        if(pos<=mid)    return query(lc(p),pos);
        else    return query(rc(p),pos);
    }
    // pair<int,int> d[MAXN];
public:
    bool inited;
    void init(int l,int L){
        tr=TR+(l-1)*4;
        build(1,1,L);
        inited=1;
        // foru(i,1,n){
        //     d[i]={0,0};
        // }
    }
    void apply(int l,int r,int x,int y){
        modify(1,l,r,{x,y});
        // foru(i,l,r){
        //     if(d[i].fi!=x)  d[i]={x,y};
        // }
    }
    pair<int,int> ask(int x){
        return query(1,x);
        // return d[x];
    }
}ds[MAXN];

void out(int x){
	if(x==0)	putchar('0');
	else if(x<10)	putchar((char)('a'+x));
	else{
		out(x/10);
		putchar((char)('a'+x%10));
	}
}

int main(){
    #ifndef ONLINE_JUDGE
    if(freopen("hanabi.in","r",stdin));
    // if(freopen("a.in","r",stdin));
    // if(freopen("ex_binding1.in","r",stdin));
    if(freopen("hanabi.out","w",stdout));
    #endif

    n=RIN,m=RIN;
    foru(i,2,n){
        fa[i]=RIN;
        e[fa[i]]+=i;
    }

    dfs1(1);
    dfs2(1,1);

    foru(o,1,m){
        int opt=RIN;
        if(opt==1){
            int x=RIN,c=RIN;
            // cerr<<o<<endl;
            fpath(x,[&](int l,int r)->void{
                // cerr<<"work with "<<l<<' '<<r<<endl;
                if(!ds[l].inited)   ds[l].init(l,len[l]);
                ds[l].apply(1,r-l+1,c,o);
            });
        }else{
            int x=RIN;
            int tp=id[top[x]];
            if(!ds[tp].inited){
                printf("0 0\n");
                continue;
            }
            auto res=ds[tp].ask(id[x]-tp+1);
            // out(res.fi);
            // putchar(' ');
            // out(res.se);
           printf("%d %d\n",res.fi,res.se);
        }
    }

//    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;

    return 0;
}