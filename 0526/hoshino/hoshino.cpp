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
class Rec{
public:
    int xl,xr,yl,yr;
    Rec(int xl=0,int xr=0,int yl=0,int yr=0):xl(xl),xr(xr),yl(yl),yr(yr){}
    Rec operator * (const Rec& x)const{
        return Rec(max(xl,x.xl),min(xr,x.xr),max(yl,x.yl),min(yr,x.yr));
    }
    bool valid()const{
        return xl<=xr && yl<=yr;
    }
    LL size()const{
        if(!valid())    return 0;
        return (LL)(xr-xl+1)*(LL)(yr-yl+1);
    }
};

class Modi : public Rec{
public:
    int v;
}a[MAXN];

class Quer : public Rec{

}b[MAXN];

int n,m;

namespace SUBN100{
    LL s[105][105];
    void work(){
        foru(o,1,n){
            foru(i,a[o].xl,a[o].xr){
                foru(j,a[o].yl,a[o].yr){
                    // cerr<<i<<' '<<j<<endl;
                    // assert(i>=0 && i<105);
                    // assert(j>=0 && j<105);
                    chkmax(s[i][j],a[o].v);
                }
            }
        }
        foru(i,1,n){
            foru(j,1,n){
                s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            }
        }
        // cout<<s[0][2]<<endl;
        foru(i,1,m){
            printf("%lld\n",s[b[i].xr][b[i].yr]-s[b[i].xl-1][b[i].yr]-s[b[i].xr][b[i].yl-1]+s[b[i].xl-1][b[i].yl-1]);
        }
    }
}
namespace SUBWRONG{
    class Node{
    public:
        int mx,mn;
        int tg;
        LL s;
        int ch[4];
    }tr[MAXN*40];
    int pcnt;
    int rt;
    inline void upd(int &p,int v,bool nn=1){
        if(!p){
            if(nn)  p=++pcnt;
            else    return ;
        }
        chkmax(tr[p].mx,v);
        chkmax(tr[p].mn,v);
        chkmax(tr[p].tg,v);
    }
    void push_down(int p,bool nn=1){
        if(!p)  return ;
        if(tr[p].tg==0) return ;
        upd(tr[p].ch[0],tr[p].tg,nn);
        upd(tr[p].ch[1],tr[p].tg,nn);
        upd(tr[p].ch[2],tr[p].tg,nn);
        upd(tr[p].ch[3],tr[p].tg,nn);
        tr[p].tg=0;
    }
    void push_up(int p){
        tr[p].mx=max({tr[tr[p].ch[0]].mx,tr[tr[p].ch[1]].mx,tr[tr[p].ch[2]].mx,tr[tr[p].ch[3]].mx});
        tr[p].mn=min({tr[tr[p].ch[0]].mn,tr[tr[p].ch[1]].mn,tr[tr[p].ch[2]].mn,tr[tr[p].ch[3]].mn});
    }
    void modify(int &p,int xl,int xr,int yl,int yr,int xql,int xqr,int yql,int yqr,int v){
        if(xl>xr)   return ;
        if(yl>yr)   return ;
        if(!p){
            p=++pcnt;
        }
        if(tr[p].mn>=v) return ;
        // if(xl==xr && yl==yr){
        if(xql<=xl && xr<=xqr && yql<=yl && yr<=yqr){
            // cerr<<"Modi "<<xl<<' '<<xr<<' '<<yl<<' '<<yr<<' '<<v<<endl;
            upd(p,v);
            return ;
        }
        push_down(p,false);
        int xmid=(xl+xr)>>1;
        int ymid=(yl+yr)>>1;
        if(xql<=xmid && yql<=ymid){
            modify(tr[p].ch[0],xl,xmid,yl,ymid,xql,xqr,yql,yqr,v);
        }
        if(xql<=xmid && yqr>ymid){
            modify(tr[p].ch[1],xl,xmid,ymid+1,yr,xql,xqr,yql,yqr,v);
        }
        if(xqr>xmid && yql<=ymid){
            modify(tr[p].ch[2],xmid+1,xr,yl,ymid,xql,xqr,yql,yqr,v);
        }
        if(xqr>xmid && yqr>ymid){
            modify(tr[p].ch[3],xmid+1,xr,ymid+1,yr,xql,xqr,yql,yqr,v);
        }
        push_up(p);
    }
    void calc(int p,int xl,int xr,int yl,int yr){
        if(xl>xr)   return ;
        if(yl>yr)   return ;
        if(tr[p].mx==tr[p].mn){
            tr[p].s=(LL)(xr-xl+1)*(LL)(yr-yl+1)*(LL)tr[p].mx;
            return ;
        }
        push_down(p,false);
        int xmid=(xl+xr)>>1;
        int ymid=(yl+yr)>>1;
        if(tr[p].ch[0]){
            calc(tr[p].ch[0],xl,xmid,yl,ymid);
        }
        if(tr[p].ch[1]){
            calc(tr[p].ch[1],xl,xmid,ymid+1,yr);
        }
        if(tr[p].ch[2]){
            calc(tr[p].ch[2],xmid+1,xr,yl,ymid);
        }
        if(tr[p].ch[3]){
            calc(tr[p].ch[3],xmid+1,xr,ymid+1,yr);
        }
        for(int i=0;i<4;i++){
            tr[p].s+=tr[tr[p].ch[i]].s;
        }
    }
    LL query(int p,int xl,int xr,int yl,int yr,int xql,int xqr,int yql,int yqr){
        if(xl>xr)   return 0;
        if(yl>yr)   return 0;
        if(!p)  return 0;
        if(xql<=xl && xr<=xqr && yql<=yl && yr<=yqr){
            return tr[p].s;
        }
        if(tr[p].mx==tr[p].mn){
            return (LL)tr[p].mx*(LL)(min(xr,xqr)-max(xl,xql)+1)*(LL)(min(yr,yqr)-max(yl,yql)+1);
        }
        int xmid=(xl+xr)>>1;
        int ymid=(yl+yr)>>1;
        LL ret=0;
        if(xql<=xmid && yql<=ymid && tr[p].ch[0]){
            ret+=query(tr[p].ch[0],xl,xmid,yl,ymid,xql,xqr,yql,yqr);
        }
        if(xql<=xmid && yqr>ymid && tr[p].ch[1]){
            ret+=query(tr[p].ch[1],xl,xmid,ymid+1,yr,xql,xqr,yql,yqr);
        }
        if(xqr>xmid && yql<=ymid && tr[p].ch[2]){
            ret+=query(tr[p].ch[2],xmid+1,xr,yl,ymid,xql,xqr,yql,yqr);
        }
        if(xqr>xmid && yqr>ymid && tr[p].ch[3]){
            ret+=query(tr[p].ch[3],xmid+1,xr,ymid+1,yr,xql,xqr,yql,yqr);
        }
        return ret;
    }
    void work(){
        foru(i,1,n){
            // cerr<<"opt "<<i<<endl;
            // cerr<<pcnt<<endl;
            modify(rt,1,n,1,n,a[i].xl,a[i].xr,a[i].yl,a[i].yr,a[i].v);
        }
        calc(rt,1,n,1,n);
        foru(i,1,m){
            printf("%lld\n",query(rt,1,n,1,n,b[i].xl,b[i].xr,b[i].yl,b[i].yr));
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    // if(freopen("sample2.in","r",stdin));
    if(freopen("hoshino.in","r",stdin));
    if(freopen("hoshino.out","w",stdout));
    #endif

    n=RIN,m=RIN;
    foru(i,1,n){
        a[i].xl=RIN;
        a[i].xr=RIN;
        a[i].yl=RIN;
        a[i].yr=RIN;
        a[i].v=RIN;
    }
    foru(i,1,m){
        b[i].xl=RIN;
        b[i].xr=RIN;
        b[i].yl=RIN;
        b[i].yr=RIN;
    }

    if(n<=100){
        SUBN100::work();
        return 0;
    }

    SUBWRONG::work();
    return 0;
    
    return 0;
}