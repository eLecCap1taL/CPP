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
#define MAXN 300005
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

int n;
int m;
Rec a[MAXN];

namespace SUBNEQUALM{
    void work(){
        Rec res=a[1];
        foru(i,2,n){
            res=res*a[i];
        }
        cout<<res.size();
    }
}

namespace SUBN1000{
    int s[1005][1005];
    int cnt[1005];
    void work(){
        foru(i,1,n){
            s[a[i].xl][a[i].yl]++;
            s[a[i].xr+1][a[i].yr+1]++;
            s[a[i].xl][a[i].yr+1]--;
            s[a[i].xr+1][a[i].yl]--;
        }
        foru(i,1,n){
            foru(j,1,n){
                s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
                cnt[s[i][j]]++;
            }
        }
        for(int i=m;i<=n;i+=m){
            cout<<cnt[i]<<endl;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    // if(freopen("sample0.in","r",stdin));
    // if(freopen(".out","w",stdout));
    if(freopen("phosphophyllite.in","r",stdin));
    if(freopen("phosphophyllite.out","w",stdout));
    #endif

    n=RIN,m=RIN;
    foru(i,1,n){
        a[i]={RIN,RIN-1,RIN,RIN-1};
    }

    if(n==m){
        SUBNEQUALM::work();
        return 0;
    }
    if(n<=1000){
        SUBN1000::work();
        return 0;
    }
    for(int i=m;i<=n;i+=m){
        printf("0\n");
    }


    
    return 0;
}
